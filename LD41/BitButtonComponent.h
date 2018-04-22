#pragma once
#include "SDL.h"
#include "GraphicsComponent.h"

class BitButtonComponent : public GraphicsComponent
{
private:
	bool flipped = false;
	int alphaOff;
protected:
	void onUpdate(App* game);
	void onCleanup();
public:
	void flip(bool on);
	BitButtonComponent(std::string filename, SDL_Renderer* renderer, int startx, int starty, int size, int alphaOff);
	~BitButtonComponent();
};

