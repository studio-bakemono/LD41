#pragma once
#include "SDL.h"
#include "GraphicsComponent.h"

class BitButtonComponent : public GraphicsComponent
{
private:
	bool flipped = false;
protected:
	void onUpdate(App* game);
	void onCleanup();
public:
	void flip(bool on);
	BitButtonComponent(std::string filename, SDL_Renderer* renderer, int position);
	~BitButtonComponent();
};

