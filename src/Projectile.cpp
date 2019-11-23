#include <utility>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <cmath>

//
// Created by Bruce on 2019-10-12.
//

#include "Projectile.h"
#include "RectangularBoundaryCollision.h"
#include "Enemy.h"


Projectile::Projectile(float spd, int dmg, float ang, sf::Vector2f pos,
                       const std::shared_ptr<sf::Texture> &texture, const sf::FloatRect &bnds) : angle(ang),
                                                                                                 bounds(bnds) {
    sprite.setTexture(*texture);
    sprite.setScale(0.2f,0.2f);
    speed = spd;
    damage = dmg;
    deletable = false;
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
    sprite.setPosition(pos);
    sprite.setRotation(angle);
    x_angle = static_cast<float>(std::cos(sprite.getRotation() * M_PI / 180.0));
    y_angle = static_cast<float>(std::sin(sprite.getRotation() * M_PI / 180.0));
}


bool Projectile::isDeletable() {
    return deletable;
}

float Projectile::getSpeed() {
    return speed;
}

int Projectile::getDamage() {
    return damage;
}

sf::Vector2f Projectile::getPosition() {
    return sprite.getPosition();
}

void Projectile::update(float delta, std::vector<Enemy> &enemies) {
    if (!deletable) {
        for (auto &enemy : enemies) {
            if (collision::areColliding(enemy.getHitBox(),sprite)) {
                enemy.hit(damage);
                deletable = true;
                return;
            }
        }
        sprite.move(x_angle * speed * delta, y_angle * speed * delta);
        sf::Vector2f position = sprite.getPosition();
        if (position.x < bounds.left || position.x > bounds.left + bounds.width || position.y < bounds.top ||
            position.y > bounds.top + bounds.height)
            deletable = true;
    }
}

void Projectile::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

