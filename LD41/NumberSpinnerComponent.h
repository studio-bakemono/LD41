#pragma once
#include "GraphicsComponent.h"
#include "SDL_ttf.h"

class NumberSpinnerComponent :
	public GraphicsComponent
{
private:
	SDL_Texture * arrowUp;
	SDL_Texture * arrowDown;
	SDL_Rect arrowUpRect;
	SDL_Rect arrowDownRect;
	SDL_Color color;
	SDL_Rect contour;
	SDL_Rect msg_rect;

protected:
	void onUpdate(App* game);
	void onCleanup();
public:
	NumberSpinnerComponent(SDL_Renderer* renderer, SDL_Texture* arrowUp, SDL_Texture* arrowDown, TTF_Font * font, SDL_Color color, int posx, int posy);
	~NumberSpinnerComponent();
};
