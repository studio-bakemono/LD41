#pragma once
#include "GraphicsComponent.h"
#include "BytePanelComponent.h"
#include <vector>
#include "Tape.h"

class BeatmapViewerComponent :
	public GraphicsComponent
{
protected:
	std::vector<class BytePanelComponent*> bytePanels;
	void onUpdate(App* game);
	void onCleanup();

public:
	BeatmapViewerComponent(SDL_Renderer* renderer, int posx, int posy, int rows);
	~BeatmapViewerComponent();
};

class ProgramBeatmapViewerComponent :
	public BeatmapViewerComponent,
	public TapeObserver
{
public:
	ProgramBeatmapViewerComponent(SDL_Renderer* renderer, int posx, int posy, int rows);

	// Inherited via TapeObserver
	virtual void onTapeUpdated(std::vector<unsigned char> tape) override;
};