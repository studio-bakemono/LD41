#pragma once

#include <SDL.h>
#include<SDL_image.h>
#include <string>

#define RESOURCES_PATH "../resources/"

namespace Graphics {
		SDL_Texture* LoadTexture(SDL_Renderer* renderer, std::string fileName);
}

