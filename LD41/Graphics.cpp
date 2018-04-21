#pragma once

#include "Graphics.h"

namespace Graphics {

	SDL_Texture* LoadTexture(SDL_Renderer* renderer, std::string fileName) {
		SDL_Surface* s = SDL_LoadBMP((RESOURCES_PATH + fileName).c_str());
		if (!s) {
			printf("%s", SDL_GetError());
		}
		SDL_Texture* t = SDL_CreateTextureFromSurface(renderer, s);
		if (!t) {
			SDL_GetError();
		}
		SDL_FreeSurface(s);
		return t;
	}

}

