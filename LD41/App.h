#pragma once

#include "EntityManager.h"
#include "Entity.h"
#include <string>
#include "NeneComponent.h"
#include "InputComponent.h"
#include "SoundsComponent.h"
#include "TuringComponent.h"
#include "BytePanelComponent.h"
#include "BeatmapViewerComponent.h"

//#include "TextureManager.h"

#include "Player.h"

class App : public InputComponentObserver
{
public:

	void onInputComponentUpdated(InputData data);
	SDL_Window * window = nullptr;
	SDL_Surface* screenSurface = nullptr;
	SDL_Renderer* renderer = nullptr;

	SDL_Surface* nene = nullptr;
	NeneComponent* neneTex = nullptr;
	InputComponent* input = nullptr;
	SoundsComponent* sounds = nullptr;
	TuringComponent* turing = nullptr;
	BytePanelComponent* bytePanel = nullptr;
	BeatmapViewerComponent* programOutput = nullptr;
	BeatmapViewerComponent* patternOutput = nullptr;

	//Event handler
	SDL_Event e;

	bool running;

	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	const int FRAMERATE = 60;
	int frametime = 0;

	App();

	bool startup();

	void Load();

	void Update();

	void Render();

	void cleanup();

	void run();

	~App();
};

