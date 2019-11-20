//
// Created by Bruce on 2019-10-12.
//

#ifndef FIGHTCLUB_ENEMY_H
#define FIGHTCLUB_ENEMY_H


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Common.h"
#include <memory>

///Class to represent enemies
///Movement, rendering, and death are all handled inside this class
class Enemy : sf::Drawable {
    ///Class to represent the health bar of enemies
    class HealthBar: sf::Drawable {
    private:
        //So enemy can use hit function
        friend class Enemy;
        int health, max, sections;
        int oldSection{-1};
        sf::Sprite sprite;
        std::vector<std::shared_ptr<sf::Texture>> textures;
        void updateGraphic();
        void hit(int damage);
        void update(const sf::Sprite& toFollow);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    public:
        HealthBar(int healthMax, std::vector<std::shared_ptr<sf::Texture>> &textures);

        int getHealth() const;

        int getMaxHealth() const;
    };
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

    ///Starts path or turns at turning point
    ///Updates the hit end variable
    ///@param starting Bool variable true if just starting path
    void startNewMovePath(bool starting);

    float getSpeed() const;

    int getDamage() const;

    int getReward() const;


    sf::Vector2f getPosition();

    ///Apply damage to an enemy
    ///@param damage amount of damage to apply to enemy
    void hit(int damage);


    bool hasHitEnd() const;

    bool isDamaged() const;

    ///Render health bar for enemy
    void drawHealthBar(sf::RenderTarget &target, sf::RenderStates states) const;


public:
    ///Moves the enemy if it hasn't hit and is alive
    void update(float delta);

    ///Renders the enemy if it hasn't hit the end and is alive.
    ///Doesn't render health bar, render @healthBar after all enemies have been rendered
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    Enemy(MapIterator trackStart, MapIterator trackEnd, std::shared_ptr<sf::Texture> texture,
          std::vector<std::shared_ptr<sf::Texture>> &healthBarTextures,
          int health, int damage, int reward, float speed);

};


#endif //FIGHTCLUB_ENEMY_H
