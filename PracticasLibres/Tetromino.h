#ifndef TETROMINO_H
#define TETROMINO_H

#include <vector>

class Tetromino {
public:
    Tetromino(int type);
    void Rotate();
    int GetX() const;
    int GetY() const;
    void SetX(int x);
    void SetY(int y);
    const std::vector<std::vector<int>>& GetShape() const;
    int GetType() const;

private:
    int x, y;
    int type;
    std::vector<std::vector<int>> shape;
};

#endif // TETROMINO_H
