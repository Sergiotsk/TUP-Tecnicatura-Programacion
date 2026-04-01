#include "Game.h"
#include <iostream>
#include <conio.h> // Windows specific for _kbhit and _getch
#include <windows.h> // For Sleep
#include <ctime>
#include <cstdlib>

Game::Game() : board(10, 20), currentPiece(0), gameOver(false), score(0), delay(500) {
    srand(time(0));
    SpawnPiece();
}

void Game::SpawnPiece() {
    int type = rand() % 7;
    currentPiece = Tetromino(type);
    currentPiece.SetX(board.GetWidth() / 2 - 1); // Center
    currentPiece.SetY(0);

    if (board.IsCollision(currentPiece, currentPiece.GetX(), currentPiece.GetY())) {
        gameOver = true;
    }
}

void Game::Input() {
    if (_kbhit()) {
        char key = _getch();
        int dx = 0;
        int dy = 0;
        bool rotate = false;

        switch (key) {
            case 'a': dx = -1; break; // Left
            case 'd': dx = 1; break;  // Right
            case 's': dy = 1; break;  // Soft drop
            case 'w': rotate = true; break; // Rotate
            case 'x': exit(0); break; // Quit
        }

        if (dx != 0) {
            if (!board.IsCollision(currentPiece, currentPiece.GetX() + dx, currentPiece.GetY())) {
                currentPiece.SetX(currentPiece.GetX() + dx);
            }
        }

        if (rotate) {
            Tetromino temp = currentPiece;
            temp.Rotate();
            if (!board.IsCollision(temp, temp.GetX(), temp.GetY())) {
                currentPiece.Rotate();
            }
        }
        
        if (dy != 0) {
             if (!board.IsCollision(currentPiece, currentPiece.GetX(), currentPiece.GetY() + 1)) {
                currentPiece.SetY(currentPiece.GetY() + 1);
            }
        }
    }
}

void Game::Update() {
    // Simple gravity simulation
    static clock_t lastTime = clock();
    clock_t currentTime = clock();
    
    if ((currentTime - lastTime) * 1000 / CLOCKS_PER_SEC > delay) {
        if (!board.IsCollision(currentPiece, currentPiece.GetX(), currentPiece.GetY() + 1)) {
            currentPiece.SetY(currentPiece.GetY() + 1);
        } else {
            board.LockPiece(currentPiece);
            board.ClearLines();
            SpawnPiece();
        }
        lastTime = currentTime;
    }
}

void Game::Render() {
    system("cls"); // Clear screen
    board.Draw(currentPiece);
    std::cout << "Score: " << score << std::endl;
    std::cout << "Controls: A (Left), D (Right), S (Down), W (Rotate), X (Quit)" << std::endl;
}

void Game::Run() {
    while (!gameOver) {
        Input();
        Update();
        Render();
        Sleep(50); // Small delay to reduce CPU usage
    }
    std::cout << "Game Over!" << std::endl;
}
