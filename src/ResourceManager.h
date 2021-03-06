//
// Created by Bruce on 2019-11-04.
//

#ifndef FIGHTCLUB_RESOURCEMANAGER_H
#define FIGHTCLUB_RESOURCEMANAGER_H


#include <map>
#include <SFML/Graphics/Texture.hpp>
#include <memory>
#include <SFML/Graphics/Font.hpp>

///Enum that allows other classes to get texture pointers simply
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
    sound,
    pause,
    mute,
    options,
    pointer,
    a1,
    a2,
    a3,
    b1,
    b2,
    b3,
    c1,
    c2,
    c3,
    d4,
    mcleod1,
    mcleod2,
    mcleod3,
    mcleod4,
    track,
    projectile
};
///Class which loads resources all and allows others to access them
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
