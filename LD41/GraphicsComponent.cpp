#include "GraphicsComponent.h"


GraphicsComponent::~GraphicsComponent()
{
	SDL_DestroyTexture(tex);
}

