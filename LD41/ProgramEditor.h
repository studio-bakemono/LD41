#pragma once
#include "GraphicsComponent.h"
#include "SDL_ttf.h"

class ProgramEditor :
	public GraphicsComponent
{
private:
	std::vector<class ProgramEditorRow *> rows;
	SDL_Texture* arrowUp;
		SDL_Texture* arrowDown;
		TTF_Font* font;
protected:
	void onUpdate(App* game);
	void onCleanup();
public:
	ProgramEditor(SDL_Renderer* renderer);
	~ProgramEditor();
};

