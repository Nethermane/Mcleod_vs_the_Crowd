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

void Map::updateEnemyPosition(Enemy *enemy, long long int delta) const {

}

