#include "GraphicsComponent.h"


GraphicsComponent::GraphicsComponent()
{
}




void GraphicsComponent::cleanup()
{
	SDL_FreeSurface(&tex);
}

GraphicsComponent::~GraphicsComponent()
{
	cleanup();
}
