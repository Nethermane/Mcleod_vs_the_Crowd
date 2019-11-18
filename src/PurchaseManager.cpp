//
// Created by jason on 11/11/19.
//

#include "PurchaseManager.h"

PurchaseManager::PurchaseManager(const Map &map, GameStateManager &gameStateManager):
map(map), gameStateManager(gameStateManager), towerManager(towerManager){

}

int PurchaseManager::purchase(Tower t, float x, float y) {
    if(isTowerCostValid(t.getCost())){
        if(isTowerPositionValid(x, y)){
            gameStateManager.setMoney(gameStateManager.getMoney() - t.getCost());
            towerManager.addTower(t);
            return 1;
        }
    }
    return 0;
}

int PurchaseManager::upgrade(Tower t, bool upgrade) {
    if(upgrade){
        if(isTowerCostValid(float (t.getUpgradeCost()))){
            t.upgrade();
            gameStateManager.setMoney(gameStateManager.getMoney() - t.getUpgradeCost());
            return 1;
        }
    }
    return 0;
}

bool PurchaseManager::isTowerPositionValid(float x, float y) {
    //check if valid position on map
    return this->map.isTowerPositionValid(x, y);
}

bool PurchaseManager::isTowerCostValid(float cost) {
    //check if valid cost
    return cost <= this->gameStateManager.getMoney() && cost >= 0;
}
