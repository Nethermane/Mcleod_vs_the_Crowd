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
    int health{}, damage{}, reward{};
    float speed;
    const sf::Texture texture;
    sf::Sprite sprite;
    MapIterator currentTarget;
    const MapIterator trackEnd;
    long long int timeOnCurrentPath{};
    long long int timeTillNextPath{};
    bool hitEnd = false;
public:
    int getHealth() const;

    float getSpeed() const;

    int getDamage() const;

    int getReward() const;

    void hit(int damage);

public:
    void update(long long int delta);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    Enemy(MapIterator trackStart, MapIterator trackEnd, const sf::Texture &texture);

};


#endif //FIGHTCLUB_ENEMY_H
