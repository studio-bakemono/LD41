#pragma once
#include "GraphicsComponent.h"
#include <SDL_ttf.h>


class OperatorButtonComponent :
	public GraphicsComponent
{
private:
	char currentOperator;
	SDL_Rect msg_rect;
	SDL_Rect contour;
	SDL_Color color;
protected:
	void onUpdate(App* game);
	void onCleanup();
public:
	OperatorButtonComponent(SDL_Renderer* renderer, TTF_Font* font, SDL_Color color, int posx, int posy, int width, int height);
	~OperatorButtonComponent();
};
