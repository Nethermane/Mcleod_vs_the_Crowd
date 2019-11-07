//
// Created by Bruce on 2019-10-12.
//

#ifndef FIGHTCLUB_ENEMY_H
#define FIGHTCLUB_ENEMY_H


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Common.h"
#include "HealthBar.h"
#include <memory>

class Enemy : sf::Drawable {
private:
    int damage, reward;
    float speed, timeOnCurrentPath, timeTillNextPath;
    std::shared_ptr<sf::Texture> texture;
    float x_angle, y_angle;
    HealthBar healthBar;
public:
    int getHealth() const;

    sf::Sprite sprite;
    MapIterator currentTarget;
    MapIterator trackEnd;
    bool hitEnd = false;

    void startNewMovePath(bool starting);

    float getSpeed() const;

    int getDamage() const;

    int getReward() const;

    void hit(int damage);

    bool hasHitEnd() const;

    bool isDamaged() const;

    HealthBar getHealthBar() const;


public:
    void update(float delta);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    Enemy(MapIterator trackStart, MapIterator trackEnd, std::shared_ptr<sf::Texture> texture, std::vector<std::shared_ptr<sf::Texture>> &healthBarTextures,
          int health, int damage, int reward, float speed);

};


#endif //FIGHTCLUB_ENEMY_H
