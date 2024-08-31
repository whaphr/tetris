#include "tetris.h"
#include <SFML/Graphics.hpp>

int main() {
  constexpr int cols = 10;
  constexpr int rows = 20;
  constexpr int square_size = 30;
  constexpr int width = cols * square_size;
  constexpr int height = rows * square_size;

  sf::RenderWindow window(sf::VideoMode(width, height), "Tetris");
  window.setPosition(sf::Vector2i(1000, 20));
  sf::RectangleShape square(sf::Vector2f(square_size, square_size));
  square.setOutlineThickness(1);
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
        square.setFillColor(tetris.GetColorAt(col, row));
        window.draw(square);
      }
    }
    window.display();
  }

  return 0;
}
