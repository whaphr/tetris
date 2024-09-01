#include "piece.h"

Piece::Piece(PieceType type, Point position)
    : _type(type), _position(position) {
  switch (_type) {
  case PieceType::I:
    _blocks = {{-1, 0}, {0, 0}, {1, 0}, {2, 0}};
    break;
  case PieceType::O:
    _blocks = {{-1, -1}, {-1, 0}, {0, -1}, {0, 0}};
    break;
  case PieceType::T:
    _blocks = {{-1, 0}, {0, 0}, {1, 0}, {0, 1}};
    break;
  case PieceType::J:
    _blocks = {{-1, 1}, {0, 1}, {0, 0}, {0, -1}};
    break;
  case PieceType::L:
    _blocks = {{1, 1}, {0, 1}, {0, 0}, {0, -1}};
    break;
  case PieceType::S:
    _blocks = {{-1, 0}, {0, 0}, {0, -1}, {1, -1}};
    break;
  case PieceType::Z:
    _blocks = {{1, 0}, {0, 0}, {0, -1}, {-1, -1}};
    break;
  }
}

void Piece::rotate_clockwise() {
  for (auto &block : _blocks) {
    std::swap(block.x, block.y);
    block.x = -block.x;
  }
}

void Piece::rotate_counterclockwise() {
  for (auto &block : _blocks) {
    std::swap(block.x, block.y);
    block.y = -block.y;
  }
}

void Piece::move_left() { _position.x--; }

void Piece::move_right() { _position.x++; }

void Piece::move_down() { _position.y++; }

const std::vector<Point> &Piece::get_blocks() const { return _blocks; }

Point Piece::get_position() const { return _position; }

PieceType Piece::get_type() const { return _type; }
