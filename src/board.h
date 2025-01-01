#pragma once
#include "piece.h"

class Board {
private:
  int _cols;
  int _rows;
  std::vector<std::vector<PieceType>> _blocks;

public:
  // the actual board is (rows, cols) for convenient rows operations.
  // however we will use (cols, rows) interface for consistency with other
  // classes
  Board(int cols, int rows)
      : _cols(cols), _rows(rows),
        _blocks(rows, std::vector<PieceType>(cols, PieceType::NUL)) {}
};
