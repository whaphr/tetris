#pragma once
#include <vector>

enum class PieceType { I, O, T, S, Z, J, L, NUL };

struct Point {
  int x, y;
  Point(int x, int y) : x(x), y(y) {}
  void operator+=(const Point &other) {
    x += other.x;
    y += other.y;
  }
};

class Piece {
private:
  std::vector<Point> _blocks;
  Point _position;
  PieceType _type;

public:
  Piece(PieceType type, Point position);
  void rotate_clockwise();
  void rotate_counterclockwise();
  void move_left();
  void move_right();
  void move_down(int dy = 1);
  const std::vector<Point> &get_blocks() const;
  Point get_position() const;
  PieceType get_type() const;
};
