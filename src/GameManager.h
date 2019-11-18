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
#include "SoundManager.h"
#include "ResourceManager.h"
#include "InGameMenu.h"
#include "PurchaseManager.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>

///Main game class that holds all aspects of the game
class GameManager {
private:
    sf::RenderWindow &window;
    sf::Clock clock;
    ResourceManager resourceManager;
    Map map;
    EnemyManager enemyManager;
    TowerManager towerManager;
    ProjectileManager projectileManager;
    UIManager uiManager;
    GameStateManager gameStateManager;
    SoundManager soundManager;
    InGameMenu ingameMenu;
    PurchaseManager purchaseManager;
    sf::IntRect gameClickHitBox, menuClickHitBox;

public:
    explicit GameManager(sf::RenderWindow &window);
};


#endif //FIGHTCLUB_GAMEMANAGER_H
