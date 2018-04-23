#include "ProgramEditor.h"
#include "ProgramEditorRow.h"
#include "Graphics.h"

void ProgramEditor::onUpdate(App * game)
{
	for (int i = 0; i < 12; i++)
	{
		rows[i]->update(game);
	}
}

void ProgramEditor::onCleanup()
{
}

ProgramEditor::ProgramEditor(SDL_Renderer* renderer)
{

	int posy = 90;
	arrowUp = Graphics::LoadTexture(renderer, "arrow_up.png");
	arrowDown = Graphics::LoadTexture(renderer, "arrow_down.png");
	font = TTF_OpenFont("../resources/PressStart2P.ttf", 24);

	for (int i = 0; i < 12; i++)
	{
		rows.push_back(new ProgramEditorRow(renderer, arrowUp, arrowDown, font, 380, posy+=36, i));
	}
}


ProgramEditor::~ProgramEditor()
{
	SDL_DestroyTexture(arrowUp);
	SDL_DestroyTexture(arrowDown);
	TTF_CloseFont(font);

}
