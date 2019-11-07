//
// Created by Bruce on 2019-10-12.
//

#include "Tower.h"
#include "Upgrade.h"
bool Tower::canUpgrade() const {
    return nextUpgrade != upgradeEnd;
}


void Tower::upgrade() {
    auto upgrade = *nextUpgrade;
    range = upgrade.range;
    attackSpeed = upgrade.attackSpeed;
    level = upgrade.level;
    cost = upgrade.cost;
    nextUpgrade = std::next(nextUpgrade, 1);
}

int Tower::getUpgradeCost() const {
    return (*nextUpgrade).upgradeCost;
}
