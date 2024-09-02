#include "piece.h"
#include "tetris.h"
#include <SFML/Graphics.hpp>

int main() {
  constexpr int cols = 50;
  constexpr int rows = 20;
  constexpr int square_size = 30;
  constexpr int width = cols * square_size;
  constexpr int height = rows * square_size;

  sf::RenderWindow window(sf::VideoMode(width, height), "Tetris");
  window.setPosition(sf::Vector2i(0, 0));
  sf::RectangleShape square(sf::Vector2f(square_size, square_size));
  square.setOutlineThickness(-1);
  square.setOutlineColor(sf::Color::Black);
  Tetris tetris(cols, rows);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed ||
          event.type == sf::Event::KeyPressed)
        window.close();
    }

    window.clear();
    for (int row = 0; row < rows; ++row) {
      for (int col = 0; col < cols; ++col) {
        square.setPosition(col * square_size, row * square_size);
        square.setFillColor(tetris.get_color_at(col, row));
        window.draw(square);
      }
    }
    for (auto piece_type :
         {PieceType::I, PieceType::O, PieceType::T, PieceType::S, PieceType::Z,
          PieceType::J, PieceType::L}) {
      Piece piece(piece_type, Point{static_cast<int>(piece_type) * 5, 1});
      for (int i = 0; i < 4; i++) {
        for (auto point : piece.get_blocks()) {
          point += piece.get_position();
          square.setPosition(point.x * square_size, point.y * square_size);
          square.setFillColor(sf::Color::Red);
          window.draw(square);
        }
        piece.rotate_counterclockwise();
        piece.move_down(5);
      }
    }
    window.display();
  }

  return 0;
}
