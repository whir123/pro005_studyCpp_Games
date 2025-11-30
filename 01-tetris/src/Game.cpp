// 📦 核心逻辑

#include "Game.h"
#include <cstdlib>
// 方块生命周期：
// 生成 → 移动/旋转 → 固定 → 消除 → 生成新方块

// ⚠️
// 能下落 → 继续下落
// 不能下落 → 固定当前方块 → 消除满行 → 生成新方块

Game::Game(Board& b) : board(b) {}

void Game::spawnPiece() {
    int type = rand() % 7;
    current = Tetromino(type);
    x = 3;
    y = 0;
    rotation = 0;
}

bool Game::canMove(int nx, int ny, int nrot) {
    const int (*shape)[4] = current.getShape(nrot);
    for (int r = 0; r < 4; r++)
        for (int c = 0; c < 4; c++)
            if (shape[r][c] == 1)
                if (board.isOccupied(nx + c, ny + r))
                    return false; // ⚠️ 碰撞发生，不能移动
    return true;
}

bool Game::moveDown() {
    if (canMove(x, y + 1, rotation)) {
        y++;
        return true;
    } else {
        // 固定
        board.mergePiece(x, y, current.getShape(rotation));
        board.clearFullLines();
        spawnPiece();
        return false;
    }
}

void Game::moveLeft() {
    if (canMove(x - 1, y, rotation)) x--;
}

void Game::moveRight() {
    if (canMove(x + 1, y, rotation)) x++;
}

void Game::rotate() {
    int nr = (rotation + 1) % 4;
    if (canMove(x, y, nr)) rotation = nr;
}
