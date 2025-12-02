#include "Board.h"
#include <iostream>

Board::Board(int width, int height) : width(width), height(height) {
    grid.resize(height, std::vector<int>(width, 0));
}

bool Board::IsCollision(const Tetromino& piece, int newX, int newY) const {
    const auto& shape = piece.GetShape();
    int n = shape.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (shape[i][j] != 0) {
                int boardX = newX + j;
                int boardY = newY + i;

                if (boardX < 0 || boardX >= width || boardY >= height) {
                    return true; // Out of bounds
                }
                if (boardY >= 0 && grid[boardY][boardX] != 0) {
                    return true; // Overlap with existing block
                }
            }
        }
    }
    return false;
}

void Board::LockPiece(const Tetromino& piece) {
    const auto& shape = piece.GetShape();
    int n = shape.size();
    int x = piece.GetX();
    int y = piece.GetY();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (shape[i][j] != 0) {
                int boardY = y + i;
                int boardX = x + j;
                if (boardY >= 0 && boardY < height && boardX >= 0 && boardX < width) {
                    grid[boardY][boardX] = 1; // Mark as occupied
                }
            }
        }
    }
}

void Board::ClearLines() {
    for (int i = height - 1; i >= 0; --i) {
        bool fullRow = true;
        for (int j = 0; j < width; ++j) {
            if (grid[i][j] == 0) {
                fullRow = false;
                break;
            }
        }

        if (fullRow) {
            // Move all rows above down
            for (int k = i; k > 0; --k) {
                grid[k] = grid[k - 1];
            }
            // Clear top row
            grid[0] = std::vector<int>(width, 0);
            i++; // Check the same row again as it's now a new row
        }
    }
}

void Board::Draw(const Tetromino& currentPiece) const {
    // Create a temporary buffer to draw both board and piece
    std::vector<std::vector<int>> displayGrid = grid;

    // Overlay current piece
    const auto& shape = currentPiece.GetShape();
    int n = shape.size();
    int x = currentPiece.GetX();
    int y = currentPiece.GetY();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (shape[i][j] != 0) {
                int boardY = y + i;
                int boardX = x + j;
                if (boardY >= 0 && boardY < height && boardX >= 0 && boardX < width) {
                    displayGrid[boardY][boardX] = 2; // 2 represents current piece
                }
            }
        }
    }

    // Draw to console
    // Clear screen (system specific, using newlines for simplicity/portability)
    // For Windows 'cls' is common, but let's just print a lot of newlines or use a specific escape code if needed.
    // For now, let's just print the frame.
    
    // Using ANSI escape codes to clear screen and move cursor to top-left might be better, 
    // but for simple Windows console, `system("cls")` is often used in tutorials.
    // I'll stick to printing for now, maybe system("cls") in the Game loop.

    std::cout << "----------" << std::endl; 
    for (int i = 0; i < height; ++i) {
        std::cout << "|";
        for (int j = 0; j < width; ++j) {
            if (displayGrid[i][j] == 0) std::cout << " .";
            else if (displayGrid[i][j] == 1) std::cout << "[]"; // Locked
            else if (displayGrid[i][j] == 2) std::cout << "##"; // Current
        }
        std::cout << "|" << std::endl;
    }
    std::cout << "----------" << std::endl;
}

int Board::GetWidth() const { return width; }
int Board::GetHeight() const { return height; }
