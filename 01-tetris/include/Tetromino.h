#ifndef TETROMINO_H
#define TETROMINO_H

class Tetromino {
public:
    Tetromino(int type);
    const int (*getShape(int rotation) const)[4];
    // ⚠️
    // getShape(int rotation) - 接受旋转状态参数(0-3)
    // const - 成员函数const，不修改对象状态
    // const int (*...)[4] - 返回指向 int[4] 数组的常量指针 指向4×4形状数组的第一行

    int getType() const { return type; }

private:
    int type; // 0~6
    static const int shapes[7][4][4][4]; // 四维数组 存储七种不同形状
    // ⚠️
    // [7] - 7种方块类型 (I, O, T, S, Z, J, L)
    // [4] - 4种旋转状态 (0°, 90°, 180°, 270°)
    // [4][4] - 4×4的方块形状网格
};

#endif
