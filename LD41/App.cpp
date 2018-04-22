#include "App.h"
#include "Graphics.h"

App::App()
{
}

//					AYO, HOL UP! THIS THE STARTUP SHIEEEEET??!?
bool App::startup()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		//	LogError();
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
	sounds = new SoundsComponent();
	neneTex = new NeneComponent(renderer);
	input = new InputComponent();
	input->addObserver(this);
}

void App::Update()
{
	input->update(this);
	sounds->update(this);
	SDL_Delay(1 / FRAMERATE);
	Render();

}


//				WE WUZ RENDERAN N SHIEEEEET
void App::Render()
{
	SDL_RenderClear(renderer);
	//	CLEAR SCREEN AND RENDER STUFF DOWN HERE
	neneTex->update(this);
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
