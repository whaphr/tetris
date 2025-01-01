// I think for this particular class, it's more effective to just draw all
// pieces on the screen rather than doing unit tests

#include "piece.h"
#include <SFML/Graphics.hpp>

constexpr int cols = 35;
constexpr int rows = 21;
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

void draw_pieces(sf::RenderWindow &window) {
  constexpr int space = 5;
  constexpr int screen_offset = 2;
  constexpr int rotations = 4;

  for (int type = 0; type != static_cast<int>(PieceType::NUL); type++) {
    Piece piece(static_cast<PieceType>(type),
                Point{type * space + screen_offset, screen_offset});
    for (int i = 0; i < rotations; i++) {
      draw_piece(window, piece);
      piece.rotate_counterclockwise();
      piece.move_down(space);
    }
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
    draw_pieces(window);
    window.display();
  }

  return 0;
}
