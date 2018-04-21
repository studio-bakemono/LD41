// randomGL.cpp : Defines the entry point for the console application.
//


#include <SDL.h>
//#include <SDL_image.h>
#include <stdio.h>
#include <assert.h>

#include "App.h"

App game;

int main(int argc, char* args[])
{
	game.run();
	return 0;

}