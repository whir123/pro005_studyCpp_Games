#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Game.h"
#include "RenderSFML.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(300, 600), "Tetris");
    Board board;
    Game game(board);
    game.spawnPiece();

    sf::Clock clock;
    float timer = 0.0f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::A) game.moveLeft();
                if (event.key.code == sf::Keyboard::D) game.moveRight();
                if (event.key.code == sf::Keyboard::W) game.rotate();
                if (event.key.code == sf::Keyboard::S) game.moveDown();
            }
        }

        float dt = clock.restart().asSeconds();
        timer += dt;

        if (timer > 0.5f) {
            game.moveDown();
            timer = 0;
        }

        renderSFML(window, board, game);
    }

    return 0;
}
