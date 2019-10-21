#include <iostream>


#include "GameManager.h"

int main() {
    sf::RenderWindow window;
    window.create(sf::VideoMode::getDesktopMode(), "McLeod vs. The Crowd", sf::Style::None);
    // window.setFramerateLimit(60);
    // Enable vertical sync. (vsync)
    window.setVerticalSyncEnabled(true);
    // When a key is pressed, sf::Event::KeyPressed will be true only once
    window.setKeyRepeatEnabled(false);
    GameManager game(window);
    return 0;
}