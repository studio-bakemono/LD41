#include "OperatorButtonComponent.h"
#include "App.h"
#include <string>

void OperatorButtonComponent::cycleOperator()
{
	switch (currentOperator)
	{
	case '+':
		currentOperator = '-';
		break;
	case '-':
		currentOperator = '*';
		break;
	case '*':
		currentOperator = '/';
		break;
	case '/':
		currentOperator = '%';
		break;
	case '%':
		currentOperator = 'c';
		break;
	case 'c':
		currentOperator = '=';
		break;
	case '=':
		currentOperator = 'z';
		break;
	case 'z':
		currentOperator = '+';
		break;
	}

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, &currentOperator, color);
	tex = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	//Don't forget too free your surface and texture
	SDL_FreeSurface(surfaceMessage);
}

void OperatorButtonComponent::onUpdate(App * game)
{
	SDL_RenderCopy(game->renderer, tex, NULL, &msg_rect);
	SDL_SetRenderDrawColor(game->renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawRect(game->renderer, &contour);
}

void OperatorButtonComponent::onCleanup()
{

}

OperatorButtonComponent::OperatorButtonComponent(SDL_Renderer* renderer, TTF_Font* font, SDL_Color color, int posx, int posy, int width, int height)
{
	msg_rect.x = posx + 4;
	msg_rect.y = posy + 4;
	msg_rect.w = width - 8;
	msg_rect.h = height - 8;
	contour.x = posx;
	contour.y = posy;
	contour.w = width;
	contour.h = height;

	this->font = font;
	this->renderer = renderer;
	this->color = color;
	cycleOperator();
}


OperatorButtonComponent::~OperatorButtonComponent()
{
	
}

void OperatorButtonComponent::setValue(char op)
{
	currentOperator = op;
}

char OperatorButtonComponent::getValue()
{
	return currentOperator;
}

void OperatorButtonComponent::onInputComponentUpdated(InputData data)
{
	if (data.mouseClicked) 
	{
		if (in_rect(data.mouseX, data.mouseY, &msg_rect)) {
			cycleOperator();
		}
	}
}
