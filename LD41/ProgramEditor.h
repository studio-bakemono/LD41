#pragma once
#include "GraphicsComponent.h"
#include "SDL_ttf.h"

class ProgramEditor :
	public GraphicsComponent
{
private:
	SDL_Texture* arrowUp;
	SDL_Texture* arrowDown;
	TTF_Font* font;
protected:
	void onUpdate(App* game);
	void onCleanup();
public:
	std::vector<class ProgramEditorRow *> rows;
	ProgramEditor(SDL_Renderer* renderer);
	~ProgramEditor();
};

