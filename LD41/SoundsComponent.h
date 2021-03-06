#pragma once
#include "Component.h"
#include <SDL_mixer.h>
#include "TuringComponent.h"

class SoundsComponent :
	public Component,
	public TuringComponentObserver
{
protected:
	void onTuringComponentUpdated(TuringComponentInputData data);
private:
	Mix_Chunk * chunk1;
	Mix_Chunk * chunk2;
	Mix_Chunk * chunk3;
	Mix_Chunk * chunk4;
	Mix_Chunk * chunk5;
	Mix_Chunk * chunk6;
	Mix_Chunk * chunk7;
	Mix_Chunk * chunk8;
	void playSound(int b);
protected:
	void onUpdate(App* game);
	void onCleanup();
public:
	SoundsComponent();
	~SoundsComponent();
};

