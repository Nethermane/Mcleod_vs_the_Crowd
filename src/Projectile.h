//
// Created by Bruce on 2019-10-12.
//

#ifndef FIGHTCLUB_PROJECTILE_H
#define FIGHTCLUB_PROJECTILE_H


#include <vector>
#include "Enemy.h"

class Projectile: sf::Drawable {
private:
    int speed;
    int damage;
    bool deletable;
    sf::FloatRect bounds;
    float angle;
    //sf::Texture texture;
    sf::Sprite sprite;
    float x_angle;
    float y_angle;



public:
    explicit Projectile(int speed, int damage, float angle,
            sf::Vector2f position, sf::Texture &texture, sf::FloatRect& bounds);
    /**
     * Updates the position of a projectile
     * @param delta time since last frame
     */
    void update(std::vector<Enemy> &enemies, float delta);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    bool isDeletable();
    int getSpeed();
    int getDamage();
    sf::Vector2f getPosition();
    //void draw




};


#endif //FIGHTCLUB_PROJECTILE_H
