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
    sprite.move(static_cast<float>(std::cos(sprite.getRotation() * M_PI / 180.0) * speed * delta/1000),
                static_cast<float>(std::sin(sprite.getRotation() * M_PI / 180.0) * speed * delta/1000));
    std::cout << sprite.getPosition().x << ": " << sprite.getPosition().y << std::endl;
}

void Enemy::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sprite);
}


int Enemy::getHealth() const {
    return health;
}

int Enemy::getSpeed() const {
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
        : currentPos(trackStart), trackEnd(trackEnd), texture(texture), sprite(this->texture), speed(1) {
    sf::Vector2f first = (*currentPos);
    currentPos = std::next(currentPos, 1);
    sf::Vector2f second = (*currentPos);
    sprite.setRotation(angleBetweenTwoPoints(first, second));
    sprite.setPosition(first.x, 300);
    timeOnCurrentPath = 0;
    timeTillNextPath = static_cast<long long int>(std::sqrt(
            std::pow(second.x - first.x, 2) + std::pow(second.y - first.y, 2))) / speed;
}
