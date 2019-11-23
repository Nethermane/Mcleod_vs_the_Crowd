//
// Created by Bruce on 2019-10-12.
//

#ifndef FIGHTCLUB_TOWER_H
#define FIGHTCLUB_TOWER_H


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics.hpp>
#include <forward_list>
#include <SFML/Graphics/Texture.hpp>
#include <memory>
#include "Upgrade.h"
#include "Enemy.h"
#include <functional>

enum class TowerType {
    Tower1 = constants::tower1Cost,
    Tower2 = constants::tower2Cost,
    Tower3 = constants::tower3Cost,
    Tower4 = constants::tower4Cost,
    None = 0
};

typedef sf::IntRect *srcPtrArray;


class Tower : sf::Drawable {
public:


    //Tower(const sf::Vector2f position, sf::Texture*texture, towerType type, int damage, int range);
    Tower(const std::shared_ptr<sf::Texture> &texture, const sf::Vector2f &position,
          std::forward_list<Upgrade>::const_iterator nextUpgrade,
          std::forward_list<Upgrade>::const_iterator upgradeEnd, const TowerType& towerType);

    ///Returns true if tower has another upgrade available
    bool canUpgrade() const;

    sf::Vector2f getPosition() const;


    ///Fires and aims if the tower cooldown has been surpassed
    void update(float delta, const std::vector<Enemy> &enemies, const std::function<void(Tower, Enemy, float)> &f);

    ///Renders the tower in it's current direction
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    ///Upgrades the tower,
    void upgrade();

    ///Returns the cost to upgrade the tower
    int getUpgradeCost() const;

    float getRange() const;

    float getNextRange() const;


    TowerType getTowerType() const;


    int getDamage() const;

    float getProjectileSpeed() const;

    sf::CircleShape getHitBox() const;

private:
    int rotation, lastAttack, cost, level, damage;
    float timeSinceLastAttack, attackDelay, range, projectileSpeed;
    sf::CircleShape hitBox;
    const TowerType towerType;


    friend class Upgrade;

    std::forward_list<Upgrade>::const_iterator nextUpgrade;
    std::forward_list<Upgrade>::const_iterator upgradeEnd;
    std::vector<float> position; // tower position

    sf::Sprite towerSprite;
    sf::Vector2f towerPosition;
    TowerType type;


};


#endif //FIGHTCLUB_TOWER_H
