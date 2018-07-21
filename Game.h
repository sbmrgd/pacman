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
#include "entity.h"
#include "tiles.h"
enum class GameState
{
    TitleScreen,
    GamePlay
};


class Game
{
    private:
    GameState gamestate;
    Entity pacman {pacman_pal,pacman_sprite[0]};
    void showTitleScreen()
    {
        Pokitto::Display::println("Title Screen");
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
        Pokitto::Display::setSpriteBitmap(0, this->pacman.bitmap, this->pacman.palette,10,20);
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
