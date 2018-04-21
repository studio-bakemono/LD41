#pragma once
#include "SDL.h"

class GraphicsComponent
{
protected:
	SDL_Texture* tex;
	SDL_Rect* size;

	virtual void onUpdate(SDL_Renderer* renderer) = 0;
	virtual void onCleanup() = 0;

public:
	void update(SDL_Renderer* renderer);
	void cleanup();
	~GraphicsComponent();
};

