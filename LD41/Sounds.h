#pragma once

#include <SDL.h>
#include <string>
#include <SDL_mixer.h>

#define RESOURCES_PATH "../resources/"

namespace Graphics {
	Mix_Chunk* LoadSound(std::string fileName);
}

