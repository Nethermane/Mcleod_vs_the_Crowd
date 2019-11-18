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
    PurchaseManager(const Map &map, GameStateManager &gameStateManager);
    int purchase(Tower t, float x, float y);
    int upgrade(Tower t, bool upgrade);
private:
    bool isTowerPositionValid(float x, float y);
    bool isTowerCostValid(float cost);
    const Map &map;
    GameStateManager &gameStateManager;
    TowerManager &towerManager;

};

#endif //FIGHTCLUB_PURCHASEMANAGER_H
