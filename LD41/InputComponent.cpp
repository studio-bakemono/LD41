#include "InputComponent.h"
#include "App.h"
#include <algorithm>

InputComponent::InputComponent()
{

}

InputComponent::~InputComponent()
{

}

void InputComponent::notifyObservers()
{
}

void InputComponent::onUpdate(App* game)
{
	SDL_Event e = game->e;
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
			game->running = false;
			break;
		}
	}
}

void InputComponent::onCleanup()
{
	delete observers;
}

void InputComponent::addObserver(InputComponentObserver* observer)
{
	observers->push_back(observer);
}

void InputComponent::removeObserver(InputComponentObserver* observer)
{
	observers->erase(std::remove(observers->begin(), observers->end(), observer), observers->end());
}

bool InputData::hasQuit()
{
	return quit;
}
