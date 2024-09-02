#include "piece.h"
#include <SFML/Graphics.hpp>

constexpr int cols = 50;
constexpr int rows = 20;
constexpr int square_size = 30;
constexpr int width = cols * square_size;
constexpr int height = rows * square_size;

void draw_piece(sf::RenderWindow &window, const Piece &piece) {
  sf::RectangleShape square(sf::Vector2f(square_size, square_size));
  square.setOutlineThickness(-1);
  square.setOutlineColor(sf::Color::Black);

  for (auto point : piece.get_blocks()) {
    point += piece.get_position();
    square.setPosition(point.x * square_size, point.y * square_size);
    square.setFillColor(sf::Color::Red);
    window.draw(square);
  }
}

int main() {
  sf::RenderWindow window(sf::VideoMode(width, height), "Tetris");
  window.setPosition(sf::Vector2i(0, 0));

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed ||
          event.type == sf::Event::KeyPressed)
        window.close();
    }

    window.clear();
    for (auto piece_type :
         {PieceType::I, PieceType::O, PieceType::T, PieceType::S, PieceType::Z,
          PieceType::J, PieceType::L}) {
      Piece piece(piece_type, Point{static_cast<int>(piece_type) * 5, 1});
      for (int i = 0; i < 4; i++) {
        draw_piece(window, piece);
        piece.rotate_counterclockwise();
        piece.move_down(5);
      }
    }
    window.display();
  }

  return 0;
}
