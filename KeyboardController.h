#pragma once

#include "Pokitto.h"
#include "EntityController.h"

class KeyboardController : public EntityController
{
public:
	virtual ~KeyboardController(void) {}


	virtual void update(Entity & entity) {};

};
