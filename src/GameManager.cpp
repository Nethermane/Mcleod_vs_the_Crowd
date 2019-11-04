//
// Created by Bruce on 2019-10-12.
//

#include <iostream>
#include "GameManager.h"
#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"

GameManager::GameManager(sf::RenderWindow &window) : window(window), map(window.getSize()), towerManager(map),
                                                     gameStateManager(100, 10), enemyManager(map, gameStateManager),  soundManager() {

    gameStateManager.start();
    sf::Font font;
    if (!font.loadFromFile("../font/ApexMk2-Regular.otf")) {
        // error...
    }
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);
    clock.restart();
    soundManager.play("../music/test.ogg");
    while (window.isOpen()) {
        float delta = clock.getElapsedTime().asSeconds();
        text.setString(std::to_string(static_cast<int>(1.0f / delta))); //fps
        sf::Event event{};
        while (window.pollEvent(event)) {
            switch (event.type) {
                // window closed
                case sf::Event::Closed:
                    window.close();
                    break;
                    // key pressed
                case sf::Event::KeyPressed:
                    switch (static_cast<char>(event.text.unicode)) {
                        case sf::Keyboard::Q :
                            window.close();
                            break;
                        case sf::Keyboard::P:
                            gameStateManager.togglePause();
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }

        if (!gameStateManager.isPaused()) {
            towerManager.update(delta);
            enemyManager.update(delta);
            projectileManager.update(enemyManager.getEnemies(), delta);
        } else {
            soundManager.start();
        }
        window.clear(sf::Color::Black);
        map.draw(window, sf::RenderStates::Default);
        enemyManager.draw(window, sf::RenderStates::Default);
        window.draw(text);
        clock.restart();
        window.display();
    }
}