#include "SoundsComponent.h"
#include "Sounds.h"


void SoundsComponent::onUpdate(App * game)
{
	next_beat -= 1;
	if (next_beat == 0) 
	{
		next_beat = 30;
		Mix_PlayChannel(-1, chunk, 0);

	}
}

void SoundsComponent::onCleanup()
{
	Mix_FreeChunk(chunk);
	chunk = NULL;
}

SoundsComponent::SoundsComponent()
{
	chunk = Sounds::LoadSound("click5.wav");
}

SoundsComponent::~SoundsComponent()
{
}
