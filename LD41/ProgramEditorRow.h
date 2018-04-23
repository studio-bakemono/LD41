#pragma once
#include "GraphicsComponent.h"
#include "NumberSpinnerComponent.h"
#include "OperatorButtonComponent.h"

class ProgramEditorRow :
	public GraphicsComponent
{
private:
	OperatorButtonComponent * opButton;
	NumberSpinnerComponent * value1;
	NumberSpinnerComponent * value2;

protected:
	void onUpdate(App* game);
	void onCleanup();
public:
	ProgramEditorRow(SDL_Renderer * renderer, SDL_Texture* arrowUp, SDL_Texture* arrowDown, TTF_Font* font, int posx, int posy);
	~ProgramEditorRow();
};

