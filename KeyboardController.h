#pragma once

#include "Pokitto.h"
#include "EntityController.h"
#include "entity.h"

class KeyboardController : public EntityController
{
public:
	virtual ~KeyboardController(void) {}

    virtual void update(void)
    {

    }
	virtual void update(Entity & entity)
	{
	    //if(Pokitto::Buttons::pressed(BTN_UP))
        if(Pokitto::Buttons::upBtn())
        {   if ((maze[(entity.position.y/8-1)*21+(entity.position.x/8)]!=1) && (maze[(entity.position.y/8-1)*21+((entity.position.x+7)/8)]!=1))
            {
                entity.movement =Vector2{0,-1};
            }

        }
        //if(Pokitto::Buttons::pressed(BTN_DOWN))
        if(Pokitto::Buttons::downBtn())
        {
            if ((maze[(entity.position.y/8+1)*21+(entity.position.x/8)]!=1) && (maze[(entity.position.y/8+1)*21+((entity.position.x+7)/8)]!=1))
            {
                entity.movement =Vector2{0,1};
            }

        }
        //if(Pokitto::Buttons::pressed(BTN_LEFT))
        if(Pokitto::Buttons::leftBtn())
        {
            if ((maze[(entity.position.y/8)*21+(entity.position.x/8-1)]!=1) && (maze[((entity.position.y+7)/8)*21+(entity.position.x/8-1)]!=1))
            {
                entity.movement =Vector2{-1,0};
            }

        }
        //if(Pokitto::Buttons::pressed(BTN_RIGHT))
        if(Pokitto::Buttons::rightBtn())
        {
            if ((maze[(entity.position.y/8)*21+(entity.position.x/8+1)]!=1) && (maze[((entity.position.y+7)/8)*21+(entity.position.x/8+1)]!=1))
            {
                entity.movement =Vector2{1,0};
            }
        }
	};

};
