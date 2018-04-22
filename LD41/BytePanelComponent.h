#pragma once
#include "GraphicsComponent.h"
#include "BitButtonComponent.h"
#include "TuringComponent.h"
#include <vector>

class BytePanelComponent :
	public GraphicsComponent,
	public TuringComponentObserver
{
private:
	BitButtonComponent* bit0 = nullptr;
	BitButtonComponent* bit1 = nullptr;
	BitButtonComponent* bit2 = nullptr;
	BitButtonComponent* bit3 = nullptr;
	BitButtonComponent* bit4 = nullptr;
	BitButtonComponent* bit5 = nullptr;
	BitButtonComponent* bit6 = nullptr;
	BitButtonComponent* bit7 = nullptr;
	std::vector<class BitButtonComponent*> bitButtons;

protected:
	void onUpdate(App* game);
	void onCleanup();
	void onTuringComponentUpdated(TuringComponentInputData data);
public:
	BytePanelComponent(SDL_Renderer* renderer);
	~BytePanelComponent();
};

