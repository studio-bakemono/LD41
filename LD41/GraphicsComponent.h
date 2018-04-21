#pragma once
#include "SDL.h"
#include "Component.h"

class GraphicsComponent: public Component
{
protected:
	SDL_Texture* tex;
	SDL_Rect* size;
public:
	~GraphicsComponent();
};

