#pragma once

// Predeclaring Entity so EntityController knows it exists
class Entity;
class Grid;

class EntityController
{
public:
	// This may not be needed,
	// but I've never tested the alternatives
	// so I'm doing this because I know it works
	virtual ~EntityController(void) {}

	virtual void update(void) = 0;
	// Pure virtual function -
	// inheriting classes must implement this or they won't compile
	virtual void update(Entity & entity, Grid & grid) = 0;
};
