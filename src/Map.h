//
// Created by Bruce on 2019-10-12.
//

#ifndef FIGHTCLUB_MAP_H
#define FIGHTCLUB_MAP_H

#include <SFML/System.hpp>
#include <list>
#include "Enemy.h"

/**
 * The Map object represents the path which enemies take
 *
 */
class Map {
    std::list<sf::Vector2f> turningPoints;
public:
    bool isTowerPositionValid(float x, float y) const;
    bool isTowerPositionValid(sf::Vector2f position) const;
    /**
     * Takes an enemy object. Moves that enemy along the path to it's nextPosition
     * This is done by calculating how long it should take to get to the point, then
     * once the time is greater than that update rotation and use std::next for the next turning point
     * Then calculates the time for that.
     * @param enemy to update position of
     * @param delta amount of time since last frame
     */
    void updateEnemyPosition(Enemy *enemy, long long int delta) const;

public:


};


#endif //FIGHTCLUB_MAP_H
