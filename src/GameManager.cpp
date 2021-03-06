//
// Created by Bruce on 2019-10-12.
//

#include <iostream>
#include "GameManager.h"

GameManager::GameManager(sf::RenderWindow &window) :
        resourceManager(), window(window),
        gameStateManager(constants::startingHealth, constants::maxRound, constants::startingMoney),
        gameClickHitBox(0, 0, static_cast<int>(window.getSize().x * 0.7f), window.getSize().y),
        menuClickHitBox(static_cast<int>(window.getSize().x * 0.7f), 0, static_cast<int>(window.getSize().x * 0.3f),
                        window.getSize().y),

        map(window.getSize(), 0.7f), towerManager(map, enemyManager, projectileManager, resourceManager,
                                                  sf::FloatRect(0, 0, static_cast<int>(window.getSize().x * 0.7f),
                                                                window.getSize().y)),
        enemyManager(map, gameStateManager, resourceManager),
        ingameMenu(window.getSize(), 0.3f, resourceManager, gameStateManager, towerManager),
        purchaseManager(map, gameStateManager, towerManager) {
    gameStateManager.start();
    window.setMouseCursorVisible(false);
    clock.restart();
    soundManager.play("../music/test.ogg");
    sf::Sprite background{*resourceManager.GetTexture(ResourceIdentifier::track)};
    background.setScale(window.getSize().x * 0.7f / background.getLocalBounds().width,
                        window.getSize().y / background.getLocalBounds().height);
    soundManager.mute();
    while (window.isOpen()) {
        float delta = clock.getElapsedTime().asSeconds();
        sf::Event event{};
        auto mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
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
                        MenuButtonPresses transactionType = ingameMenu.menuPosition(mousePos);
                        if (transactionType == MenuButtonPresses::None) {
                        } else if (transactionType == MenuButtonPresses::Pause) {
                            gameStateManager.togglePause();
                        } else if (transactionType == MenuButtonPresses::Mute) {
                            soundManager.mute();
                            ingameMenu.setMute();
                        } else if (transactionType == MenuButtonPresses::UnMute) {
                            soundManager.unMute();
                            ingameMenu.setUnMute();
                        } else if (transactionType == MenuButtonPresses::Options) {
                            //TODO: Handle options
                        } else if (transactionType == MenuButtonPresses::Upgrade) {
                            if (ingameMenu.getSelectedTower() != nullptr) {
                                auto towerToUpgrade = *ingameMenu.getSelectedTower();
                                auto upgradeCost = (towerToUpgrade).getUpgradeCost();
                                if (towerToUpgrade.canUpgrade() && gameStateManager.getMoney() >= upgradeCost) {
                                    (*ingameMenu.getSelectedTower()).upgrade();
                                    ingameMenu.selectTower(*(ingameMenu.getSelectedTower())); //update range
                                    gameStateManager.setMoney(gameStateManager.getMoney() - upgradeCost);
                                }
                            }
                        } else {
                            //TODO: Handle tower buying
                            if (transactionType == MenuButtonPresses::Tower1) {
                                if (static_cast<int>(TowerType::Tower1) <= gameStateManager.getMoney())
                                    ingameMenu.setSelectedTowerType(TowerType::Tower1);
                            } else if (transactionType == MenuButtonPresses::Tower2) {
                                if (static_cast<int>(TowerType::Tower2) <= gameStateManager.getMoney())
                                    ingameMenu.setSelectedTowerType(TowerType::Tower2);
                            } else if (transactionType == MenuButtonPresses::Tower3) {
                                if (static_cast<int>(TowerType::Tower3) <= gameStateManager.getMoney())
                                    ingameMenu.setSelectedTowerType(TowerType::Tower3);
                            } else if (transactionType == MenuButtonPresses::Tower4) {
                                if (static_cast<int>(TowerType::Tower4) <= gameStateManager.getMoney())
                                    ingameMenu.setSelectedTowerType(TowerType::Tower4);
                            }
                        }
                        //Click was somewhere on game field
                        if (transactionType == MenuButtonPresses::None && gameClickHitBox.contains(click) &&
                            ingameMenu.getSelectedTowerType() != TowerType::None) {
                            if (towerManager.isTowerPositionValid(mousePos)) {
                                purchaseManager.purchase(ingameMenu.getSelectedTowerType(), mousePos);
                                ingameMenu.setSelectedTowerType(TowerType::None);
                            } else {
                                ingameMenu.setSelectedTowerType(TowerType::None);
                            }
                        } else if (transactionType == MenuButtonPresses::MenuBackground &&
                                   menuClickHitBox.contains(click) &&
                                   ingameMenu.getSelectedTowerType() != TowerType::None) {
                            ingameMenu.setSelectedTowerType(TowerType::None);
                        } else if (gameClickHitBox.contains(click) &&
                                   ingameMenu.getSelectedTowerType() == TowerType::None) {
                            auto tower = towerManager.getTowerAtPoint(click);
                            if (tower != nullptr) {
                                ingameMenu.selectTower(*tower);
                            } else {
                                ingameMenu.deselectTower();
                            }
                        }
                    }
                    break;
                default:
                    break;
            }
        }
        if (!gameStateManager.isPaused()) {
            towerManager.update(delta);
            enemyManager.update(delta);
            projectileManager.update(delta, const_cast<std::vector<Enemy> &>(enemyManager.getEnemies()));
        }
        ingameMenu.update(delta, mousePos);
        window.clear(sf::Color::Black);
        window.draw(background);
        map.draw(window, sf::RenderStates::Default);
        enemyManager.draw(window, sf::RenderStates::Default);
        towerManager.draw(window, sf::RenderStates::Default);
        projectileManager.draw(window, sf::RenderStates::Default);
        ingameMenu.draw(window, sf::RenderStates::Default);
        clock.restart();
        window.display();
    }
}
