#pragma once
#include "GraphicsComponent.h"
#include "BytePanelComponent.h"
#include <vector>

class BeatmapViewerComponent :
	public GraphicsComponent
{
private:
	std::vector<class BytePanelComponent*> bytePanels;
protected:
	void onUpdate(App* game);
	void onCleanup();

public:
	BeatmapViewerComponent(SDL_Renderer* renderer, int posx, int posy, int rows);
	~BeatmapViewerComponent();
};

