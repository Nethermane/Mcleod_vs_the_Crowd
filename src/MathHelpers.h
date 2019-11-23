//
// Created by Bruce on 2019-11-06.
//

#ifndef FIGHTCLUB_MATHHELPERS_H
#define FIGHTCLUB_MATHHELPERS_H

#include "Common.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

float angleBetweenTwoPoints(sf::Vector2f origin, sf::Vector2f target);
float distBetweenTwoPoints(sf::Vector2f first, sf::Vector2f second);
#endif //FIGHTCLUB_MATHHELPERS_H
