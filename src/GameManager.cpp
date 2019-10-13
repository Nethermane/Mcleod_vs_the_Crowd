//
// Created by Bruce on 2019-10-12.
//

#include "GameManager.h"
#include "SFML/Window/Event.hpp"
GameManager::GameManager(sf::RenderWindow &window) : window(window), enemyManager(map), towerManager(map) {

    clock.restart();
    while (window.isOpen()) {
        long long int delta = clock.getElapsedTime().asMicroseconds();
        sf::Event event;
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
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }
        towerManager.update(delta);
        enemyManager.update(delta);
        projectileManager.update(enemyManager.getEnemies(), delta);
        clock.restart();
        window.clear(sf::Color::Green);
        enemyManager.draw(window, sf::RenderStates::Default);
        window.display();
    }
}