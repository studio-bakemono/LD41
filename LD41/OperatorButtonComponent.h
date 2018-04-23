#pragma once
#include "GraphicsComponent.h"
#include <SDL_ttf.h>
#include "InputComponent.h"

class OperatorButtonComponent :
	public GraphicsComponent,
	public InputComponentObserver
{
private:
	char currentOperator = '%';
	SDL_Rect msg_rect;
	SDL_Rect contour;
	SDL_Color color;
	SDL_Renderer* renderer;
	TTF_Font* font;
	void cycleOperator();

protected:
	void onUpdate(App* game);
	void onCleanup();
public:
	OperatorButtonComponent(SDL_Renderer* renderer, TTF_Font* font, SDL_Color color, int posx, int posy, int width, int height);
	~OperatorButtonComponent();
	void setValue(char op);
	char getValue();

	// Inherited via InputComponentObserver
	virtual void onInputComponentUpdated(InputData data) override;
};

