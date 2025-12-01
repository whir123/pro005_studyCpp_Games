// ⭐️ 渲染逻辑改成 SFML 画方块
// brew install sfml@2

#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Game.h"

static const int CELL = 30;

void renderSFML(sf::RenderWindow& window, const Board& board, const Game& game) {
    // ⚠️ window: SFML的渲染窗口对象 ｜ board: 棋盘对象（存储已固定的方块） ｜ game: 游戏对象（包含当前正在下落的方块信息）
    window.clear(sf::Color::Black);

    // ⚠️ 创建正方形 长宽28像素 青色填充
    sf::RectangleShape block(sf::Vector2f(CELL - 2, CELL - 2));
    block.setFillColor(sf::Color::Cyan);

    // 💡「auto 是 C++11 引入的一个类型推导关键字 它让编译器自动推断变量的类型 不需要手动写出完整类型」
    auto grid = board.getGrid(); // 获取棋盘网格数据
    auto shape = game.getPiece().getShape(game.getRotation()); // 获取当前方块的形状

    int px = game.getX(); // 当前方块的x坐标
    int py = game.getY(); // 当前方块的y坐标

    // ⚠️ 绘制已固定的方块
    for (int y = 0; y < Board::HEIGHT; y++) {
        for (int x = 0; x < Board::WIDTH; x++) {
            if (grid[y][x]) {
                block.setPosition(sf::Vector2f(
                    static_cast<float>(x * CELL),
                    static_cast<float>(y * CELL)
                ));
                window.draw(block);
            }
        }
    }

    // ⚠️ 绘制当前正下落的方块
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            if (shape[r][c] == 1) {
            block.setPosition(sf::Vector2f(
                static_cast<float>((px + c) * CELL),
                static_cast<float>((py + r) * CELL)
            ));
                window.draw(block);
            }
        }
    }

    window.display();
}
