#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Tetromino.h"

class Game {
public:
    Game(Board& board);

    void spawnPiece();
    bool moveDown();
    void moveLeft();
    void moveRight();
    void rotate();

    int getX() const { return x; }
    int getY() const { return y; }
    int getRotation() const { return rotation; }
    const Tetromino& getPiece() const { return current; }

private:
    bool canMove(int nx, int ny, int nrot);

    Board& board;
    Tetromino current = Tetromino(0);
    int x = 3;
    int y = 0;
    int rotation = 0;
};

#endif
