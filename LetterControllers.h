#pragma once

#include "Pokitto.h"
#include "EntityController.h"
#include "entity.h"
#include "Grid.h"

class LetterController : public EntityController
{

private:
    uint32_t time1 = Pokitto::Core::getTime();
    int16_t y_adjustment;
    bool elapsed = false;

public:
    LetterController (int16_t y_adjustment) : y_adjustment(y_adjustment)
    {
    }

	virtual ~LetterController(void) {}

    void update(void)
    {
        /*if((Pokitto::Core::getTime()-time1)>400)
        {
            time1 = Pokitto::Core::getTime();
            y_adjustment *= -1;
            elapsed = true;
        }
        else elapsed = false;*/
    }
	void update(Entity & entity, Grid & grid)
	{
	    if((Pokitto::Core::getTime()-time1)>entity.update_time)
	    //if(elapsed)
        {
            time1 = Pokitto::Core::getTime();
            y_adjustment *= -1;
            entity.movement.y = y_adjustment;
            entity.position += entity.movement;
        }
        else
        {
            entity.movement.y = 0;
        }
        //entity.movement.y = y_adjustment;
        entity.position += entity.movement;
	};

};
