#pragma once

#include <iostream>
#include <vector>
#include "SDL.h"

class Component
{
public:

	enum ComponentType {
		GraphicsComponent,
		PhysicsComponent,
		InputComponent,
		AudioComponent
	};

	Component();

	virtual void update() = 0;
	virtual void cleanup() = 0;
	
	~Component();
};

