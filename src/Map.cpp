//
// Created by Bruce on 2019-10-12.
//

#include <iostream>
#include <cmath>
#include "Map.h"
#include "MathHelpers.h"


Map::Map(const sf::Vector2u &screenSize, const float &percentScreenTake) {
    turningPoints.emplace_front(1 * screenSize.x * percentScreenTake, 0.9 * screenSize.y);
    turningPoints.emplace_front(0.6 * screenSize.x * percentScreenTake, 0.1 * screenSize.y);
    turningPoints.emplace_front(0.3 * screenSize.x * percentScreenTake, 0.9 * screenSize.y);
    turningPoints.emplace_front(0 * screenSize.x * percentScreenTake, 0.1 * screenSize.y);
    spline.setThickness(screenSize.x / 100.0f);
    spline.setThickCornerType(sw::Spline::ThickCornerType::Round);
    auto point = turningPoints.begin();
    sf::Vector2f secondLastVertex;
    bool extendLast = false;
    while (point != turningPoints.end()) {
        if (point == turningPoints.begin()) {
            auto next = std::next(point, 1);
            if (next == end())
                throw std::runtime_error("Track needs more points");
            float angle = angleBetweenTwoPoints(*point, *next);
            spline.addVertex(sf::Vector2f(
                    (*point).x - static_cast<float>(std::cos(angle * M_PI / 180.0)) * spline.getThickness(),
                    (*point).y - static_cast<float>(std::sin(angle * M_PI / 180.0)) * spline.getThickness()));
        } else if (extendLast) {
            float angle = angleBetweenTwoPoints(secondLastVertex, *point);
            spline.addVertex(sf::Vector2f(
                    (*point).x + static_cast<float>(std::cos(angle * M_PI / 180.0)) * spline.getThickness(),
                    (*point).y + static_cast<float>(std::sin(angle * M_PI / 180.0)) * spline.getThickness()));
            break;
        } else {
            spline.addVertex(*point);
        }
        if (std::next(point, 2) == turningPoints.end()) {
            secondLastVertex = *point;
            extendLast = true;
        }
        point = std::next(point, 1);
    }
    auto lastHitBox = turningPoints.begin();
    auto hitboxPoint = std::next(lastHitBox, 1);
    while (hitboxPoint != turningPoints.end()) {
        sf::RectangleShape lineSeg = sf::RectangleShape(
                sf::Vector2f(distBetweenTwoPoints(*lastHitBox, *hitboxPoint), screenSize.x / 1200.0f));
        lineSeg.setOrigin(0, lineSeg.getLocalBounds().height/2);
        lineSeg.setRotation(angleBetweenTwoPoints(*lastHitBox, *hitboxPoint));
        lineSeg.setPosition((*lastHitBox).x, (*lastHitBox).y);
        trackHitboxes.push_back(lineSeg);
        hitboxPoint++;
        lastHitBox++;
    }
    spline.update();
}

MapIterator Map::begin() const {
    return turningPoints.begin();
}

MapIterator Map::end() const {
    return turningPoints.end();
}

void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(spline, states);
}

std::vector<sf::RectangleShape> Map::getTrackHitBoxes() const{
    return trackHitboxes;

}
