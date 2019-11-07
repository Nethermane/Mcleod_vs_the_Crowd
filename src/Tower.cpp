//
// Created by Bruce on 2019-10-12.
//

#include "Tower.h"

bool Tower::canUpgrade() const {
    return nextUpgrade != upgradeEnd;
}

std::forward_list<Upgrade>::const_iterator Tower::getUpgrade() {
    return nextUpgrade;
}

int Tower::getUpgradeCost() const {
    return (*nextUpgrade).getUpgradeCost();
}


void Upgrade::apply(Tower &tower) const {
    tower.range = range;
    tower.attackSpeed = attackSpeed;
    tower.level = level;
    tower.cost = cost;
    tower.nextUpgrade = std::next(tower.nextUpgrade, 1);
}

Upgrade::Upgrade(const int &range, const int &attackSpeed, const int &level, const int &upgradeCost, const int &cost)
        : range(range),
          attackSpeed(attackSpeed),
          level(level),
          upgradeCost(upgradeCost),
          cost(cost) {}

int Upgrade::getUpgradeCost() const {
    return upgradeCost;
}


