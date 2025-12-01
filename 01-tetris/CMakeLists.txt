cmake_minimum_required(VERSION 3.20)
project(tetris)

set(CMAKE_CXX_STANDARD 17)

# 指定 Homebrew SFML 3 安装路径
set(SFML_DIR "/opt/homebrew/Cellar/sfml/3.0.2/lib/cmake/SFML")

# SFML 3.x 组件写法
find_package(SFML 3 REQUIRED COMPONENTS sfml-graphics sfml-window sfml-system)

add_executable(tetris
    src/main.cpp
    src/Board.cpp
    src/Game.cpp
    src/RenderSFML.cpp
    src/Tetromino.cpp
)

target_link_libraries(tetris sfml-graphics sfml-window sfml-system)
