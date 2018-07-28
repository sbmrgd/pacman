#pragma once
/*
Copyright 2018 sbmrgd

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

*/

#include <Pokitto.h>
#include <vector>
#include "entity.h"
#include "tiles.h"
#include "Vector2.h"
enum class GameState
{
    TitleScreen,
    GamePlay
};


class Game
{
    private:
    GameState gamestate;
    Entity letter_P {letters_pal,letters[0]};
    Entity letter_A {letters_pal,letters[1]};
    Entity letter_C {letters_pal,letters[2]};
    Entity letter_M {letters_pal,letters[3]};
    Entity letter_A2 {letters_pal,letters[1]};
    Entity letter_N {letters_pal,letters[4]};
    Entity pacman {pacman_pal,pacman_sprite[1],{20,20}};
    std::vector<Entity> entities;
    void showTitleScreen()
    {

        for(std::size_t index = 0;index<entities.size()-1;++index)
            {
                Pokitto::Display::setSpriteBitmap(index,entities[index].bitmap,entities[index].palette,Pokitto::Display::getWidth()/2+(index-3)*18,Pokitto::Display::getHeight()/2-8);
            }
        Pokitto::Display::setSpriteBitmap(6,entities[6].bitmap,entities[6].palette,entities[6].position.x,entities[6].position.y);
    }
    void update()
    {
        switch(this->gamestate)
        {
        case GameState::TitleScreen:
            this->showTitleScreen();
            break;
        case GameState::GamePlay:
            break;
        }
    }

    public:
    void begin()
    {
        Pokitto::Core::begin();
        Pokitto::Core::setFrameRate(255);
        entities.push_back(letter_P);
        entities.push_back(letter_A);
        entities.push_back(letter_C);
        entities.push_back(letter_M);
        entities.push_back(letter_A2);
        entities.push_back(letter_N);
        entities.push_back(pacman);
    }
    void run()
    {
        while (Pokitto::Core::isRunning())
        {
            if (Pokitto::Core::update())
            {
                this->update();
            }
        }
    }
};
