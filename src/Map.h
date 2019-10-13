//
// Created by Bruce on 2019-10-12.
//

#ifndef FIGHTCLUB_MAP_H
#define FIGHTCLUB_MAP_H

#include "Enemy.h"
/**
 * The Map object represents the path which enemies take
 *
 */
class Map {
private:
    std::forward_list<sf::Vector2f> turningPoints;
public:
    bool isTowerPositionValid(float x, float y) const;
    bool isTowerPositionValid(sf::Vector2f position) const;
    MapIterator begin() const;
    MapIterator end() const;
public:
    Map();

};

#endif //FIGHTCLUB_MAP_H
