#include "NeneComponent.h"

NeneComponent::NeneComponent(SDL_Renderer* renderer)
{
	tex = Graphics::LoadTexture(renderer, "../resources/button.bmp");
	if (!tex) {
		SDL_GetError();
	}

}
NeneComponent::~NeneComponent()
{
	cleanup();
}

void NeneComponent::onUpdate(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, tex, NULL, NULL);
}

void NeneComponent::onCleanup()
{
	
}
