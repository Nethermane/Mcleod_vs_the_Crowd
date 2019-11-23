//
// Created by jason on 11/11/19.
//

#include "PurchaseManager.h"

PurchaseManager::PurchaseManager(const Map &map, GameStateManager &gameStateManager, TowerManager &towerManager):
map(map), gameStateManager(gameStateManager), towerManager(towerManager){

}

void PurchaseManager::purchase(const TowerType& t, const sf::Vector2f &position) {
    if(isTowerCostValid(static_cast<int>(t)) && towerManager.isTowerPositionValid(position)){
            gameStateManager.setMoney(gameStateManager.getMoney() - static_cast<int>(t));
            towerManager.createTower(position, t);
    }
}

void PurchaseManager::upgrade(Tower &t) {
        if(isTowerCostValid(float (t.getUpgradeCost()))){
            t.upgrade();
            gameStateManager.setMoney(gameStateManager.getMoney() - t.getUpgradeCost());
        }
}


bool PurchaseManager::isTowerCostValid(float cost) {
    //check if valid cost
    return cost <= this->gameStateManager.getMoney() && cost >= 0;
}
