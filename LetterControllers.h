#pragma once

#include "Pokitto.h"
#include "EntityController.h"
#include "entity.h"

class LetterController1 : public EntityController
{
private:
    uint32_t time1 = Pokitto::Core::getTime();
    uint16_t y_adjustment = -4;

public:
	virtual ~LetterController1(void) {}


	virtual void update(Entity & entity)
	{
	    if((Pokitto::Core::getTime()-time1)>400)
        {
            time1 = Pokitto::Core::getTime();
            entity.position.y+=y_adjustment;
            y_adjustment *= -1;
        }
	};

};

class LetterController2 : public EntityController
{
private:
    uint32_t time1 = Pokitto::Core::getTime();
    uint16_t y_adjustment = 4;

public:
	virtual ~LetterController2(void) {}


	virtual void update(Entity & entity)
	{
	    if((Pokitto::Core::getTime()-time1)>400)
        {
            time1 = Pokitto::Core::getTime();
            entity.position.y+=y_adjustment;
            y_adjustment *= -1;
        }
	};

};
