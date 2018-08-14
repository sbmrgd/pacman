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
#include "tiles.h"
#include "entity.h"
#include "Vector2.h"
#include "KeyboardController.h"
#include "LetterControllers.h"
enum class GameState
{
    TitleScreen,
    GamePlay
};


class Game
{
    private:
    GameState gamestate;
    KeyboardController keyboardcontroller;
    LetterController letter_P_controller{-4};
    LetterController letter_A_controller{+4};
    LetterController letter_C_controller{-4};
    LetterController letter_M_controller{+4};
    LetterController letter_A2_controller{-4};
    LetterController letter_N_controller{+4};

    //Entity letter_P {letters_pal,letters[0],Pokitto::Display::getWidth()/2-3*18,Pokitto::Display::getHeight()/2-8+2,0,0,400, letter_P_controller};
    //Entity letter_A {letters_pal,letters[1],Pokitto::Display::getWidth()/2-2*18,Pokitto::Display::getHeight()/2-8-2,0,0,400, letter_A_controller};
    //Entity letter_C {letters_pal,letters[2],Pokitto::Display::getWidth()/2-1*18,Pokitto::Display::getHeight()/2-8+2,0,0,400, letter_C_controller};
    //Entity letter_M {letters_pal,letters[3],Pokitto::Display::getWidth()/2-0*18,Pokitto::Display::getHeight()/2-8-2,0,0,400, letter_M_controller};
    //Entity letter_A2 {letters_pal,letters[1],Pokitto::Display::getWidth()/2+1*18,Pokitto::Display::getHeight()/2-8+2,0,0,400, letter_A2_controller};
    //Entity letter_N {letters_pal,letters[4],Pokitto::Display::getWidth()/2+2*18,Pokitto::Display::getHeight()/2-8-2,0,0,400, letter_N_controller};
    //Entity pacman {pacman_pal,pacman_sprite[1],20,20,1,0,20, keyboardcontroller};
    std::vector<Entity> entities;

    void showTitleScreen()
    {

        for(std::size_t index = 0;index<entities.size();++index)
            {
                entities[index].update();
                Pokitto::Display::setSpriteBitmap(index,entities[index].bitmap,entities[index].palette,entities[index].position.x,entities[index].position.y);
            }

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
        entities.emplace_back(Entity{letters_pal,letters[0],Pokitto::Display::getWidth()/2-3*18,Pokitto::Display::getHeight()/2-8+2,0,0,400, letter_P_controller});
        entities.emplace_back(Entity{letters_pal,letters[1],Pokitto::Display::getWidth()/2-2*18,Pokitto::Display::getHeight()/2-8-2,0,0,400, letter_A_controller});
        entities.emplace_back(Entity{letters_pal,letters[2],Pokitto::Display::getWidth()/2-1*18,Pokitto::Display::getHeight()/2-8+2,0,0,400, letter_C_controller});
        entities.emplace_back(Entity{letters_pal,letters[3],Pokitto::Display::getWidth()/2-0*18,Pokitto::Display::getHeight()/2-8-2,0,0,400, letter_M_controller});
        entities.emplace_back(Entity{letters_pal,letters[1],Pokitto::Display::getWidth()/2+1*18,Pokitto::Display::getHeight()/2-8+2,0,0,400, letter_A2_controller});
        entities.emplace_back(Entity{letters_pal,letters[4],Pokitto::Display::getWidth()/2+2*18,Pokitto::Display::getHeight()/2-8-2,0,0,400, letter_N_controller});
        entities.emplace_back(Entity{pacman_pal,pacman_sprite[1],20,20,1,0,20, keyboardcontroller});
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
