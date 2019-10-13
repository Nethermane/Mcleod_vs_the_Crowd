//
// Created by Bruce on 2019-10-12.
//
#ifndef FIGHTCLUB_GAMEMANAGER_H
#define FIGHTCLUB_GAMEMANAGER_H

#include <SFML/Graphics.hpp>
#include "EnemyManager.h"
#include "Map.h"
#include "TowerManager.h"
#include "ProjectileManager.h"
#include "UIManager.h"
#include "GameStateManager.h"

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



public:
    GameManager(sf::RenderWindow &window);
};


#endif //FIGHTCLUB_GAMEMANAGER_H
