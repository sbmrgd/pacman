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

#include "Pokitto.h"
#include "EntityController.h"
#include "entity.h"
#include "Grid.h"

class KeyboardController : public EntityController
{
public:
	virtual ~KeyboardController(void) {}

    virtual void update(void)
    {

    }
	virtual void update(Entity & entity, Grid & grid)
	{
	    if(Pokitto::Buttons::upBtn())
        {
            if ((grid.getItem(entity.position.x/8,entity.position.y/8-1)!=Tile::Wall) && (grid.getItem((entity.position.x+7)/8,entity.position.y/8-1)!=Tile::Wall))
            {
                entity.movement = Vector2{0, -1};
            }

        }

        if(Pokitto::Buttons::downBtn())
        {
            if ((grid.getItem(entity.position.x/8,entity.position.y/8+1)!=Tile::Wall) && (grid.getItem((entity.position.x+7)/8,entity.position.y/8+1)!=Tile::Wall))
            {
                entity.movement = Vector2{0, 1};
            }

        }

        if(Pokitto::Buttons::leftBtn())
        {
            if ((grid.getItem(entity.position.x/8-1,entity.position.y/8)!=Tile::Wall) && (grid.getItem(entity.position.x/8-1,(entity.position.y+7)/8)!=Tile::Wall))
            {
                entity.movement = Vector2{-1, 0};
            }

        }

        if(Pokitto::Buttons::rightBtn())
        {
            if ((grid.getItem(entity.position.x/8+1,entity.position.y/8)!=Tile::Wall) && (grid.getItem(entity.position.x/8+1,(entity.position.y+7)/8)!=Tile::Wall))
            {
                entity.movement = Vector2{1, 0};
            }
        }
	};

};
