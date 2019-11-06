#include <iostream>


#include "GameManager.h"

int main() {
    sf::RenderWindow window;
    window.create(sf::VideoMode::getDesktopMode(), "McLeod vs. The Crowd", sf::Style::None, sf::ContextSettings(0,0,16));
    window.setKeyRepeatEnabled(false);
    window.setFramerateLimit(200);
    GameManager game(window);
    return 0;
}