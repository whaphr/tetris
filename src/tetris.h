#include <SFML/Graphics/Color.hpp>
#include <vector>

class Tetris {
private:
  int _cols;
  int _rows;
  std::vector<std::vector<sf::Color>> _board;

public:
  Tetris(int cols, int rows)
      : _cols(cols), _rows(rows),
        _board(rows, std::vector<sf::Color>(cols, sf::Color::Black)) {}

  const std::vector<std::vector<sf::Color>> &get_board() const {
    return _board;
  }
  sf::Color get_color_at(int x, int y) const { return _board[y][x]; }
};
