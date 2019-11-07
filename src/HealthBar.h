//
// Created by Bruce on 2019-11-04.
//

#ifndef FIGHTCLUB_HEALTHBAR_H
#define FIGHTCLUB_HEALTHBAR_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <memory>

class HealthBar: sf::Drawable {
private:
    int health, max, sections;
    int oldSection{-1};
    sf::Sprite sprite;
    std::vector<std::shared_ptr<sf::Texture>> textures;
    void updateGraphic();
public:
    HealthBar(int healthMax, std::vector<std::shared_ptr<sf::Texture>> &textures);
    void hit(int damage);
    void update(const sf::Sprite& toFollow);
    int getHealth() const;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    int getMaxHealth() const;
};


#endif //FIGHTCLUB_HEALTHBAR_H
