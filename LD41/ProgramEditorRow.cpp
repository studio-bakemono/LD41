#include "ProgramEditorRow.h"
#include "App.h"

void ProgramEditorRow::onUpdate(App * game)
{
	opButton->update(game);
	value1->update(game);
	value2->update(game);
	
	if (opButton->getValue() != game->tape.getValue(rowPosition * 3))
	{
		game->tape.changeAdress(rowPosition * 3, opButton->getValue());
	}
	if (value1->getValue() != game->tape.getValue(rowPosition * 3 + 1))
	{
		game->tape.changeAdress(rowPosition * 3 + 1, opButton->getValue());
	}
	if (value2->getValue() != game->tape.getValue(rowPosition * 3 + 2))
	{
		game->tape.changeAdress(rowPosition * 3 + 2, opButton->getValue());
	}

}

void ProgramEditorRow::onCleanup()
{

}

ProgramEditorRow::ProgramEditorRow(SDL_Renderer * renderer, SDL_Texture* arrowUp, SDL_Texture* arrowDown, TTF_Font* font, int posx, int posy, int rowPosition)
{
	this->rowPosition = rowPosition;
	SDL_Color color = { 255, 255, 255, 255 };
	opButton = new OperatorButtonComponent(renderer, font, { 255, 255, 255, 255 }, posx, posy, 32, 32);
	value1 = new NumberSpinnerComponent(renderer, arrowUp, arrowDown, font, color, posx + 48, posy);
	value2 = new NumberSpinnerComponent(renderer, arrowUp, arrowDown, font, color, posx + 230, posy);
}

ProgramEditorRow::~ProgramEditorRow()
{

}

void ProgramEditorRow::onTapeUpdated(std::vector<unsigned char> tape)
{
	if (opButton->getValue() != tape[rowPosition * 3])
	{
		opButton->setValue(tape[rowPosition * 3]);
	}
	if (value1->getValue() != tape[rowPosition * 3 + 1])
	{
		value1->setValue(tape[rowPosition * 3 + 1]);
	}
	if (value2->getValue() != tape[rowPosition * 3 + 2])
	{
		value2->setValue(tape[rowPosition * 3 + 2]);
	}
}

void ProgramEditorRow::onInputComponentUpdated(InputData data)
{
	opButton->onInputComponentUpdated(data);
	value1->onInputComponentUpdated(data);
	value2->onInputComponentUpdated(data);
}
