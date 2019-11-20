//
// Created by Bruce on 2019-11-07.
//

#include "Upgrade.h"

Upgrade::Upgrade(const int &range, const float &attackSpeed, const int &level, const int &upgradeCost, const int &cost,
        const int& damage)
        : range(range),
          attackSpeed(attackSpeed),
          level(level),
          upgradeCost(upgradeCost),
          cost(cost),
          damage(damage) {}

int Upgrade::getUpgradeCost() const {
    return upgradeCost;
}
