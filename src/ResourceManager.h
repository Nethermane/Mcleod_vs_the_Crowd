//
// Created by Bruce on 2019-11-04.
//

#ifndef FIGHTCLUB_RESOURCEMANAGER_H
#define FIGHTCLUB_RESOURCEMANAGER_H


#include <map>
#include <SFML/Graphics/Texture.hpp>
#include <memory>
#include <SFML/Graphics/Font.hpp>

enum ResourceIdentifier
{
    enemy_1,
    enemy_2,
    enemy_3,
    enemy_4,
    enemy_5,
    HealthA,
    HealthB,
    HealthC,
    HealthF,
    apex,
    mcleod,
    sound,
    pause,
    mute,
    options
};

class ResourceManager
{
private:
    std::map<ResourceIdentifier, std::shared_ptr<sf::Texture>> m_Textures;
    std::map<ResourceIdentifier, std::shared_ptr<sf::Font>> m_Fonts;
public:
    ResourceManager();
    std::shared_ptr<sf::Texture> LoadTexture(ResourceIdentifier id, const std::string& file);
    std::shared_ptr<sf::Font> LoadFont(ResourceIdentifier id, const std::string& file);

    std::shared_ptr<sf::Texture> GetTexture(ResourceIdentifier id) const;
    std::shared_ptr<sf::Font> GetFont(ResourceIdentifier id) const;

};


#endif //FIGHTCLUB_RESOURCEMANAGER_H
