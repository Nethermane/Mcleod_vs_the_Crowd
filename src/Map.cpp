//
// Created by Bruce on 2019-10-12.
//

#include "Map.h"

bool Map::isTowerPositionValid(float x, float y) const {
    return false;
}

bool Map::isTowerPositionValid(sf::Vector2f position) const {
    return isTowerPositionValid(position.x, position.y);
}


Map::Map() {
    turningPoints.emplace_front(1,1);
    turningPoints.emplace_front(0.5,0.1);
    turningPoints.emplace_front(0,0.1);


}

MapIterator Map::begin() const {
    return turningPoints.begin();
}
MapIterator Map::end() const {
    return turningPoints.end();
}