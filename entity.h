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
#include "Vector2.h"
#include "EntityController.h"
#include "EntityRenderer.h"

class Entity
{

public:
    const uint16_t* palette; //pointer to main palette of the entity
    const uint8_t* bitmap; //pointer to current bitmap of the entity
    const uint8_t* bitmap0; //pointer to the first bitmap of the sprite sheet of the entity
    Vector2 position; // position vector
    Vector2 movement; // movement vector
    uint32_t time1 = Pokitto::Core::getTime(); // start time
    uint32_t update_time; // everytime that a number of ms equal to update_time have passed, the movement vector is added to the position vector
    bool changedBitmap = false;
    /*Entity(const uint16_t* palette, const uint8_t* bitmap,uint16_t x, uint16_t y,EntityController & controller)
		: controller(&controller)
	{
	    this->palette = palette;
	    this->bitmap = bitmap;
	    this->position.x = x;
	    this->position.y = y;
	}*/
private:
	EntityController * controller; //Controller of the entity
	EntityRenderer  * renderer = nullptr; //Renderer of the entity
	bool isVisible = true;

public:
    Entity(const uint16_t* palette, const uint8_t* bitmap,int16_t p_x, int16_t p_y, int16_t m_x, int16_t m_y, uint32_t update_time, EntityController & controller)
    : palette{palette}, bitmap{bitmap}, bitmap0{bitmap}, position{p_x,p_y}, movement{m_x,m_y}, update_time{update_time}, controller(&controller)
    {

    }
    Entity(const uint16_t* palette, const uint8_t* bitmap,int16_t p_x, int16_t p_y, int16_t m_x, int16_t m_y, uint32_t update_time,
           EntityController & controller, EntityRenderer & renderer)
    : palette{palette}, bitmap{bitmap}, bitmap0{bitmap}, position{p_x,p_y}, movement{m_x,m_y}, update_time{update_time}, controller(&controller), renderer(&renderer)
    {

    }
	EntityController * getController(void) const
	{
		return this->controller;
	}
	void makeInvisible()
	{
	    isVisible = false;
	    this->position=Vector2{300,300};
	}
	void makeVisible(Vector2 newPosition)
	{
	    isVisible = true;
	    this->position=newPosition;
	}
	void update(void)
	{
	    if (isVisible)
        {
            if(this->controller != nullptr)
                this->controller->update(*this);
            if((Pokitto::Core::getTime()-time1)>update_time)
            {
                time1 = Pokitto::Core::getTime();
                this->position+=movement;

            }

            if (this->position.x<0)
                this->position.x=0;
            if (this->position.x>Pokitto::Display::getWidth()-bitmap[0])
                this->position.x=Pokitto::Display::getWidth()-bitmap[0];
            if (this->position.y<0)
                this->position.y=0;
            if (this->position.y>Pokitto::Display::getHeight()-bitmap[1])
                this->position.y=Pokitto::Display::getHeight()-bitmap[1];
        }


	}
	void render(void)
	{
    if(this->renderer != nullptr)
			this->renderer->render(*this);
	}
};


