//
// Created by Bruce on 2019-10-12.
//

#ifndef FIGHTCLUB_ENEMY_H
#define FIGHTCLUB_ENEMY_H


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Common.h"

class Enemy : sf::Drawable {
private:
    int health{}, speed{}, damage{}, reward{};
    const sf::Texture texture;
    sf::Sprite sprite;
    MapIterator currentPos;
    const MapIterator trackEnd;
    long long int timeOnCurrentPath{};
    long long int timeTillNextPath{};
public:
    int getHealth() const;

    int getSpeed() const;

    int getDamage() const;

    int getReward() const;

    void hit(int damage);

public:
    void update(long long int delta);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    Enemy(MapIterator trackStart, MapIterator trackEnd, const sf::Texture &texture);

};


#endif //FIGHTCLUB_ENEMY_H
