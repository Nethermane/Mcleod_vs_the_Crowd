//
// Created by Bruce on 2019-10-12.
//

#ifndef FIGHTCLUB_MAP_H
#define FIGHTCLUB_MAP_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "Enemy.h"
#include "SelbaWard/Spline.hpp"
/**
 * The Map object represents the path which enemies take
 *
 */
class Map : sf::Drawable{
private:
    std::forward_list<sf::Vector2f> turningPoints;
    sw::Spline spline;
public:
    bool isTowerPositionValid(float x, float y) const;
    bool isTowerPositionValid(sf::Vector2f position) const;
    MapIterator begin() const;
    MapIterator end() const;
public:
    explicit Map(const sf::Vector2u &screenSize, const float &percentScreenTake);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif //FIGHTCLUB_MAP_H
