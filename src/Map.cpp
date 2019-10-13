//
// Created by Bruce on 2019-10-12.
//

#include <iostream>
#include <cmath>
#include "Map.h"

bool Map::isTowerPositionValid(float x, float y) const {
    return false;
}

bool Map::isTowerPositionValid(sf::Vector2f position) const {
    return isTowerPositionValid(position.x, position.y);
}

Map::Map(const sf::Vector2u &screenSize) {

    turningPoints.emplace_front(1 * screenSize.x, 0.8 * screenSize.y);
    turningPoints.emplace_front(0.5 * screenSize.x, 0.8 * screenSize.y);
    turningPoints.emplace_front(0.5 * screenSize.x, 0.1 * screenSize.y);
    turningPoints.emplace_front(0 * screenSize.x, 0.1 * screenSize.y);
}

MapIterator Map::begin() const {
    return turningPoints.begin();
}

MapIterator Map::end() const {
    return turningPoints.end();
}