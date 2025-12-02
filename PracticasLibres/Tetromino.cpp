#include "Tetromino.h"

// Shapes definitions: 0=Empty, 1=Block
// I, J, L, O, S, T, Z
const std::vector<std::vector<std::vector<int>>> SHAPES = {
    // I
    {
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    },
    // J
    {
        {1, 0, 0},
        {1, 1, 1},
        {0, 0, 0}
    },
    // L
    {
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0}
    },
    // O
    {
        {1, 1},
        {1, 1}
    },
    // S
    {
        {0, 1, 1},
        {1, 1, 0},
        {0, 0, 0}
    },
    // T
    {
        {0, 1, 0},
        {1, 1, 1},
        {0, 0, 0}
    },
    // Z
    {
        {1, 1, 0},
        {0, 1, 1},
        {0, 0, 0}
    }
};

Tetromino::Tetromino(int type) : type(type), x(0), y(0) {
    if (type >= 0 && type < SHAPES.size()) {
        shape = SHAPES[type];
    }
}

void Tetromino::Rotate() {
    // Simple matrix rotation (transpose + reverse rows)
    int n = shape.size();
    std::vector<std::vector<int>> newShape(n, std::vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            newShape[j][n - 1 - i] = shape[i][j];
        }
    }
    shape = newShape;
}

int Tetromino::GetX() const { return x; }
int Tetromino::GetY() const { return y; }
void Tetromino::SetX(int newX) { x = newX; }
void Tetromino::SetY(int newY) { y = newY; }
const std::vector<std::vector<int>>& Tetromino::GetShape() const { return shape; }
int Tetromino::GetType() const { return type; }
