//
// Created by Bruce on 2019-10-12.
//

#ifndef FIGHTCLUB_TOWER_H
#define FIGHTCLUB_TOWER_H


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics.hpp>
#include <forward_list>
#include <SFML/Graphics/Texture.hpp>
#include "Upgrade.h"



enum class towerType{
    Tower1, Tower2, Tower3, Tower4
};

typedef sf::IntRect* srcPtrArray;


class Tower : sf::Sprite {
public:
    Tower(const std::vector<float>);
    ///Returns true if tower has another upgrade available

    //Tower(const sf::Vector2f position, sf::Texture*texture, towerType type, int damage, int range);
    Tower(sf::Texture* Texture, const sf::Vector2f position, towerType type, int damage, int range, sf::Vector2f size);

    void Shoot();
    void StopShooting();
    ~Tower();


    bool canUpgrade() const;
    sf::Sprite getTowerSprite() const;
    sf::Vector2f getTowerPosition() const;
    void setPosition(sf::Vector2f position);
    float getRange() const;
    float getDamage() const;
    char getMode() const;
    void setDirection(char);
    void click();
    void setMode(char);
    char getDirection() const;
    towerType getTowerType();
    sf::Vector2f getPosition() const;
    void render(sf::RenderWindow& window);

    float towerDamage;
    float range;

    float studentDistance(sf::Vector2f student); //  returns the distance between the student and the tower
    void studentDirection(sf::Vector2f position); // returns the direction of the student (as seen by the tower)


    ///Upgrades the tower,
    void upgrade();

    int getUpgradeCost() const;
    towerType getTowerType() const;

    bool clicked;
    int upgradePrice;

private:
    int attackSpeed, rotation, lastAttack, cost, level;
    long long int timeSinceLastAttack;

    char direction; // nsew (north south east west)
    char mode; // f = fight, n=  not fight



    friend class Upgrade;

    std::forward_list<Upgrade>::const_iterator nextUpgrade;
    std::forward_list<Upgrade>::const_iterator upgradeEnd;
    std::vector<float> position; // tower position

    sf::Sprite towerSprite;
    sf::Texture towerTexture;
    sf::IntRect sprite;
    sf::Vector2f towerPosition;
    sf::Vector2f towerSize;

    srcPtrArray* srcSprite;
    towerType type;





};



#endif //FIGHTCLUB_TOWER_H
