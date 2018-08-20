#pragma once

// Predeclaring Entity so EntityRenderer knows it exists
class Entity;

class EntityRenderer
{
public:
	virtual ~EntityRenderer(void) {}

	// For updating the frame count mainly
	virtual void update(void) {}

	// Pure virtual function -
	// inheriting classes must implement this or they won't compile
	virtual void render(Entity & entity) = 0;
};
