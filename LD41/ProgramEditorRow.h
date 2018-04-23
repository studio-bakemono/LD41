#pragma once
#include "GraphicsComponent.h"
#include "NumberSpinnerComponent.h"
#include "OperatorButtonComponent.h"
#include "Tape.h"
#include "InputComponent.h"

class ProgramEditorRow :
	public GraphicsComponent,
	public TapeObserver,
	public InputComponentObserver
{
private:
	OperatorButtonComponent * opButton;
	NumberSpinnerComponent * value1;
	NumberSpinnerComponent * value2;
	int rowPosition;

protected:
	void onUpdate(App* game);
	void onCleanup();
public:
	ProgramEditorRow(SDL_Renderer * renderer, SDL_Texture* arrowUp, SDL_Texture* arrowDown, TTF_Font* font, int posx, int posy, int rowPosition);
	~ProgramEditorRow();
	

	// Inherited via TapeObserver
	virtual void onTapeUpdated(std::vector<unsigned char> tape) override;


	// Inherited via InputComponentObserver
	virtual void onInputComponentUpdated(InputData data) override;

};

