


#include "GameManager.h"

int main() {
    sf::RenderWindow window;
    //16 is anti aliasing. Makes lines smoother
    window.create(sf::VideoMode::getDesktopMode(), "McLeod vs. The Crowd", sf::Style::None, sf::ContextSettings(0,0,16));
    window.setKeyRepeatEnabled(false);
    window.setFramerateLimit(60);
    GameManager game(window);
    return 0;
}