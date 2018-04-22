#include "BeatmapViewerComponent.h"



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
		bytePanels.push_back(new BytePanelComponent(renderer, 160, posx, posy+=28, 100));
	}
}


BeatmapViewerComponent::~BeatmapViewerComponent()
{

}
