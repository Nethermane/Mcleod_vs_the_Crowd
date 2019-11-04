#include <utility>

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

void Enemy::update(float delta) {
    if (hitEnd)
        return;
    timeOnCurrentPath += delta;
    if (timeOnCurrentPath > timeTillNextPath)
        startNewMovePath(false);
    else
        sprite.move(x_angle * speed * delta, y_angle * speed * delta);
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
             std::shared_ptr<sf::Texture> texture, int health, int damage, int reward, float speed)
        : currentTarget(trackStart), trackEnd(trackEnd),
          timeOnCurrentPath(0), timeTillNextPath(0), health(health), damage(damage),reward(reward),speed(speed), texture(texture) {
    sprite = sf::Sprite(*(this->texture));
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
    startNewMovePath(true);
}

void Enemy::startNewMovePath(const bool starting) {
    sf::Vector2f first = (*currentTarget);
    currentTarget = std::next(currentTarget, 1);
    if (currentTarget == trackEnd) {
        hitEnd = true;
        return;
    }
    sf::Vector2f second = (*currentTarget);

    sprite.setRotation(angleBetweenTwoPoints(first, second));
    x_angle = static_cast<float>(std::cos(sprite.getRotation() * M_PI / 180.0));
    y_angle = static_cast<float>(std::sin(sprite.getRotation() * M_PI / 180.0));
    if(std::next(currentTarget, 1) == trackEnd) {
        second.x += x_angle * sprite.getGlobalBounds().width;
        second.y += y_angle * sprite.getGlobalBounds().width;
    }
    if(starting) {
        first.x -= x_angle * sprite.getGlobalBounds().width;
        first.y -= y_angle * sprite.getGlobalBounds().width;
    }
    sprite.setPosition(first.x, first.y);
    timeOnCurrentPath -= timeTillNextPath;
    //Extra movement around corner that may have been lost to lag
    sprite.move(x_angle * speed * timeOnCurrentPath, y_angle * speed * timeOnCurrentPath);
    //Set time till next turn
    timeTillNextPath = static_cast<float>(std::sqrt(std::pow(second.x - first.x, 2) +
                                                    std::pow(second.y - first.y, 2)) / speed) - timeOnCurrentPath;
    timeOnCurrentPath = 0;
}

bool Enemy::hasHitEnd() {
    return hitEnd;
}

Enemy &Enemy::operator=(const Enemy &other) {
    health = other.health;
    damage = other.damage;
    reward = other.reward;
    speed = other.speed;
    timeOnCurrentPath = other.timeOnCurrentPath;
    timeTillNextPath = other.timeTillNextPath;
    texture = other.texture;
    x_angle = other.x_angle;
    y_angle = other.y_angle;
    sprite = other.sprite;
    currentTarget = other.currentTarget;
    trackEnd = other.trackEnd;
    hitEnd = other.hitEnd;
    return *this;
}
