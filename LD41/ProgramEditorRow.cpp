#include "ProgramEditorRow.h"



void ProgramEditorRow::onUpdate(App * game)
{
	opButton->update(game);
	value1->update(game);
	value2->update(game);
}

void ProgramEditorRow::onCleanup()
{

}

ProgramEditorRow::ProgramEditorRow(SDL_Renderer * renderer, SDL_Texture* arrowUp, SDL_Texture* arrowDown, TTF_Font* font, int posx, int posy)
{
	SDL_Color color = { 255, 255, 255, 255 };
	opButton = new OperatorButtonComponent(renderer, font, { 255, 255, 255, 255 }, posx, posy, 32, 32);
	value1 = new NumberSpinnerComponent(renderer, arrowUp, arrowDown, font, color, posx + 48, posy);
	value2 = new NumberSpinnerComponent(renderer, arrowUp, arrowDown, font, color, posx + 230, posy);
}


ProgramEditorRow::~ProgramEditorRow()
{

}
