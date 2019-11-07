//
// Created by Bruce on 2019-11-07.
//

#include "UpgradeManager.h"

void UpgradeManager::upgrade(Tower &tower) {
    (*tower.getUpgrade()).apply(tower);
}

UpgradeManager::UpgradeManager() {
    tower1Upgrades.push_front(Upgrade(400, 50, 4, 250, 100));
    tower1Upgrades.push_front(Upgrade(200, 35, 3, 100, 10));
    tower1Upgrades.push_front(Upgrade(150, 20, 2, 50, 10));
    tower1Upgrades.push_front(Upgrade(125, 10, 1, 25, 10));
    tower1Upgrades.push_front(Upgrade(100, 5, 0, 10, 10));
    //TODO: Add 4 different upgrade paths
}