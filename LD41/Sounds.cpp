#pragma once

#include "Sounds.h"

namespace Sounds {

	Mix_Chunk* LoadSound(std::string fileName)
	{
		Mix_Chunk* chunk = Mix_LoadWAV((RESOURCES_PATH + fileName).c_str());
		if (chunk == NULL)
		{
			printf("Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		}
		return chunk;
	}

}
