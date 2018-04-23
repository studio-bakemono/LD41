#include "App.h"
#include "Graphics.h"
#include "ProgramEditorRow.h"

App::App()
{
}

//					AYO, HOL UP! THIS THE STARTUP SHIEEEEET??!?
bool App::startup()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | IMG_INIT_PNG) < 0)
	{
		//	LogError();
		return false;
	}
	if (TTF_Init() == -1)
	{
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
		return false;
	}

	//Initialize SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		return false;
	}
	running = true;

	window = SDL_CreateWindow("Test", 200, 200, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	screenSurface = SDL_GetWindowSurface(window);
	if (!screenSurface)
	{
		//LogError(); 
		return false;
	}
	return true;

}


// THIS IS THE LOAD FUNCTION IT LOADS SHIT  *BLOWS MIND*
void App::Load() {
	//LOAD RESOURCES HERE
	neneTex = new NeneComponent(renderer);

	programEditor = new ProgramEditor(renderer);
	sounds = new SoundsComponent();
	bytePanel = new BytePanelComponent(renderer, 640, 0, 16, 200);
	programOutput = new ProgramBeatmapViewerComponent(renderer, 16, 100, 16);
	patternOutput = new BeatmapViewerComponent(renderer, 192, 100, 16);
	turing = new TuringComponent();
	turing->addObserver(bytePanel);
	turing->addObserver(sounds);
	tape.addObserver(programOutput);
	input = new InputComponent();
	input->addObserver(this);
	for (int i = 0; i < programEditor->rows.size(); i++) {
		input->addObserver(programEditor->rows[i]);
		tape.addObserver(programEditor->rows[i]);
	}
}

void App::Update()
{
	input->update(this);
	sounds->update(this);
	turing->update(this);
	SDL_Delay(1 / FRAMERATE);
	Render();

}


//				WE WUZ RENDERAN N SHIEEEEET
void App::Render()
{
	SDL_RenderClear(renderer);
	//	CLEAR SCREEN AND RENDER STUFF DOWN HERE
	neneTex->update(this);
	bytePanel->update(this);

	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xD0);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	SDL_Rect programOutputRect = { 16, 90, 164, 482 };
	SDL_RenderFillRect(renderer, &programOutputRect);

	SDL_Rect patternOutputRect = { 192, 90, 164, 482 };
	SDL_RenderFillRect(renderer, &patternOutputRect);

	SDL_Rect programEditorRect = { 368, 90, 420, 482 };
	SDL_RenderFillRect(renderer, &programEditorRect);

	programEditor->update(this);
	programOutput->update(this);
	patternOutput->update(this);

	//STOP RENDERING SUTFF HERE	
	SDL_RenderPresent(renderer);
	SDL_Delay(1000 / 60);
}

void App::run()
{
	//Do startup operations
	startup();
	Load();
	while (running)
	{
		Update();
	}
	//cleanup();
}

void App::cleanup()
{
	SDL_FreeSurface(screenSurface);
	screenSurface = nullptr;

	SDL_DestroyWindow(window);
	window = nullptr;

	SDL_DestroyRenderer(renderer);
	renderer = nullptr;

	SDL_FreeSurface(nene);
	nene = nullptr;

	delete neneTex;
	delete input;

	SDL_Quit();
	TTF_Quit();
	IMG_Quit();
}

App::~App()
{
	cleanup();
}

void App::onInputComponentUpdated(InputData data)
{
	if (data.quit)
	{
		running = false;
	}
}
