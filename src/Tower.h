//
// Created by Bruce on 2019-10-12.
//

#ifndef FIGHTCLUB_TOWER_H
#define FIGHTCLUB_TOWER_H


#include <SFML/Graphics/Sprite.hpp>
#include <forward_list>
#include "Upgrade.h"

class Tower : sf::Sprite {
public:
    ///Returns true if tower has another upgrade available
    bool canUpgrade() const;

    ///Upgrades the tower,
    void upgrade();

    int getUpgradeCost() const;

private:
    int range, attackSpeed, rotation, lastAttack, cost, level;
    long long int timeSinceLastAttack;

    friend class Upgrade;

    std::forward_list<Upgrade>::const_iterator nextUpgrade;
    std::forward_list<Upgrade>::const_iterator upgradeEnd;

};


#endif //FIGHTCLUB_TOWER_H
