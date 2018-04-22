#include "BitButtonComponent.h"
#include "Graphics.h"
#include "App.h"

void BitButtonComponent::onUpdate(App * game)
{
	SDL_RenderCopy(game->renderer, tex, NULL, this->size);
}

void BitButtonComponent::onCleanup()
{

}

void BitButtonComponent::flip(bool on)
{
	flipped = on;
	if (flipped)
	{
		SDL_SetTextureAlphaMod(tex, 255);
	}
	else
	{
		SDL_SetTextureAlphaMod(tex, 127);
	}
}

BitButtonComponent::BitButtonComponent(std::string filename, SDL_Renderer * renderer, int position)
{
	this->size = new SDL_Rect();
	this->size->h = 64;
	this->size->w = 64;
	this->size->x = position;
	this->size->y = 32;

	tex = Graphics::LoadTexture(renderer, filename);
	if (!tex) {
		SDL_GetError();
	}
	SDL_SetTextureBlendMode(tex, SDL_BLENDMODE_BLEND);

}

BitButtonComponent::~BitButtonComponent()
{

}
