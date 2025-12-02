#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Tetromino.h"

class Game {
public:
    Game();
    void Run();

private:
    void Input();
    void Update();
    void Render();
    void SpawnPiece();

    Board board;
    Tetromino currentPiece;
    bool gameOver;
    int score;
    
    // Timing
    unsigned long lastTime;
    unsigned long timer;
    int delay;
};

#endif // GAME_H
