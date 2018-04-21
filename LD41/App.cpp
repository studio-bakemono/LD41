#include "App.h"
#include "Graphics.h"

App::App()
{
}

//					AYO, HOL UP! THIS THE STARTUP SHIEEEEET??!?
bool App::startup()
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      //	LogError();
      return false;
    }

  running = true;

  window = SDL_CreateWindow("Test", 200, 200,
			    WINDOW_WIDTH, WINDOW_HEIGHT,
			    SDL_WINDOW_SHOWN);

  renderer = SDL_CreateRenderer(
				window, -1, SDL_RENDERER_ACCELERATED);

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

  nene_tex =  Graphics::LoadTexture(renderer, "button.bmp");
  if (!nene_tex) {
    SDL_GetError();
  }
  
}

void App::Update()
{

  
  //SDL_GetMouseState(&mouse_position.x, &mouse_position.y);
  while (SDL_PollEvent(&e) != 0)
    {
      switch (e.type)
	{
	case SDL_MOUSEMOTION:
	  printf("THERE IS MOUSE MOTION\n mouse position: (%d, %d)\n",
		 e.motion.x, e.motion.y);
	  break;
	  
	case SDL_KEYDOWN:
	  printf("KEYBOARD INPUT FROM KEY: %d \n", e.key.keysym.sym);
	  
	  break;
	  

	case SDL_MOUSEBUTTONDOWN:
	  printf("MOUSE INPUT FROM KEY: %d \n", e.button.button);
	  break;
	  
	case SDL_MOUSEBUTTONUP:
	  break;
	  
	case SDL_QUIT:
	  
	  running = false;
	  
	  break;
	}
      
      SDL_Delay(1 / FRAMERATE);
    }
  
  
  
  
  
   Render();
  
}





//				WE WUZ RENDERAN N SHIEEEEET
void App::Render()
{
  SDL_RenderClear(renderer);
  //	CLEAR SCREEN AND RENDER STUFF DOWN HERE
  
  SDL_RenderCopy(renderer, nene_tex, NULL, NULL);
  
  //STOP RENDERING SUTFF HERE	
  SDL_RenderPresent(renderer);
  SDL_Delay(1/60);
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
  nene= nullptr;

  SDL_DestroyTexture(nene_tex);
  nene_tex = nullptr;

  
  SDL_Quit();
}

App::~App()
{
  cleanup();
}
