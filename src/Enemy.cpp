//
// Created by Bruce on 2019-10-12.
//

#include "Enemy.h"

void Enemy::update(int delta) {
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

Enemy::Enemy() {

}

void Enemy::hit(const int damage) {

}
