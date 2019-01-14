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

#include <cstddef>
#include "Pokitto.h"
#include "tiles.h"

enum class GridState
{
	NormalState,
	PowerState,
	PowerState2,
};
class Grid
{

public:
    constexpr static std::size_t height = 21;
    constexpr static std::size_t width = 21;
    Tile items[height*width];
    GridState gridState = GridState::NormalState;
    uint32_t powerStateTimer;
    uint32_t powerStateDuration;
    uint32_t time1;
//private:

    uint8_t totalPillsRemaining = 0;


public:
    Grid(const Tile (&array)[height * width])
    {
       for(std::size_t indexHeight = 0; indexHeight < height; indexHeight++)
        {
            for(std::size_t indexWidth = 0; indexWidth < width; indexWidth++)
            {
                items[indexHeight * width + indexWidth] = array[indexHeight * width + indexWidth];

                //Count the total number of pills to collect
                switch (array[indexHeight * width + indexWidth])
                {
                    case Tile::Pill:
                    case Tile::PowerPill: totalPillsRemaining++;
                    break;
                    case Tile::Empty:
                    case Tile::Wall:
                    break;
                }
            }
        }
    }

    Tile & getItem(std::size_t x, std::size_t y)
    {
        return this->items[y * width + x];
    }
    void setPowerState(uint32_t duration)
    {
        this->gridState = GridState::PowerState;
        this->powerStateDuration = duration;
        this->time1 = Pokitto::Core::getTime();
        this->powerStateTimer = 10;
    }
    void update()
    {
        if ((this->gridState==GridState::PowerState)|| (this->gridState==GridState::PowerState2))
        {
            if ((Pokitto::Core::getTime()-time1)> powerStateDuration/10)
            {
                powerStateTimer--;
                this->time1 = Pokitto::Core::getTime();
            }
            if (powerStateTimer == 4) this->gridState=GridState::PowerState2;
            else if (powerStateTimer == 0) this->gridState=GridState::NormalState;
        }
    }
};
