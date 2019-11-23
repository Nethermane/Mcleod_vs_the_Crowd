//
// Created by Bruce on 2019-10-13.
//

#ifndef FIGHTCLUB_COMMON_H
#define FIGHTCLUB_COMMON_H
#include <SFML/System/Vector2.hpp>
#include <forward_list>

typedef std::forward_list<sf::Vector2f>::const_iterator MapIterator;

namespace constants {
    const int tower1Cost = 25;
    const int tower2Cost = 50;
    const int tower3Cost = 150;
    const int tower4Cost = 400;
    const int projectileSpeed = 1500;
    const int startingHealth = 100;
    const int maxRound = 10;
    const int startingMoney = 65;
    const float towerSizeMod = 0.6;
}
#endif //FIGHTCLUB_COMMON_H
