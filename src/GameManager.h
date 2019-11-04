//
// Created by Bruce on 2019-10-12.
//
#ifndef FIGHTCLUB_GAMEMANAGER_H
#define FIGHTCLUB_GAMEMANAGER_H

#include "EnemyManager.h"
#include "Map.h"
#include "TowerManager.h"
#include "ProjectileManager.h"
#include "UIManager.h"
#include "GameStateManager.h"
#include "ResourceManager.h"
#include <SFML/Graphics/RenderWindow.hpp>

class GameManager {
private:
    sf::RenderWindow &window;
    sf::Clock clock;
    Map map;
    EnemyManager enemyManager;
    TowerManager towerManager;
    ProjectileManager projectileManager;
    UIManager UIManager;
    GameStateManager gameStateManager;
    ResourceManager resourceManager;
    void loadTextures();


public:
    explicit GameManager(sf::RenderWindow &window);
};


#endif //FIGHTCLUB_GAMEMANAGER_H
