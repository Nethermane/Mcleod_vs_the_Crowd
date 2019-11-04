//
// Created by Bruce on 2019-11-04.
//

#ifndef FIGHTCLUB_RESOURCEMANAGER_H
#define FIGHTCLUB_RESOURCEMANAGER_H


#include <map>
#include <SFML/Graphics/Texture.hpp>
#include <memory>
#include <string.h>

enum ResourceIdentifier
{
    enemy,
    FireAnimation,
    SmokeAnimation,
    FloorTile,
};

class ResourceManager
{
private:
    std::map<ResourceIdentifier, std::shared_ptr<sf::Texture>> m_Textures;
public:
    ResourceManager();
    std::shared_ptr<sf::Texture> LoadTexture(ResourceIdentifier id, const std::string& file);

    std::shared_ptr<sf::Texture> GetTexture(ResourceIdentifier id) const;
};


#endif //FIGHTCLUB_RESOURCEMANAGER_H
