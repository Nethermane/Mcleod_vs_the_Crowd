//
// Created by Bruce on 2019-11-06.
//

#include <cmath>
#include "MathHelpers.h"

float angleBetweenTwoPoints(sf::Vector2f origin, sf::Vector2f target) {
    return static_cast<float>(std::atan2(target.y - origin.y, target.x - origin.x) * 180 / M_PI);
}

float distBetweenTwoPoints(sf::Vector2f first, sf::Vector2f second) {
    return static_cast<float>(std::sqrt(std::pow(second.x - first.x, 2) +
                                        std::pow(second.y - first.y, 2)));
}

/**
 * Pythagorean theorem
 * @param fromX
 * @param fromY
 * @param toX
 * @param toY
 */
double findDistance(double fromX, double fromY, double toX, double toY){
    double a = std::abs(fromX - toX);
    double b = std::abs(fromY - toY);

    return std::sqrt((a * a) + (b * b));
}
