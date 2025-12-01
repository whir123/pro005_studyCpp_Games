#ifndef RENDER_SFML_H
#define RENDER_SFML_H

#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Game.h"

// 在 SFML 窗口中渲染
void renderSFML(sf::RenderWindow& window, const Board& board, const Game& game);

#endif
