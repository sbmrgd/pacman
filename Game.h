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
#include "StaticRenderer.h"
#include "AnimatedRenderer.h"
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
    StaticRenderer letterRenderer;
    AnimatedRenderer ghostRenderer;
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

        /*for(std::size_t index = 0;index<entities.size();++index)
        {
            if (!entities[index].changedBitmap) Pokitto::Display::setSpritePos(index,entities[index].position.x,entities[index].position.y);
            else Pokitto::Display::setSpriteBitmap(index,entities[index].bitmap,entities[index].palette,entities[index].position.x,entities[index].position.y);

        }*/
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
                Pokitto::Sound::playMusicStream();

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
        Pokitto::Sound::playMusicStream("music/pacman.snd"); //before game.begin!
        //Initialize Pokitto
        Pokitto::Sound::pauseMusicStream();
        Pokitto::Core::begin();
        Pokitto::Core::setFrameRate(255);
        Pokitto::Display::persistence = 1;
        Pokitto::Display::setFont(fontKoubit);
        Pokitto::Display::loadRGBPalette(Game_pal);

        //Initialize Controllers
        controllers.push_back(&letterControllerEven);
        controllers.push_back(&letterControllerOdd);
        controllers.push_back(&keyboardController);

        //Initialize Renderers
        renderers.push_back(&letterRenderer);
        renderers.push_back(&ghostRenderer);
        renderers.push_back(&pacmanRenderer);

        //Initialize Entities
        entities.emplace_back(0, letters_pal,letters[0],(int16_t)(Pokitto::Display::getWidth()/2-3*18),(int16_t)(Pokitto::Display::getHeight()/2-32+2),0,0,400, letterControllerEven, letterRenderer);
        entities.emplace_back(1, letters_pal,letters[1],(int16_t)(Pokitto::Display::getWidth()/2-2*18),(int16_t)(Pokitto::Display::getHeight()/2-32-2),0,0,400, letterControllerOdd, letterRenderer);
        entities.emplace_back(2, letters_pal,letters[2],(int16_t)(Pokitto::Display::getWidth()/2-1*18),(int16_t)(Pokitto::Display::getHeight()/2-32+2),0,0,400, letterControllerEven, letterRenderer);
        entities.emplace_back(3, letters_pal,letters[3],(int16_t)(Pokitto::Display::getWidth()/2-0*18),(int16_t)(Pokitto::Display::getHeight()/2-32-2),0,0,400, letterControllerOdd, letterRenderer);
        entities.emplace_back(4, letters_pal,letters[1],(int16_t)(Pokitto::Display::getWidth()/2+1*18),(int16_t)(Pokitto::Display::getHeight()/2-32+2),0,0,400, letterControllerEven, letterRenderer);
        entities.emplace_back(5, letters_pal,letters[4],(int16_t)(Pokitto::Display::getWidth()/2+2*18),(int16_t)(Pokitto::Display::getHeight()/2-32-2),0,0,400, letterControllerOdd, letterRenderer);
        /*entities.emplace_back(ghost_blinky_pal,ghost[0],5,5,1,0,20, keyboardController, ghostRenderer);
        entities.emplace_back(ghost_inky_pal,ghost[0],21,5,1,0,20, keyboardController, ghostRenderer);
        entities.emplace_back(ghost_clyde_pal,ghost[0],37,5,1,0,20, keyboardController, ghostRenderer);
        entities.emplace_back(ghost_pinky_pal,ghost[0],53,5,1,0,20, keyboardController, ghostRenderer);*/
        //entities.emplace_back(pacman_pal,pacman_sprite[0],20,20,1,0,20, keyboardController, pacmanRenderer);
        entities.emplace_back(6, ghost_blinky_pal,ghost_small[0],4,(int16_t)(Pokitto::Display::getHeight()/2)+1,1,0,20, keyboardController, ghostRenderer);
        entities.emplace_back(7, ghost_inky_pal,ghost_small[0],12,(int16_t)(Pokitto::Display::getHeight()/2)+1,1,0,20, keyboardController, ghostRenderer);
        entities.emplace_back(8, ghost_clyde_pal,ghost_small[0],20,(int16_t)(Pokitto::Display::getHeight()/2)+1,1,0,20, keyboardController, ghostRenderer);
        entities.emplace_back(9, ghost_pinky_pal,ghost_small[0],28,(int16_t)(Pokitto::Display::getHeight()/2)+1,1,0,20, keyboardController, ghostRenderer);
        entities.emplace_back(10, pacman_pal,pacman_small2[0],36,(int16_t)(Pokitto::Display::getHeight()/2)+1,1,0,20, keyboardController, pacmanRenderer);

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
        Pokitto::Display::fillScreen(0);
        updateScreen = true;

        /*TO DO: this part should be moved to a new function beginGame or InitializeGame or something
        for(std::size_t index = 6;index<10;++index)
        {
            entities[index].position=Vector2{Pokitto::Display::getWidth()/2+16*(index-8),Pokitto::Display::getHeight()/2-8};
        }

        entities[10].position=Vector2{0,Pokitto::Display::getHeight()-16};
        */
    }

    void playGame()
    {

        Pokitto::Display::setColor(2);
        /*for(int i=0;i<Pokitto::Display::getWidth();i+=16)
        {
            Pokitto::Display::fillRectangle(i,0,15,15);
            Pokitto::Display::fillRectangle(i,Pokitto::Display::getHeight()-16,15,15);
        }*/
        for(std::size_t x=0;x<mazeWidth;x++)
                {
                    for(std::size_t y=0;y<mazeHeight;y++)
                    {
                        switch (maze[(y)*mazeWidth+x])
                        {
                            case Tile::Empty:
                                Pokitto::Display::setColor(0);
                                Pokitto::Display::fillRectangle(x*spriteWidth,y*spriteHeight,spriteWidth,spriteHeight-1); //bug in fillRectangle, so spriteHeight-1 instead of spriteHeight
                                break;
                                break;
                            case Tile::Wall:
                                Pokitto::Display::setColor(2);
                                Pokitto::Display::fillRectangle(x*spriteWidth,y*spriteHeight,spriteWidth,spriteHeight-1);
                                break;
                            case Tile::Pill:
                                Pokitto::Display::setColor(1);
                                //Pokitto::Display::fillCircle(8*x+3,8*y+3,1);
                                Pokitto::Display::fillRectangle(x*spriteWidth+3,y*spriteHeight+3,2,1);
                                break;
                            case Tile::PowerPill:
                                Pokitto::Display::setColor(1);
                                Pokitto::Display::fillCircle(spriteWidth*x+3,spriteHeight*y+3,2);
                                break;
                        }
                    }
                }
        if (updateScreen)
        {
            Pokitto::Sound::pauseMusicStream();
            Pokitto::Display::update();
        updateScreen=false;
        for(uint8_t i=entities.size()-1;i<entities.size();i++)
        {
            //entities[i].makeVisible(Vector2{(i-6)*16,16});
            entities[i].makeVisible(Vector2{7*8,17*8});
        }
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
