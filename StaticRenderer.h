#pragma once

#include "Pokitto.h"
#include "EntityRenderer.h"
#include "entity.h"

class StaticRenderer : public EntityRenderer
{

public:
	virtual ~StaticRenderer(void) {}

	// Pure virtual function -
	// inheriting classes must implement this or they won't compile
	virtual void render(Entity & entity)
	{
        Pokitto::Display::setSpritePos(entity.index, entity.position.x, entity.position.y);
	}
};

