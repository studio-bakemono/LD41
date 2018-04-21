#pragma once
#include "SDL.h"
#include "InputManager.h"
#include "vector2.h"

class Player
{
public:

	SDL_Renderer* renderer = nullptr;
	SDL_Rect rect;


	void load() {
		
	}

	void update() {

	}

	void render() {

	}

	void cleanup() {
		renderer = nullptr;

	}


	Player(SDL_Surface* s, SDL_Renderer* ren)
		:renderer(ren) {}

	~Player();
};

