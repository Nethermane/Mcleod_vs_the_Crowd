//
// Created by Bruce on 2019-10-12.
//

#ifndef FIGHTCLUB_TOWERMANAGER_H
#define FIGHTCLUB_TOWERMANAGER_H

#include "Map.h"
#include "Tower.h"
#include "Upgrade.h"
#include <algorithm>

/**
 * This class stores all towers and manages the creation of projectiles.
 */
class TowerManager {
private:
    std::forward_list<Upgrade> tower1Upgrades, tower2Upgrades, tower3Upgrades, tower4Upgrades;
    const Map &map;
    std::vector<Tower> towers;
public:
    explicit TowerManager(const Map &map);
    void update(float delta);
    bool addTower(Tower t);
    bool upgradeTower(Tower t);
};


#endif //FIGHTCLUB_TOWERMANAGER_H
