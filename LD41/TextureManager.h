/*#pragma once

#include <iostream>
#include <vector>
#include "SDL.h"

#include <map>
#include <memory>

using std::vector;
using std::map;

struct TextureManager
{

	enum Atlases {
		Player,
		Tiles
	};

	map<Atlases, std::string> atlas_locations;


	vector<SDL_Surface*> surfaces;
	vector<SDL_Texture*> textures;


	SDL_Renderer* _renderer;


	void load() {
		/*
		atlas_locations.insert(
			std::pair<Atlases, std::string>(Atlases::Player, "ass.bmp"));

		for (auto a : atlas_locations) {
			surfaces.push_back( SDL_LoadBMP(a.second.c_str()) );
		}
		*/

	}

	void convert_to_textures() {
		for (auto s : surfaces) {
			textures.push_back(SDL_CreateTextureFromSurface(_renderer, s));
		}
	}

	void cleanup();

	TextureManager();
	TextureManager::TextureManager(SDL_Renderer& r);
	~TextureManager();
};

*/