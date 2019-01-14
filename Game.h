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
#include "AIController1.h"
#include "StaticRenderer.h"
#include "AnimatedRenderer.h"
#include "DirectionalRenderer.h"
#include "Grid.h"

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
    AIController1 blinkyController;
    AIController1 inkyController;
    AIController1 clydeController;
    AIController1 pinkyController;
    LetterController letterControllerP{4};
    LetterController letterControllerA{-3};
    LetterController letterControllerC{2};
    LetterController letterControllerM{-2};
    LetterController letterControllerA2{3};
    LetterController letterControllerN{-4};
    StaticRenderer letterRenderer;
    AnimatedRenderer ghostRenderer;
    DirectionalRenderer pacmanRenderer;
    Grid maze{mazeData};
    bool updateScreen = false;
    uint32_t time1;
    bool switchPalette;

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
                entity.update(maze);
        }

        for(auto & renderer : renderers)
        {
            (*renderer).update();
        }
        if (this->gamestate==GameState::GamePlay) maze.update();
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
        if (this->gamestate==GameState::GamePlay) drawMaze();
    }

    void showTitleScreen()
    {
        updateState();
        renderState();


        if (updateScreen)
        {
            Pokitto::Display::setColor(1);
            Pokitto::Display::setCursor(Pokitto::Display::getWidth()/2-4*Pokitto::Display::fontWidth,Pokitto::Display::getHeight()-Pokitto::Display::fontHeight-10);
            Pokitto::Display::println("Insert (C)oin");

            Pokitto::Display::update();
            updateScreen = false;
        }
        if (Pokitto::Buttons::pressed(BTN_C))
        {
                Pokitto::Sound::playMusicStream();
                gamestate = GameState::GamePlay;
                maze = Grid(mazeData);
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
        controllers.push_back(&letterControllerP);
        controllers.push_back(&letterControllerA);
        controllers.push_back(&letterControllerC);
        controllers.push_back(&letterControllerM);
        controllers.push_back(&letterControllerA2);
        controllers.push_back(&letterControllerN);
        controllers.push_back(&keyboardController);
        controllers.push_back(&blinkyController);
        controllers.push_back(&inkyController);
        controllers.push_back(&clydeController);
        controllers.push_back(&pinkyController);

        //Initialize Renderers
        renderers.push_back(&letterRenderer);
        renderers.push_back(&ghostRenderer);
        renderers.push_back(&pacmanRenderer);

        //Initialize Entities
        entities.emplace_back(0, letters_pal,letters[0],(int16_t)(Pokitto::Display::getWidth()/2-3*18),(int16_t)(Pokitto::Display::getHeight()/2-32+2),0,0,400, letterControllerP, letterRenderer);
        entities.emplace_back(1, letters_pal,letters[1],(int16_t)(Pokitto::Display::getWidth()/2-2*18),(int16_t)(Pokitto::Display::getHeight()/2-32-2),0,0,400, letterControllerA, letterRenderer);
        entities.emplace_back(2, letters_pal,letters[2],(int16_t)(Pokitto::Display::getWidth()/2-1*18),(int16_t)(Pokitto::Display::getHeight()/2-32+2),0,0,400, letterControllerC, letterRenderer);
        entities.emplace_back(3, letters_pal,letters[3],(int16_t)(Pokitto::Display::getWidth()/2-0*18),(int16_t)(Pokitto::Display::getHeight()/2-32-2),0,0,400, letterControllerM, letterRenderer);
        entities.emplace_back(4, letters_pal,letters[1],(int16_t)(Pokitto::Display::getWidth()/2+1*18),(int16_t)(Pokitto::Display::getHeight()/2-32+2),0,0,400, letterControllerA2, letterRenderer);
        entities.emplace_back(5, letters_pal,letters[4],(int16_t)(Pokitto::Display::getWidth()/2+2*18),(int16_t)(Pokitto::Display::getHeight()/2-32-2),0,0,400, letterControllerN, letterRenderer);
        /*entities.emplace_back(ghost_blinky_pal,ghost[0],5,5,1,0,20, keyboardController, ghostRenderer);
        entities.emplace_back(ghost_inky_pal,ghost[0],21,5,1,0,20, keyboardController, ghostRenderer);
        entities.emplace_back(ghost_clyde_pal,ghost[0],37,5,1,0,20, keyboardController, ghostRenderer);
        entities.emplace_back(ghost_pinky_pal,ghost[0],53,5,1,0,20, keyboardController, ghostRenderer);*/
        //entities.emplace_back(pacman_pal,pacman_sprite[0],20,20,1,0,20, keyboardController, pacmanRenderer);
        entities.emplace_back(6, ghost_blinky_pal,ghost_small[0],4,(int16_t)(Pokitto::Display::getHeight()/2)+1,0,0,20, blinkyController, ghostRenderer);
        entities.emplace_back(7, ghost_inky_pal,ghost_small[0],12,(int16_t)(Pokitto::Display::getHeight()/2)+1,1,0,20, inkyController, ghostRenderer);
        entities.emplace_back(8, ghost_clyde_pal,ghost_small[0],20,(int16_t)(Pokitto::Display::getHeight()/2)+1,1,0,20, clydeController, ghostRenderer);
        entities.emplace_back(9, ghost_pinky_pal,ghost_small[0],28,(int16_t)(Pokitto::Display::getHeight()/2)+1,1,0,20, pinkyController, ghostRenderer);
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

    void drawMaze()
    {
        for(std::size_t x=0;x<mazeWidth;x++)
        {
            for(std::size_t y=0;y<mazeHeight;y++)
            {
                switch (maze.getItem( x, y))
                {
                    case Tile::Empty:
                        Pokitto::Display::setColor(0);
                        Pokitto::Display::fillRectangle(x*spriteWidth,y*spriteHeight,spriteWidth,spriteHeight-1); //bug in fillRectangle, so spriteHeight-1 instead of spriteHeight
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

    }

    void playGame()
    {
        if (maze.totalPillsRemaining==0)
        {
            clearScreen();
            gamestate = GameState::TitleScreen;
        }
        else
        {
            Pokitto::Display::setColor(2);
            //drawMaze();
            Pokitto::Display::setColor(1);
            Pokitto::Display::setCursor(168,48);
            Pokitto::Display::print((int)maze.totalPillsRemaining);
            if (maze.gridState == GridState::PowerState)
            {
                for (int i=6;i<10;i++)
                {
                    entities[i].palette = ghost_inv_pal;
                }
                this->time1 = Pokitto::Core::getTime();
                switchPalette = true;
            }
            else if (maze.gridState == GridState::PowerState2)
            {
                if((Pokitto::Core::getTime()-time1)>40)
                {
                    time1 = Pokitto::Core::getTime();
                    if (switchPalette)
                    {

                        switchPalette = 0;
                        for (int i=6;i<10;i++)
                        {
                            entities[i].palette = ghost_inv2_pal;
                        }
                    }
                    else
                    {
                        switchPalette = 1;
                        for (int i=6;i<10;i++)
                        {
                            entities[i].palette = ghost_inv_pal;
                        }
                    }
                }
            }
            else
            {
                entities[6].palette = ghost_blinky_pal;
                entities[7].palette = ghost_inky_pal;
                entities[8].palette = ghost_clyde_pal;
                entities[9].palette = ghost_pinky_pal;
            }
        //Pokitto::Display::update(false,168,48,16,8);
            if (updateScreen)
            {
                drawMaze();
                Pokitto::Sound::pauseMusicStream();
                Pokitto::Display::update();
                updateScreen=false;
                entities[6].makeVisible(Vector2{10*spriteWidth,8*spriteHeight});
                entities[6].movement = Vector2{0,0};
                entities[7].makeVisible(Vector2{9*spriteWidth,9*spriteHeight});
                entities[7].movement = Vector2{0,0};
                entities[8].makeVisible(Vector2{10*spriteWidth,9*spriteHeight});
                entities[8].movement = Vector2{0,0};
                entities[9].makeVisible(Vector2{11*spriteWidth,9*spriteHeight});
                entities[9].movement = Vector2{0,0};
                for(uint8_t i=entities.size()-1;i<entities.size();i++)
                {
                    //entities[i].makeVisible(Vector2{(i-6)*16,16});
                    entities[i].makeVisible(Vector2{7*spriteWidth,17*spriteHeight});
                }
            }

            updateState();
            renderState();
        }
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
