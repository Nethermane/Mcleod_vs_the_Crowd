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
    int health, damage, reward;
    float speed, timeOnCurrentPath, timeTillNextPath;
    sf::Texture texture;
    float x_angle, y_angle;
    sf::Sprite sprite;
    MapIterator currentTarget;
    MapIterator trackEnd;
    bool hitEnd = false;
    void startNewMovePath();
public:
    int getHealth() const;

    float getSpeed() const;

    int getDamage() const;

    int getReward() const;

    void hit(int damage);
    bool hasHitEnd();
    Enemy& operator=(const Enemy& other);

public:
    void update(float delta);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    Enemy(MapIterator trackStart, MapIterator trackEnd, const sf::Texture &texture, int health, int damage, int reward);

};


#endif //FIGHTCLUB_ENEMY_H
