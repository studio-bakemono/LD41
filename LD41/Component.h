#pragma once

#include <iostream>
#include <vector>
#include "SDL.h"

class App;

class Component
{
protected:
	virtual void onUpdate(App* game) = 0;
	virtual void onCleanup() = 0;
public:

	enum ComponentType {
		GraphicsComponent,
		PhysicsComponent,
		InputComponent,
		AudioComponent
	};

	Component();
	void update(App* game);
	void cleanup();
	~Component();
};
