#include "NumberSpinnerComponent.h"
#include "App.h"


void NumberSpinnerComponent::onUpdate(App * game)
{
	SDL_RenderCopy(game->renderer, arrowUp, NULL, &arrowUpRect);
	SDL_RenderCopy(game->renderer, arrowDown, NULL, &arrowDownRect);
	
	SDL_SetRenderDrawColor(game->renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawRect(game->renderer, &contour);
	SDL_RenderCopy(game->renderer, tex, NULL, &msg_rect);

}

void NumberSpinnerComponent::onCleanup()
{
	SDL_DestroyTexture(this->arrowUp);
	SDL_DestroyTexture(this->arrowDown);
}

NumberSpinnerComponent::NumberSpinnerComponent(SDL_Renderer* renderer, SDL_Texture* arrowUp, SDL_Texture* arrowDown, TTF_Font * font, SDL_Color color, int posx, int posy)
{
	this->arrowUp = arrowUp;
	this->arrowDown = arrowDown;
	this->color = color;

	arrowUpRect.h = 24;
	arrowUpRect.w = 24;
	arrowUpRect.x = posx + 4;
	arrowUpRect.y = posy + 4;

	arrowDownRect.h = 24;
	arrowDownRect.w = 24;
	arrowDownRect.x = posx + 144;
	arrowDownRect.y = posy + 4;

	contour.h = 32;
	contour.w = 172;
	contour.x = posx;
	contour.y = posy;

	msg_rect.x = posx + 48;
	msg_rect.y = posy + 4;
	msg_rect.w = 80;
	msg_rect.h = 28;

	this->color = color;

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, "000", color);

	tex = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	//Don't forget too free your surface and texture
	SDL_FreeSurface(surfaceMessage);

}

NumberSpinnerComponent::~NumberSpinnerComponent()
{
	cleanup();
}
