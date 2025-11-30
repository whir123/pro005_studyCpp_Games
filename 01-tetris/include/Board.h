#ifndef BOARD_H // 作用：防止头文件被重复包含，避免编译错误
#define BOARD_H

class Board {
public:
    static const int WIDTH = 10;
    static const int HEIGHT = 20;

    Board(); // 构造函数 声明

    // 公有成员函数 外部可调用：
    bool isOccupied(int x, int y) const;
    void setCell(int x, int y, int val);
    void mergePiece(int px, int py, const int shape[4][4]);
    void clearFullLines();
    const int (*getGrid() const)[WIDTH];

private:
    int grid[HEIGHT][WIDTH];
};

#endif