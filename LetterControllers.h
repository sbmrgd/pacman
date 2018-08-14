#pragma once

#include "Pokitto.h"
#include "EntityController.h"
#include "entity.h"

class LetterController : public EntityController
{

private:
    uint32_t time1 = Pokitto::Core::getTime();
    int16_t y_adjustment;

public:
    LetterController (int16_t y_adjustment) : y_adjustment(y_adjustment)
    {
    }
	virtual ~LetterController(void) {}


	virtual void update(Entity & entity)
	{
	    if((Pokitto::Core::getTime()-time1)>400)
        {
            time1 = Pokitto::Core::getTime();
            //entity.position.y+=y_adjustment;
            entity.movement.y = -y_adjustment;
            y_adjustment *= -1;
        }
	};

};
