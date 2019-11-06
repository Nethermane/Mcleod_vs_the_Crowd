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

Map::Map(const sf::Vector2u &screenSize, const float &percentScreenTake) {
    turningPoints.emplace_front(1 * screenSize.x * percentScreenTake, 0.9 * screenSize.y);
    turningPoints.emplace_front(0.6 * screenSize.x * percentScreenTake, 0.1 * screenSize.y);
    turningPoints.emplace_front(0.3 * screenSize.x * percentScreenTake, 0.9 * screenSize.y);
    turningPoints.emplace_front(0 * screenSize.x * percentScreenTake, 0.1 * screenSize.y);
    for(const sf::Vector2f &point: turningPoints)
        spline.addVertex(point);
    spline.update();
}

MapIterator Map::begin() const {
    return turningPoints.begin();
}

MapIterator Map::end() const {
    return turningPoints.end();
}

void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(spline);
}