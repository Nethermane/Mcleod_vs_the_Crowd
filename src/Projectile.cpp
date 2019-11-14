#include <utility>
#include <cmath>
#include <SFML/Graphics/RenderTarget.hpp>

//
// Created by Bruce on 2019-10-12.
//

#include "Projectile.h"


Projectile::Projectile(int spd, int dmg, float ang, sf::Vector2f pos,
        sf::Texture& text, sf::FloatRect& bnds):
         sprite(text), angle(ang), bounds(bnds) {
    speed = spd;
    damage = dmg;
    deletable = false;
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
    sprite.setPosition(pos.x,pos.y);
    sprite.setRotation(angle);
}


bool Projectile::isDeletable(){
    sf::Vector2f position = sprite.getPosition();
    if (position.x < bounds.left ||  position.x > bounds.left + bounds.width || position.y < bounds.top || position.y > bounds.top + bounds.height) {
        deletable = true;
    }
    return deletable;
}

int Projectile::getSpeed(){
    return speed;
}
int Projectile::getDamage(){
    return damage;
}

sf::Vector2f Projectile::getPosition(){
    return sprite.getPosition();
}

void Projectile::update(std::vector<Enemy> &enemies, float delta){
    x_angle = static_cast<float>(std::cos(sprite.getRotation() * M_PI / 180.0));
    y_angle = static_cast<float>(std::sin(sprite.getRotation() * M_PI / 180.0));
    sprite.move(x_angle*speed*delta,y_angle*speed*delta);
    for (int i = 0; i < enemies.size(); i++){
        int enemyX = enemies.at(i).getPosition().x;
        int enemyY = enemies.at(i).getPosition().y;
        if (sprite.getPosition().x < enemyX + 150 && sprite.getPosition().x + 4 > enemyX && sprite.getPosition().y < enemyY + 150 && sprite.getPosition().y + 4 > enemyY){
            enemies.at(i).hit(damage);
            deletable = true;
        }
    }
}

void Projectile::draw(sf::RenderTarget &targt, sf::RenderStates states) const {
    targt.draw(sprite);
}

