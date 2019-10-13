//
// Created by Bruce on 2019-10-12.
//

#include <cmath>
#include <SFML/Graphics/RenderTarget.hpp>
#include <iostream>
#include "Enemy.h"

float angleBetweenTwoPoints(sf::Vector2f origin, sf::Vector2f target) {
    return static_cast<float>(std::atan2(target.y - origin.y, target.x - origin.x) * 180 / M_PI);
}

void Enemy::update(long long int delta) {
    if (hitEnd)
        return;
    timeOnCurrentPath += delta;
    if (timeOnCurrentPath > timeTillNextPath) {
        sf::Vector2f first = (*currentTarget);
        currentTarget = std::next(currentTarget, 1);
        if (currentTarget == trackEnd) {
            hitEnd = true;
            return;
        }
        sf::Vector2f second = (*currentTarget);
        sprite.setRotation(angleBetweenTwoPoints(first, second));
        sprite.setPosition(first.x, first.y);
        timeOnCurrentPath = timeOnCurrentPath - timeTillNextPath;
        sprite.move(
                static_cast<float>(std::cos(sprite.getRotation() * M_PI / 180.0) * speed * timeOnCurrentPath),
                static_cast<float>(std::sin(sprite.getRotation() * M_PI / 180.0) * speed * timeOnCurrentPath));
        //Set time till next turn
        timeTillNextPath = static_cast<long long int>(std::sqrt(
                std::pow(second.x - first.x, 2) +
                std::pow(second.y - first.y, 2)) / speed - timeOnCurrentPath);
        timeOnCurrentPath = 0;

    } else {
        sprite.move(static_cast<float>(std::cos(sprite.getRotation() * M_PI / 180.0) * speed * delta),
                    static_cast<float>(std::sin(sprite.getRotation() * M_PI / 180.0) * speed * delta));
    }
}

void Enemy::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (hitEnd)
        return;
    target.draw(sprite);
}


int Enemy::getHealth() const {
    return health;
}

float Enemy::getSpeed() const {
    return speed;
}

int Enemy::getDamage() const {
    return damage;
}

int Enemy::getReward() const {
    return reward;
}

void Enemy::hit(const int damage) {

}

Enemy::Enemy(MapIterator trackStart,
             MapIterator trackEnd,
             const sf::Texture &texture)
        : currentTarget(trackStart), trackEnd(trackEnd), texture(texture), sprite(this->texture), speed(5) {
    sf::Vector2f first = (*currentTarget);
    currentTarget = std::next(currentTarget, 1);
    sf::Vector2f second = (*currentTarget);
    sprite.setOrigin(sprite.getGlobalBounds().width/2, sprite.getGlobalBounds().height/2);
    sprite.setRotation(angleBetweenTwoPoints(first, second));
    sprite.setPosition(first.x, first.y);
    timeOnCurrentPath = 0;
    timeTillNextPath = static_cast<long long int>(std::sqrt(
            std::pow(second.x - first.x, 2) +
            std::pow(second.y - first.y, 2)) / speed);
}
