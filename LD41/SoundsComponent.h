#pragma once
#include "Component.h"
#include <SDL_mixer.h>

class SoundsComponent :
	public Component
{
private:
	Mix_Chunk * chunk;
	int next_beat = 120;
protected:
	void onUpdate(App* game);
	void onCleanup();
public:
	SoundsComponent();
	~SoundsComponent();
};

