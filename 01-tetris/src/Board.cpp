// 📦 地图和格子管理

#include "Board.h"
#include <cstring>

Board::Board() {
    // 创建棋盘时初始化所有格子为空
    memset(grid, 0, sizeof(grid));
}

bool Board::isOccupied(int x, int y) const {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) return true;
    return grid[y][x] == 1; // 检查该位置是否为1（有方块）
}

void Board::setCell(int x, int y, int val) {
    grid[y][x] = val; // 直接设置指定位置的值
}

void Board::mergePiece(int px, int py, const int shape[4][4]) {
    for (int r = 0; r < 4; r++)
        for (int c = 0; c < 4; c++)
            if (shape[r][c] == 1) // 如果方块形状的该位置为1
                grid[py + r][px + c] = 1; // 在棋盘对应位置标记为1
}

void Board::clearFullLines() {
    for (int y = HEIGHT - 1; y >= 0; y--) { // 从底部向上检查
        bool full = true;
        for (int x = 0; x < WIDTH; x++) {
            if (grid[y][x] == 0) {
                full = false;
                break;
            }
        }
        if (full) {
            // 下移所有行
            for (int row = y; row > 0; row--) {
                for (int col = 0; col < WIDTH; col++)
                    grid[row][col] = grid[row - 1][col];
            }
            for (int col = 0; col < WIDTH; col++)
                grid[0][col] = 0;

            y++; // 重新检查这一行
        }
    }
}

const int (*Board::getGrid() const)[WIDTH] {
    return grid; // 返回指向整个网格的指针 ｜ ⚠️ 返回一个指针，指向 int[WIDTH] 数组
}

// ⚠️
// grid[0] → [0,0,0,0,0,0,0,0,0,0]   ← 返回的指针指向这里
// grid[1] → [0,0,0,0,0,0,0,0,0,0]
// grid[2] → [0,0,0,0,0,0,0,0,0,0]
// ...
// grid[19] → [0,0,0,0,0,0,0,0,0,0]