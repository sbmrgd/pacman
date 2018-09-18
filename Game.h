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
    bool updateScreen = false;

    std::vector<Entity> entities;
    std::vector<EntityController*> controllers;
    std::vector<EntityRenderer*> renderers;

    void updateState()
    {
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
    }

    void renderState()
    {
        for(auto & entity : entities)
        {
            entity.render();
        }

        for(std::size_t index = 0;index<entities.size();++index)
        {
            if (!entities[index].changedBitmap) Pokitto::Display::setSpritePos(index,entities[index].position.x,entities[index].position.y);
            else Pokitto::Display::setSpriteBitmap(index,entities[index].bitmap,entities[index].palette,entities[index].position.x,entities[index].position.y);

        }
    }

    void showTitleScreen()
    {

        updateState();
        renderState();

        Pokitto::Display::setCursor(Pokitto::Display::getWidth()/2-4*Pokitto::Display::fontWidth,Pokitto::Display::getHeight()-Pokitto::Display::fontHeight-10);
        Pokitto::Display::println("Insert (C)oin");

        if (updateScreen)
        {
            Pokitto::Display::update();
            updateScreen = false;
        }
        if (Pokitto::Buttons::pressed(BTN_C))
        {
                gamestate = GameState::GamePlay;
                this->clearScreen();
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
            this->playGame();
            break;
        }
    }

    public:
    void begin()
    {
        //Initialize Pokitto
        Pokitto::Core::begin();
        Pokitto::Core::setFrameRate(255);
        Pokitto::Display::persistence = 1;
        Pokitto::Display::setFont(fontKoubit);

        //Initialize Controllers
        controllers.push_back(&letterControllerEven);
        controllers.push_back(&letterControllerOdd);
        controllers.push_back(&keyboardController);

        //Initialize Renderers
        renderers.push_back(&ghostRenderer);
        renderers.push_back(&pacmanRenderer);

        //Initialize Entities
        entities.emplace_back(letters_pal,letters[0],(int16_t)(Pokitto::Display::getWidth()/2-3*18),(int16_t)(Pokitto::Display::getHeight()/2-8+2),0,0,400, letterControllerEven);
        entities.emplace_back(letters_pal,letters[1],(int16_t)(Pokitto::Display::getWidth()/2-2*18),(int16_t)(Pokitto::Display::getHeight()/2-8-2),0,0,400, letterControllerOdd);
        entities.emplace_back(letters_pal,letters[2],(int16_t)(Pokitto::Display::getWidth()/2-1*18),(int16_t)(Pokitto::Display::getHeight()/2-8+2),0,0,400, letterControllerEven);
        entities.emplace_back(letters_pal,letters[3],(int16_t)(Pokitto::Display::getWidth()/2-0*18),(int16_t)(Pokitto::Display::getHeight()/2-8-2),0,0,400, letterControllerOdd);
        entities.emplace_back(letters_pal,letters[1],(int16_t)(Pokitto::Display::getWidth()/2+1*18),(int16_t)(Pokitto::Display::getHeight()/2-8+2),0,0,400, letterControllerEven);
        entities.emplace_back(letters_pal,letters[4],(int16_t)(Pokitto::Display::getWidth()/2+2*18),(int16_t)(Pokitto::Display::getHeight()/2-8-2),0,0,400, letterControllerOdd);
        entities.emplace_back(ghost_blinky_pal,ghost[0],5,5,1,0,20, keyboardController, ghostRenderer);
        entities.emplace_back(ghost_inky_pal,ghost[0],21,5,1,0,20, keyboardController, ghostRenderer);
        entities.emplace_back(ghost_clyde_pal,ghost[0],37,5,1,0,20, keyboardController, ghostRenderer);
        entities.emplace_back(ghost_pinky_pal,ghost[0],53,5,1,0,20, keyboardController, ghostRenderer);
        entities.emplace_back(pacman_pal,pacman_sprite[0],20,20,1,0,20, keyboardController, pacmanRenderer);

        for(std::size_t index = 0;index<entities.size();++index)
        {
                Pokitto::Display::setSpriteBitmap(index,entities[index].bitmap,entities[index].palette,entities[index].position.x,entities[index].position.y);
        }
        updateScreen = true;
    }
    void clearScreen()
    {
        for(int16_t x=0;x<Pokitto::Display::getHeight()/2+1;x++){
        Pokitto::Display::directRectangle(Pokitto::Display::getWidth()/2-x*1.25, Pokitto::Display::getHeight()/2-x, Pokitto::Display::getWidth()/2+x*1.25 , Pokitto::Display::getHeight()/2+x,0);
        Pokitto::Core::wait(10);
        }

        for(std::size_t index = 0;index<entities.size();++index)
        {
            entities[index].makeInvisible();
            //Pokitto::Display::setSpritePos(index,300,300);
        }
        renderState();

        /*TO DO: this part should be moved to a new function beginGame or InitializeGame or something
        for(std::size_t index = 6;index<10;++index)
        {
            entities[index].position=Vector2{Pokitto::Display::getWidth()/2+16*(index-8),Pokitto::Display::getHeight()/2-8};
        }

        entities[10].position=Vector2{0,Pokitto::Display::getHeight()-16};
        */

        Pokitto::Display::fillScreen(0);
        updateScreen = true;


    }

    void playGame()
    {

        Pokitto::Display::setColor(1);
        Pokitto::Display::setCursor(10,10);
        Pokitto::Display::println("gameplay");
        if (updateScreen)
        {
            Pokitto::Display::update();
        updateScreen=false;
        }
        updateState();
        renderState();

    }
    void run()
    {
        while (Pokitto::Core::isRunning())
        {
            if (Pokitto::Core::update(true))
            {
                this->update();
            }
        }
    }
};
