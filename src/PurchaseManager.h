//
// Created by jason on 11/11/19.
//

#ifndef FIGHTCLUB_PURCHASEMANAGER_H
#define FIGHTCLUB_PURCHASEMANAGER_H

#include "Map.h"
#include "GameStateManager.h"
#include "TowerManager.h"
#include "Tower.h"

class PurchaseManager{
public:
    PurchaseManager(const Map &map, GameStateManager &gameStateManager, TowerManager &towerManager);
    void purchase(const TowerType &t, const sf::Vector2f &position);
    void upgrade(Tower &t);
private:
    bool isTowerPositionValid(float x, float y);
    bool isTowerCostValid(float cost);
    const Map &map;
    GameStateManager &gameStateManager;
    TowerManager &towerManager;

};

#endif //FIGHTCLUB_PURCHASEMANAGER_H
