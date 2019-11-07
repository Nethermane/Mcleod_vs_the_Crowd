#include <utility>

//
// Created by Bruce on 2019-10-12.
//

#include <cmath>
#include <SFML/Graphics/RenderTarget.hpp>
#include <iostream>
#include "Enemy.h"
#include "MathHelpers.h"


int Enemy::HealthBar::getHealth() const {
    return health;
}

Enemy::HealthBar::HealthBar(const int healthMax,
                     std::vector<std::shared_ptr<sf::Texture>> &textures) : textures(textures),
                                                                            health(healthMax),
                                                                            max(healthMax),
                                                                            sections(static_cast<int>(textures.size())),
                                                                            oldSection(100) {
    updateGraphic();
}

void Enemy::HealthBar::updateGraphic() {
    int pcnt = health * 100 / max;
    int sectionAmount = 100 / sections;
    int currSection = oldSection;
    for (int i = sections - 1; i >= 0; i--) {
        if (pcnt > i * sectionAmount) {
            currSection = i;
            break;
        }
    }
    if (currSection != oldSection) {
        sprite.setTexture(*(textures.at(static_cast<unsigned long long int>(currSection))));
        sprite.setScale(0.2, 0.2);
        sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
    }
    oldSection = currSection;
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter"

void Enemy::HealthBar::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sprite);
}

#pragma clang diagnostic pop

void Enemy::HealthBar::hit(int damage) {
    health -= damage;
    updateGraphic();
}


void Enemy::HealthBar::update(const sf::Sprite &toFollow) {
    sprite.setPosition(toFollow.getPosition().x - sprite.getGlobalBounds().width / 2,
                       toFollow.getPosition().y - toFollow.getGlobalBounds().height / 2 -
                       sprite.getGlobalBounds().height);
}

int Enemy::HealthBar::getMaxHealth() const {
    return max;
}


void Enemy::update(float delta) {
    if (hitEnd || getHealth() <= 0)
        return;
    timeOnCurrentPath += delta;
    if (timeOnCurrentPath > timeTillNextPath)
        startNewMovePath(false);
    else
        sprite.move(x_angle * speed * delta, y_angle * speed * delta);
    healthBar.update(sprite);
}

void Enemy::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (hitEnd || getHealth() <= 0)
        return;
    target.draw(sprite);
}


int Enemy::getHealth() const {
    return healthBar.getHealth();
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
    healthBar.hit(damage);
}

Enemy::Enemy(MapIterator trackStart,
             MapIterator trackEnd,
             std::shared_ptr<sf::Texture> texture,
             std::vector<std::shared_ptr<sf::Texture>> &healthBarTextures,
             int health, int damage, int reward, float speed)
        : currentTarget(trackStart), trackEnd(trackEnd),
          timeOnCurrentPath(0), timeTillNextPath(0), healthBar(health, healthBarTextures), damage(damage),
          reward(reward), speed(speed), texture(
                std::move(texture)) {
    sprite.setScale(0.3, 0.3);
    sprite.setTexture(*this->texture);
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    startNewMovePath(true);
}

void Enemy::startNewMovePath(const bool starting) {
    while (timeOnCurrentPath >= timeTillNextPath) {
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
        if (std::next(currentTarget, 1) == trackEnd) {
            second.x += x_angle * sprite.getLocalBounds().width;
            second.y += y_angle * sprite.getLocalBounds().width;
        }
        if (starting) {
            first.x -= x_angle * sprite.getLocalBounds().width / 2;
            first.y -= y_angle * sprite.getLocalBounds().width / 2;
        }
        sprite.setPosition(first.x, first.y);
        timeOnCurrentPath -= timeTillNextPath;
        //Extra movement around corner that may have been lost to lag
        sprite.move(x_angle * speed * timeOnCurrentPath, y_angle * speed * timeOnCurrentPath);
        //Set time till next turn
        timeTillNextPath = static_cast<float>(std::sqrt(std::pow(second.x - first.x, 2) +
                                                        std::pow(second.y - first.y, 2)) / speed) - timeOnCurrentPath;
    }
    timeOnCurrentPath = 0;
}

bool Enemy::hasHitEnd() const {
    return hitEnd;
}

void Enemy::drawHealthBar(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(healthBar);
}

bool Enemy::isDamaged() const {
    return healthBar.getHealth() < healthBar.getMaxHealth();
}
