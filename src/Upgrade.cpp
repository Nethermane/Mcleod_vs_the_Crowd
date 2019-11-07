//
// Created by Bruce on 2019-11-07.
//

#include "Upgrade.h"

Upgrade::Upgrade(const int &range, const int &attackSpeed, const int &level, const int &upgradeCost, const int &cost)
        : range(range),
          attackSpeed(attackSpeed),
          level(level),
          upgradeCost(upgradeCost),
          cost(cost) {}

int Upgrade::getUpgradeCost() const {
    return upgradeCost;
}
