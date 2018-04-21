#pragma once
#include "GraphicsComponent.h"
#include "Graphics.h"

class NeneComponent :
	public GraphicsComponent
{
protected:
	void onUpdate(SDL_Renderer* renderer);
	void onCleanup();
public:
	NeneComponent(SDL_Renderer* renderer);
	~NeneComponent();
	
};

