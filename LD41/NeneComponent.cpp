#include "NeneComponent.h"
#include "App.h"

NeneComponent::NeneComponent(SDL_Renderer* renderer)
{
	tex = Graphics::LoadTexture(renderer, "button.bmp");
	if (!tex) {
		SDL_GetError();
	}

}
NeneComponent::~NeneComponent()
{
	cleanup();
}

void NeneComponent::onUpdate(App* game)
{
	SDL_RenderCopy(game->renderer, tex, NULL, NULL);
}

void NeneComponent::onCleanup()
{
	
}
