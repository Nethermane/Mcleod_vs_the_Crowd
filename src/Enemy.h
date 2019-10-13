//
// Created by Bruce on 2019-10-12.
//

#ifndef FIGHTCLUB_ENEMY_H
#define FIGHTCLUB_ENEMY_H


#include <SFML/Graphics/Sprite.hpp>

class Enemy : sf::Sprite {
private:
    int health, speed, damage, reward;
    sf::Vector2f *nextPosition;
    long long int timeOnCurrentPath;
    long long int timeTillNextPath;
public:

    int getHealth() const;

    int getSpeed() const;

    int getDamage() const;

    int getReward() const;

    void hit(int damage);
public:
    void update(int delta);
    Enemy();
};


#endif //FIGHTCLUB_ENEMY_H
