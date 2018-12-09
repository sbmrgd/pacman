#pragma once

#include "Pokitto.h"
#include "EntityRenderer.h"
#include "entity.h"

class SimpleRenderer : public EntityRenderer
{

private:
    uint32_t time1 = Pokitto::Core::getTime();
    int16_t bitmapnr = 0;
    bool elapsed = false;
public:
	virtual ~SimpleRenderer(void) {}

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
            //entity.bitmap = entity.bitmap0 + bitmapnr*66;
            entity.bitmap = entity.bitmap0 + bitmapnr*18;
            entity.changedBitmap = true;
        }
        else entity.changedBitmap = false;
	}
};
