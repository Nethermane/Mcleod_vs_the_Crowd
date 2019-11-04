//
// Created by jason on 10/31/19.
//

#ifndef FIGHTCLUB_SOUNDMANAGER_H
#define FIGHTCLUB_SOUNDMANAGER_H

#include <SFML/Audio.hpp>
#include <string>

class SoundManager {
    public:
        SoundManager();
        int play(std::string filename);
        int change(std::string filename);
        void start();
        void pause();
        void stop();
    private:
        sf::Music music;

};

#endif //FIGHTCLUB_SOUNDMANAGER_H