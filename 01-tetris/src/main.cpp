// 📦 主循环

#include <iostream>
#include <thread>
#include <chrono>
// #include <conio.h>   // Windows 下可用；Linux/Mac 下需替代
#include "Input.h"
#include "Board.h"
#include "Game.h"
#include "Render.h"

int main() {
    initKeyboard(); // ⚠️

    Board board;
    Game game(board);
    game.spawnPiece();

    while (true) {
        render(board, game);

        if (kbhit()) {
            char ch = getch_noblock();
            if (ch == 'a') game.moveLeft();
            if (ch == 'd') game.moveRight();
            if (ch == 'w') game.rotate();
            if (ch == 's') game.moveDown();
        }

        game.moveDown();
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }

    resetKeyboard();
    return 0;
}
