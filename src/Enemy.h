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
    float speed, timeOnCurrentPath, timeTillNextPath;
    const sf::Texture texture;
    float x_angle, y_angle;
    sf::Sprite sprite;
    MapIterator currentTarget;
    const MapIterator trackEnd;
    bool hitEnd = false;
    void startNewMovePath();
public:
    int getHealth() const;

    float getSpeed() const;

    int getDamage() const;

    int getReward() const;

    sf::Vector2f getPosition();

    void hit(int damage);

public:
    void update(float delta);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    Enemy(MapIterator trackStart, MapIterator trackEnd, const sf::Texture &texture);

};


#endif //FIGHTCLUB_ENEMY_H
