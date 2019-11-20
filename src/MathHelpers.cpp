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
bool intersectsCircle(const sf::CircleShape &circle, const sf::FloatRect &rect)
{

    float circleDistanceX = std::abs(circle.getPosition().x - rect.left);
    float circleDistanceY = std::abs(circle.getPosition().y - rect.top);

    if (circleDistanceX > (rect.width/2 + circle.getRadius())) { return false; }
    if (circleDistanceY > (rect.height/2 + circle.getRadius())) { return false; }

    if (circleDistanceX <= (rect.width/2)) { return true; }
    if (circleDistanceY <= (rect.height/2)) { return true; }

    double cornerDistance_sq = std::pow(circleDistanceX - rect.width/2, 2) + std::pow(circleDistanceY - rect.height/2,2);

    return (cornerDistance_sq <= std::pow(circle.getRadius(),2));
}