#include "OperatorButtonComponent.h"
#include "App.h"

void OperatorButtonComponent::onUpdate(App * game)
{
	SDL_RenderCopy(game->renderer, tex, NULL, &msg_rect);
	SDL_SetRenderDrawColor(game->renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawRect(game->renderer, &contour);
}


void OperatorButtonComponent::onCleanup()
{

}


OperatorButtonComponent::OperatorButtonComponent(SDL_Renderer* renderer, TTF_Font* font, SDL_Color color, int posx, int posy, int width, int height)
{
	msg_rect.x = posx + 4;
	msg_rect.y = posy + 4;
	msg_rect.w = width - 8;
	msg_rect.h = height - 8;
	contour.x = posx;
	contour.y = posy;
	contour.w = width;
	contour.h = height;

	this->color = color;

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, "%", color);

	tex = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	//Don't forget too free your surface and texture
	SDL_FreeSurface(surfaceMessage);

}


OperatorButtonComponent::~OperatorButtonComponent()
{
	
}
