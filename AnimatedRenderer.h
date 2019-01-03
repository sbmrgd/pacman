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
#include "EntityRenderer.h"
#include "entity.h"

class AnimatedRenderer : public EntityRenderer
{

private:
    uint32_t time1 = Pokitto::Core::getTime();
    int16_t bitmapnr = 0;
    bool elapsed = false;
public:
	virtual ~AnimatedRenderer(void) {}

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
            //entity.bitmap = entity.bitmap0 + bitmapnr*18;
            entity.bitmap = entity.bitmap0 + bitmapnr*(2+spriteWidth*spriteHeight*spriteBitMode/8); // Each sprite bitmap consists of (2 + spriteWidth * spriteHeight / spriteBitMode / 8 uint8_t values
            //entity.changedBitmap = true;
            Pokitto::Display::setSpriteBitmap(entity.index, entity.bitmap, entity.palette, entity.position.x, entity.position.y);
        }
        else
        {
            //entity.changedBitmap = false;
            Pokitto::Display::setSpritePos(entity.index, entity.position.x, entity.position.y);
        }
	}
};
