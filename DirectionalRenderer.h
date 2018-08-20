#pragma once

#include "Pokitto.h"
#include "EntityRenderer.h"
#include "entity.h"

class DirectionalRenderer : public EntityRenderer
{

private:
    uint32_t time1 = Pokitto::Core::getTime();
    int16_t bitmapnr = 0;
    int16_t direction = 0;
    bool elapsed = false;

    int16_t getDirection(Entity &entity)
    {
        if (entity.movement.x>0) return 0;
        else
        {
            if (entity.movement.x<0) return 1;
            else
            {
                if (entity.movement.y<0) return 2;
                else return 3;
            }
        }

    }
public:
	virtual ~DirectionalRenderer(void) {}

	// For updating the frame count mainly
	virtual void update(void)
	{

        if((Pokitto::Core::getTime()-time1)>100)
        {
            time1 = Pokitto::Core::getTime();
            bitmapnr = (bitmapnr+1+4)%4;
            elapsed = true;
        }
        else elapsed = false;
    }

	// Pure virtual function -
	// inheriting classes must implement this or they won't compile
	virtual void render(Entity & entity)
	{
        if (elapsed)
        {
            entity.bitmap = entity.bitmap0 +getDirection(entity)*4*66 + bitmapnr*66;
        }
	}
};
