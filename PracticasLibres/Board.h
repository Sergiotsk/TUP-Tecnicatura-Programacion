#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Tetromino.h"

class Board {
public:
    Board(int width, int height);
    bool IsCollision(const Tetromino& piece, int newX, int newY) const;
    void LockPiece(const Tetromino& piece);
    void ClearLines();
    void Draw(const Tetromino& currentPiece) const;
    int GetWidth() const;
    int GetHeight() const;

private:
    int width, height;
    std::vector<std::vector<int>> grid;
};

#endif // BOARD_H
