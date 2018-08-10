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

class Entity
{

public:
    const uint16_t* palette; //pointer to main palette of the entity
    const uint8_t* bitmap; //pointer to current bitmap of the entity
    Vector2 position; // position vector
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

public:
    Entity(const uint16_t* palette, const uint8_t* bitmap,uint16_t x, uint16_t y, EntityController & controller)
    : palette{palette}, bitmap{bitmap}, position{x,y}, controller(&controller)
    {
    }
	EntityController * getController(void) const
	{
		return this->controller;
	}
	void update(void)
	{
		if(this->controller != nullptr)
			this->controller->update(*this);
	}
};


