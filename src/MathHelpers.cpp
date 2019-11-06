//
// Created by Bruce on 2019-11-06.
//

#include <cmath>
#include "MathHelpers.h"
float angleBetweenTwoPoints(sf::Vector2f origin, sf::Vector2f target) {
    return static_cast<float>(std::atan2(target.y - origin.y, target.x - origin.x) * 180 / M_PI);
}
