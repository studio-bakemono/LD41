#pragma once
#include "GraphicsComponent.h"
#include "SDL_ttf.h"
#include "InputComponent.h"

class NumberSpinnerComponent :
	public GraphicsComponent,
	public InputComponentObserver
{
private:
	SDL_Texture * arrowUp;
	SDL_Texture * arrowDown;
	SDL_Rect arrowUpRect;
	SDL_Rect arrowDownRect;
	SDL_Color color;
	SDL_Rect contour;
	SDL_Rect msg_rect;
	int currentValue;

	SDL_Renderer* renderer;
	TTF_Font* font;
	void updateText();

protected:
	void onUpdate(App* game);
	void onCleanup();
public:
	NumberSpinnerComponent(SDL_Renderer* renderer, SDL_Texture* arrowUp, SDL_Texture* arrowDown, TTF_Font * font, SDL_Color color, int posx, int posy);
	~NumberSpinnerComponent();
	int getValue();
	void setValue(int value);

	// Inherited via InputComponentObserver
	virtual void onInputComponentUpdated(InputData data) override;
};
