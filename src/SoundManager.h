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
        void resume();
        void stop();
        void mute();
        void unMute();
    private:
        sf::Music music;
        float volume{100};

};

#endif //FIGHTCLUB_SOUNDMANAGER_H