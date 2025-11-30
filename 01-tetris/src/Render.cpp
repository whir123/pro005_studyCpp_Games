#include "Render.h"
#include <iostream>
#include <cstdlib>

static void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void render(const Board& board, const Game& game) {
    // clearScreen();
    std::cout << "\033[2J\033[1;1H";

    const int (*grid)[Board::WIDTH] = board.getGrid();
    const int (*shape)[4] = game.getPiece().getShape(game.getRotation());
    int px = game.getX();
    int py = game.getY();

    for (int y = 0; y < Board::HEIGHT; y++) {
        for (int x = 0; x < Board::WIDTH; x++) {
            bool printed = false;

            // 当前方块
            for (int r = 0; r < 4; r++)
                for (int c = 0; c < 4; c++)
                    if (shape[r][c] == 1 && y == py + r && x == px + c) {
                        std::cout << "■";
                        printed = true;
                    }

            if (!printed) {
                if (grid[y][x] == 1) std::cout << "■";
                else std::cout << "·";
            }
        }
        std::cout << "\n";
    }
}
