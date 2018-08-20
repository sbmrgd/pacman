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
	    if(Pokitto::Buttons::pressed(BTN_UP))
        {
            entity.movement =Vector2{0,-1};
        }
        if(Pokitto::Buttons::pressed(BTN_DOWN))
        {
            entity.movement =Vector2{0,1};
        }
        if(Pokitto::Buttons::pressed(BTN_LEFT))
        {
            entity.movement =Vector2{-1,0};
        }
        if(Pokitto::Buttons::pressed(BTN_RIGHT))
        {
            entity.movement =Vector2{1,0};
        }
	};

};
