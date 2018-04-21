#include "GraphicsComponent.h"

void GraphicsComponent::update(SDL_Renderer* renderer)
{
	onUpdate(renderer);
}

void GraphicsComponent::cleanup()
{
	SDL_DestroyTexture(tex);
}

GraphicsComponent::~GraphicsComponent()
{
	cleanup();
}
