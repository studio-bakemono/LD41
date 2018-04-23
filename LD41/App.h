#pragma once
#include <SDL_ttf.h>

#include <string>
#include "NeneComponent.h"
#include "InputComponent.h"
#include "SoundsComponent.h"
#include "TuringComponent.h"
#include "BytePanelComponent.h"
#include "BeatmapViewerComponent.h"
#include "ProgramEditor.h"
#include "Tape.h"

class App : public InputComponentObserver
{
private:
	SDL_Surface * nene = nullptr;
	NeneComponent* neneTex = nullptr;
	InputComponent* input = nullptr;
	SoundsComponent* sounds = nullptr;
	TuringComponent* turing = nullptr;
	BytePanelComponent* bytePanel = nullptr;
	BeatmapViewerComponent* programOutput = nullptr;
	BeatmapViewerComponent* patternOutput = nullptr;
	ProgramEditor* programEditor = nullptr;

	bool startup();
	void Load();
	void Update();
	void Render();
	void cleanup();

public:
	Tape tape;

	void onInputComponentUpdated(InputData data);
	SDL_Window * window = nullptr;
	SDL_Surface* screenSurface = nullptr;
	SDL_Renderer* renderer = nullptr;

	//Event handler
	SDL_Event e;

	bool running;

	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	const int FRAMERATE = 60;
	int frametime = 0;

	App();
	~App();
	void run();

};

