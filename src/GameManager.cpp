//
// Created by Bruce on 2019-10-12.
//

#include <iostream>
#include "GameManager.h"

GameManager::GameManager(sf::RenderWindow &window) :
        resourceManager(), window(window), gameStateManager(100, 10),
        gameClickHitBox(0, 0, static_cast<int>(window.getSize().x * 0.7f), window.getSize().y),
        menuClickHitBox(static_cast<int>(window.getSize().x * 0.7f), 0, static_cast<int>(window.getSize().x * 0.3f),
                        window.getSize().y),
        ingameMenu(window.getSize(), 0.3f, resourceManager, gameStateManager),
        map(window.getSize(), 0.7f), towerManager(map, enemyManager, projectileManager, resourceManager,
                                                  sf::FloatRect(0, 0, static_cast<int>(window.getSize().x * 0.7f),
                                                                window.getSize().y)),
        enemyManager(map, gameStateManager, resourceManager),
        purchaseManager(map, gameStateManager) {
    gameStateManager.start();
    gameStateManager.setMoney(10);
    window.setMouseCursorVisible(false);
    sf::Sprite mouse(*resourceManager.GetTexture(ResourceIdentifier::pointer));
    towerManager.createTower(resourceManager.GetTexture(ResourceIdentifier::mcleod), sf::Vector2f(500, 500),
                             TowerType::Tower1);
    clock.restart();
    soundManager.play("../music/test.ogg");
    sf::CircleShape range;

    soundManager.mute();
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
                        default:
                            break;
                    }
                    break;
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i click = sf::Mouse::getPosition(window);
                        MenuButtonPresses transactionType = ingameMenu.menuClick(click);
                        if (transactionType == MenuButtonPresses::None) {
                        } else if (transactionType == MenuButtonPresses::Pause) {
                            gameStateManager.togglePause();
                        } else if (transactionType == MenuButtonPresses::Mute) {
                            soundManager.mute();
                        } else if (transactionType == MenuButtonPresses::UnMute) {
                            soundManager.unMute();
                        } else if (transactionType == MenuButtonPresses::Options) {
                            //TODO: Handle options
                        } else if (transactionType == MenuButtonPresses::Upgrade) {
                            auto towerToUpgrade = *ingameMenu.getSelectedTower();
                            auto upgradeCost = (towerToUpgrade).getUpgradeCost();
                            if (towerToUpgrade.canUpgrade() && gameStateManager.getMoney() >= upgradeCost) {
                                (*ingameMenu.getSelectedTower()).upgrade();
                                gameStateManager.setMoney(gameStateManager.getMoney() - upgradeCost);
                            }
                        } else {
                            //TODO: Handle tower buying
                            if (transactionType == MenuButtonPresses::Tower1) {
                                mouse.setTexture(*resourceManager.GetTexture(ResourceIdentifier::mcleod), true);
                                mouse.setOrigin(mouse.getLocalBounds().width / 2, mouse.getLocalBounds().height / 2);
                                range.setRadius(mouse.getLocalBounds().width * 2);
                                range.setFillColor(sf::Color(255, 255, 255, 128));
                                range.setOrigin(range.getLocalBounds().width / 2, range.getLocalBounds().height / 2);
                            } else {
                                range.setRadius(0);
                                mouse.setTexture(*resourceManager.GetTexture(ResourceIdentifier::pointer), true);
                            }
                        }
                        //Click was somewhere on game field
                        if (transactionType == MenuButtonPresses::None && gameClickHitBox.contains(click)) {
                            //TODO: handle clicking in game. Select tower or place tower
                        }
                    }
                    break;
                default:
                    break;
            }
        }
        mouse.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
        range.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));

        if (!gameStateManager.isPaused()) {
            double time = 0;
            clock_t start = std::clock();
            towerManager.update(delta);
            clock_t stop = std::clock();
            time = (double) (stop - start);
            if (time > 0)
                std::cout << time / CLOCKS_PER_SEC << "Time for towers" << std::endl;
            start = std::clock();
            enemyManager.update(delta);
            stop = std::clock();
            time = (double) (stop - start);
            if (time > 0)
                std::cout << time / CLOCKS_PER_SEC << "Time for enemies" << std::endl;
            start = std::clock();
            projectileManager.update(delta, const_cast<std::vector<Enemy> &>(enemyManager.getEnemies()));
            stop = std::clock();
            time = (double) (stop - start);
            if (time > 0)
                std::cout << time / CLOCKS_PER_SEC << "Time for projectiles" << std::endl;
        }
        ingameMenu.update(delta);
        window.clear(sf::Color::Black);
        map.draw(window, sf::RenderStates::Default);
        enemyManager.draw(window, sf::RenderStates::Default);
        ingameMenu.draw(window, sf::RenderStates::Default);
        towerManager.draw(window, sf::RenderStates::Default);
        projectileManager.draw(window, sf::RenderStates::Default);
        window.draw(mouse);
        window.draw(range);
        clock.restart();
        window.display();
    }
}
