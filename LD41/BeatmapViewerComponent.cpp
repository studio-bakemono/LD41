#include "BeatmapViewerComponent.h"
#include "Turing.h"


void BeatmapViewerComponent::onUpdate(App * game)
{
	for (int i = 0; i < bytePanels.size(); i++)
	{
		bytePanels[i]->update(game);
	}
}

void BeatmapViewerComponent::onCleanup()
{
	for (int i = 0; i < bytePanels.size(); i++)
	{
		bytePanels[i]->cleanup();
	}
}

BeatmapViewerComponent::BeatmapViewerComponent(SDL_Renderer* renderer, int posx, int posy, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		bytePanels.push_back(new BytePanelComponent(renderer, 160, posx, posy+=28, 0));
	}
}


BeatmapViewerComponent::~BeatmapViewerComponent()
{

}

ProgramBeatmapViewerComponent::ProgramBeatmapViewerComponent(SDL_Renderer * renderer, int posx, int posy, int rows) : BeatmapViewerComponent(renderer, posx, posy, rows)
{
	
}

void ProgramBeatmapViewerComponent::onTapeUpdated(std::vector<unsigned char> tape)
{
	std::vector<unsigned char> tapeCopy(tape);
	Turing t(tapeCopy);
	for (int i = 0; i < 16; i++) 
	{
		BS bits = t.tick();
		for (int j = 0; j < 8; j++) 
		{
			bytePanels[i]->bitButtons[j]->flip(bits[j]);
		}
	}
}
