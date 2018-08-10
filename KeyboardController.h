#pragma once

#include "Pokitto.h"
#include "EntityController.h"
#include "entity.h"

class KeyboardController : public EntityController
{
public:
	virtual ~KeyboardController(void) {}


	virtual void update(Entity & entity)
	{
	    if(Pokitto::Buttons::pressed(BTN_A))
        {
            entity.position.x+=1;
        }
	};

};
