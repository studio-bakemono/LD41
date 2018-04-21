#pragma once
#include "GraphicsComponent.h"
#include "Graphics.h"

class NeneComponent :
	public GraphicsComponent
{
protected:
	void onUpdate(App* game);
	void onCleanup();
public:
	NeneComponent(SDL_Renderer* renderer);
	~NeneComponent();
};

