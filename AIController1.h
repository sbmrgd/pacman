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

class AIController1 : public EntityController
{
private:
    uint32_t time1 = Pokitto::Core::getTime();
    uint8_t counter = 8;
public:
	virtual ~AIController1(void) {}

    virtual void update(void)
    {

    }

	virtual void update(Entity & entity, Grid & grid)
	{
	    if (counter==0)
        {
            counter = 8;
	    uint8_t randomNumber = rand() % 4;
	    switch (randomNumber)
	    {
        case 0:
            entity.movement = Vector2{0, -1};
            break;
        case 1:
            entity.movement = Vector2{0, 1};
            break;
        case 2:
            entity.movement = Vector2{-1, 0};
            break;
        case 3:
            entity.movement = Vector2{1, 0};
            break;
	    }
        }

        if((Pokitto::Core::getTime()-time1)>entity.update_time)
        {   counter--;
            time1 = Pokitto::Core::getTime();
            if (((entity.position.x%spriteWidth)==0) && ((entity.position.y%spriteHeight)==0))
                {
                    /*if (grid.getItem((entity.position.x/spriteWidth),(entity.position.y/spriteHeight))>Tile::Wall)
                    {
                        grid.getItem((entity.position.x/spriteWidth),(entity.position.y/spriteHeight))=Tile::Empty;
                        grid.totalPillsRemaining--;
                    }*/
                    if (grid.getItem((entity.position.x/spriteWidth+entity.movement.x+mazeWidth)%mazeWidth,(entity.position.y/spriteHeight+entity.movement.y))!=Tile::Wall)
                    {
                        if (entity.position.x/spriteWidth==(mazeWidth-1)) entity.position.x=0;
                        else if (entity.position.x==0) entity.position.x=(mazeWidth-1)*spriteWidth;
                        entity.position+=entity.movement;
                    }
                }
                else
                {
                    entity.position+=entity.movement;
                }
        }
	};

};

