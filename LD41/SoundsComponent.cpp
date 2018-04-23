#include "SoundsComponent.h"
#include "Sounds.h"


void SoundsComponent::onTuringComponentUpdated(TuringComponentInputData data)
{
	for (int b = 0; b<BEATCOUNT; b++) {
		if (data.bits[b]) {
			//playSound(b);
		}
	}
}

void SoundsComponent::playSound(int b)
{
	switch (b)
	{
	case 0:
		Mix_PlayChannel(-1, chunk1, 0);
		break;
	case 1:
		Mix_PlayChannel(-1, chunk2, 0);
		break;
	case 2:
		Mix_PlayChannel(-1, chunk3, 0);
		break;
	case 3:
		Mix_PlayChannel(-1, chunk4, 0);
		break;
	case 4:
		Mix_PlayChannel(-1, chunk5, 0);
		break;
	case 5:
		Mix_PlayChannel(-1, chunk6, 0);
		break;
	case 6:
		Mix_PlayChannel(-1, chunk7, 0);
		break;
	case 7:
		Mix_PlayChannel(-1, chunk8, 0);
		break;
	}
}

void SoundsComponent::onUpdate(App * game) {}

void SoundsComponent::onCleanup()
{
	Mix_FreeChunk(chunk1);
	Mix_FreeChunk(chunk2);
	Mix_FreeChunk(chunk3);
	Mix_FreeChunk(chunk4);
	Mix_FreeChunk(chunk5);
	Mix_FreeChunk(chunk6);
	Mix_FreeChunk(chunk7);
	Mix_FreeChunk(chunk8);
	chunk1 = NULL;
	chunk2 = NULL;
	chunk3 = NULL;
	chunk4 = NULL;
	chunk5 = NULL;
	chunk6 = NULL;
	chunk7 = NULL;
	chunk8 = NULL;
}

SoundsComponent::SoundsComponent()
{
	chunk1 = Sounds::LoadSound("switch1.wav");
	chunk2 = Sounds::LoadSound("switch2.wav");
	chunk3 = Sounds::LoadSound("switch3.wav");
	chunk4 = Sounds::LoadSound("switch4.wav");
	chunk5 = Sounds::LoadSound("switch5.wav");
	chunk6 = Sounds::LoadSound("switch6.wav");
	chunk7 = Sounds::LoadSound("switch7.wav");
	chunk8 = Sounds::LoadSound("switch8.wav");
}

SoundsComponent::~SoundsComponent()
{
}
