#include <iostream>


#include "GameManager.h"

int main() {
    sf::RenderWindow window;
    window.create(sf::VideoMode::getDesktopMode(), "McLeod vs. The Crowd", sf::Style::None);
    window.setKeyRepeatEnabled(false);
    window.setFramerateLimit(0);
    GameManager game(window);
    return 0;
}