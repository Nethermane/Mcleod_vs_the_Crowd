#include <utility>

//
// Created by jason on 10/31/19.
//

#include <SFML/Audio.hpp>
#include "SoundManager.h"
#include <string>

SoundManager::SoundManager() {
    this->music.setLoop(true);
}

int SoundManager::play(std::string filename){
    if(!this->music.openFromFile((filename))){
        return -1;
    }
    this->music.play();
    return 1;
};

void SoundManager::start() {
    this->music.play();
}

void SoundManager::pause() {
    this->music.pause();
}
void SoundManager::resume() {
    this->music.play();
}

void SoundManager::stop() {
    this->music.stop();
}

int SoundManager::change(std::string filename) {
    this->stop();
    this->play(std::move(filename));
    return 1;
}
