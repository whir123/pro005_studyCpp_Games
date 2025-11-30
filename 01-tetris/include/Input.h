#ifndef INPUT_H
#define INPUT_H

#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>

// 关闭回显、关闭行缓冲（进入原始模式）
static struct termios oldt, newt;

void initKeyboard() {
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    // 关闭 canonical mode 和回显
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // 设置非阻塞
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
}

void resetKeyboard() {
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

// 检测键盘是否有按键（非阻塞）
bool kbhit() {
    fd_set set;
    struct timeval timeout = {0, 0};

    FD_ZERO(&set);
    FD_SET(STDIN_FILENO, &set);

    return select(STDIN_FILENO+1, &set, NULL, NULL, &timeout) > 0;
}

// 读取一个字符（非阻塞）
int getch_noblock() {
    unsigned char c;
    if (read(STDIN_FILENO, &c, 1) < 0) return -1;
    return c;
}

#endif
