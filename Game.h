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
#include "SimpleRenderer.h"
#include "DirectionalRenderer.h"
enum class GameState
{
    TitleScreen,
    GamePlay
};


class Game
{
    private:
    GameState gamestate;
    KeyboardController keyboardController;
    LetterController letterControllerEven{-4};
    LetterController letterControllerOdd{4};
    SimpleRenderer ghostRenderer;
    DirectionalRenderer pacmanRenderer;
    /*LetterController letter_C_controller{-4};
    LetterController letter_M_controller{+4};
    LetterController letter_A2_controller{-4};
    LetterController letter_N_controller{+4};*/

    //Entity letter_P {letters_pal,letters[0],Pokitto::Display::getWidth()/2-3*18,Pokitto::Display::getHeight()/2-8+2,0,0,400, letter_P_controller};
    //Entity letter_A {letters_pal,letters[1],Pokitto::Display::getWidth()/2-2*18,Pokitto::Display::getHeight()/2-8-2,0,0,400, letter_A_controller};
    //Entity letter_C {letters_pal,letters[2],Pokitto::Display::getWidth()/2-1*18,Pokitto::Display::getHeight()/2-8+2,0,0,400, letter_C_controller};
    //Entity letter_M {letters_pal,letters[3],Pokitto::Display::getWidth()/2-0*18,Pokitto::Display::getHeight()/2-8-2,0,0,400, letter_M_controller};
    //Entity letter_A2 {letters_pal,letters[1],Pokitto::Display::getWidth()/2+1*18,Pokitto::Display::getHeight()/2-8+2,0,0,400, letter_A2_controller};
    //Entity letter_N {letters_pal,letters[4],Pokitto::Display::getWidth()/2+2*18,Pokitto::Display::getHeight()/2-8-2,0,0,400, letter_N_controller};
    //Entity pacman {pacman_pal,pacman_sprite[1],20,20,1,0,20, keyboardcontroller};
    std::vector<Entity> entities;
    std::vector<EntityController*> controllers;
    std::vector<EntityRenderer*> renderers;

    void showTitleScreen()
    {
        //letterControllerEven.update();
        //letterControllerOdd.update();
        //for(std::size_t index = 0;index<entities.size();++index)
        for(auto & controller : controllers)
        {
            (*controller).update();
        }
        for(auto & entity : entities)
        {
                entity.update();
        }
        for(auto & renderer : renderers)
        {
            (*renderer).update();
        }
        /*ghostRenderer.update();
        pacmanRenderer.update();*/
        for(auto & entity : entities)
        {
                entity.render();
        }
        for(std::size_t index = 0;index<entities.size();++index)
        {
                Pokitto::Display::setSpriteBitmap(index,entities[index].bitmap,entities[index].palette,entities[index].position.x,entities[index].position.y);
        }
        Pokitto::Display::setFont(fontKoubit);
        Pokitto::Display::setCursor(Pokitto::Display::getWidth()/2-6*Pokitto::Display::fontWidth,Pokitto::Display::getHeight()-Pokitto::Display::fontHeight-10);
        Pokitto::Display::println("Press C to start");
        if (Pokitto::Buttons::pressed(BTN_C)) gamestate = GameState::GamePlay;
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

        controllers.push_back(&letterControllerEven);
        controllers.push_back(&letterControllerOdd);
        controllers.push_back(&keyboardController);

        renderers.push_back(&ghostRenderer);
        renderers.push_back(&pacmanRenderer);

        entities.emplace_back(letters_pal,letters[0],(int16_t)(Pokitto::Display::getWidth()/2-3*18),(int16_t)(Pokitto::Display::getHeight()/2-8+2),0,0,400, letterControllerEven);
        entities.emplace_back(letters_pal,letters[1],(int16_t)(Pokitto::Display::getWidth()/2-2*18),(int16_t)(Pokitto::Display::getHeight()/2-8-2),0,0,400, letterControllerOdd);
        entities.emplace_back(letters_pal,letters[2],(int16_t)(Pokitto::Display::getWidth()/2-1*18),(int16_t)(Pokitto::Display::getHeight()/2-8+2),0,0,400, letterControllerEven);
        entities.emplace_back(letters_pal,letters[3],(int16_t)(Pokitto::Display::getWidth()/2-0*18),(int16_t)(Pokitto::Display::getHeight()/2-8-2),0,0,400, letterControllerOdd);
        entities.emplace_back(letters_pal,letters[1],(int16_t)(Pokitto::Display::getWidth()/2+1*18),(int16_t)(Pokitto::Display::getHeight()/2-8+2),0,0,400, letterControllerEven);
        entities.emplace_back(letters_pal,letters[4],(int16_t)(Pokitto::Display::getWidth()/2+2*18),(int16_t)(Pokitto::Display::getHeight()/2-8-2),0,0,400, letterControllerOdd);
        entities.emplace_back(pacman_pal,pacman_sprite[0],20,20,1,0,20, keyboardController, pacmanRenderer);
        entities.emplace_back(ghost_blinky_pal,ghost[0],5,5,1,0,20, keyboardController, ghostRenderer);
        entities.emplace_back(ghost_inky_pal,ghost[0],21,5,1,0,20, keyboardController, ghostRenderer);
        entities.emplace_back(ghost_clyde_pal,ghost[0],37,5,1,0,20, keyboardController, ghostRenderer);
        entities.emplace_back(ghost_pinky_pal,ghost[0],53,5,1,0,20, keyboardController, ghostRenderer);
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
