//
// Created by Bruce on 2019-11-07.
//

#ifndef FIGHTCLUB_UPGRADEMANAGER_H
#define FIGHTCLUB_UPGRADEMANAGER_H


#include "GameStateManager.h"
#include "Tower.h"
#include <forward_list>

class UpgradeManager {

private:
    std::forward_list<Upgrade> tower1Upgrades, tower2Upgrades, tower3Upgrades, tower4Upgrades;
public:
    explicit UpgradeManager();

    void upgrade(Tower &tower);
};


#endif //FIGHTCLUB_UPGRADEMANAGER_H
