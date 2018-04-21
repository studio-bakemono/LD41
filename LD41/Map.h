#pragma once

#include "SDL.h"
#include <iostream>
#include <vector>
using std::vector;

struct Map {

	const int TILE_WIDTH =  32;
	const int TILE_HEIGHT = 32;

	SDL_Surface* atlas = nullptr;

	vector<vector<int>>map;

	void load_surface( std::string surf_name )
	{
		atlas = SDL_LoadBMP( surf_name.c_str() );
	}

	void draw_tilemap(SDL_Surface* screen_surf)
	{
		//SDL_Rect pos{0, 0, TILE_WIDTH, TILE_HEIGHT};
		for (int y = 0; y < map.size(); y++)
		{
			for (int x = 0; x < map[y].size() ; x++)
			{
				if (map[y][x] == 1)
				{				
					SDL_BlitScaled(atlas, NULL, screen_surf, new SDL_Rect{ x*TILE_WIDTH, y*TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT} );
				}
			}
		}
	}


	void clean_up()
	{
		SDL_FreeSurface(atlas);
		atlas = nullptr;
	}


	~Map()
	{
		//690, 115
		SDL_FreeSurface(atlas);
		atlas = nullptr;
	}

};
