//
// Created by Bruce on 2019-10-12.
//

#include <iostream>
#include "GameManager.h"
#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"

GameManager::GameManager(sf::RenderWindow &window) :
        resourceManager(), window(window), gameStateManager(100, 10),
        ingameMenu(window.getSize(), 0.3f, resourceManager, gameStateManager),
        map(window.getSize(), 0.7f), towerManager(map), enemyManager(map, gameStateManager, resourceManager) {
    enemyManager.loadEnemyTextures();
    gameStateManager.start();
    gameStateManager.setMoney(10);
    clock.restart();
    soundManager.play("../music/test.ogg");
    while (window.isOpen()) {
        float delta = clock.getElapsedTime().asSeconds();
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
                            if (gameStateManager.isPaused())
                                soundManager.pause();
                            else
                                soundManager.resume();
                            break;
                        case sf::Keyboard::E:
                            enemyManager.makeEnemies();
                            break;
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
        }
        ingameMenu.update(delta);
        window.clear(sf::Color::Black);
        map.draw(window, sf::RenderStates::Default);
        enemyManager.draw(window, sf::RenderStates::Default);
        ingameMenu.draw(window, sf::RenderStates::Default);
        clock.restart();
        window.display();
    }
}
