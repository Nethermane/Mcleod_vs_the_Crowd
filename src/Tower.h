//
// Created by Bruce on 2019-10-12.
//

#ifndef FIGHTCLUB_TOWER_H
#define FIGHTCLUB_TOWER_H


#include <SFML/Graphics/Sprite.hpp>

class Tower: sf::Sprite {
private:
    int range, attackSpeed, rotation, lastAttack, cost, level, upgradeCost;
    long long int timeSinceLastAttack;

};


#endif //FIGHTCLUB_TOWER_H
