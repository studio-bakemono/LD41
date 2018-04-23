#include "NumberSpinnerComponent.h"
#include "App.h"

#include <sstream>
#include <iomanip>


void NumberSpinnerComponent::updateText()
{
	std::stringstream ss;
	ss << std::setw(3) << std::setfill('0') << currentValue;
	std::string s = ss.str();

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, s.c_str(), color);
	tex = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	//Don't forget too free your surface and texture
	SDL_FreeSurface(surfaceMessage);

}

void NumberSpinnerComponent::onUpdate(App * game)
{
	SDL_RenderCopy(game->renderer, arrowUp, NULL, &arrowUpRect);
	SDL_RenderCopy(game->renderer, arrowDown, NULL, &arrowDownRect);
	
	SDL_SetRenderDrawColor(game->renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawRect(game->renderer, &contour);
	SDL_RenderCopy(game->renderer, tex, NULL, &msg_rect);

}

void NumberSpinnerComponent::onCleanup()
{
	SDL_DestroyTexture(this->arrowUp);
	SDL_DestroyTexture(this->arrowDown);
}

NumberSpinnerComponent::NumberSpinnerComponent(SDL_Renderer* renderer, SDL_Texture* arrowUp, SDL_Texture* arrowDown, TTF_Font * font, SDL_Color color, int posx, int posy)
{
	this->renderer = renderer;
	this->arrowUp = arrowUp;
	this->arrowDown = arrowDown;
	this->color = color;
	this->font = font;

	arrowUpRect.h = 24;
	arrowUpRect.w = 24;
	arrowUpRect.x = posx + 4;
	arrowUpRect.y = posy + 4;

	arrowDownRect.h = 24;
	arrowDownRect.w = 24;
	arrowDownRect.x = posx + 144;
	arrowDownRect.y = posy + 4;

	contour.h = 32;
	contour.w = 172;
	contour.x = posx;
	contour.y = posy;

	msg_rect.x = posx + 48;
	msg_rect.y = posy + 4;
	msg_rect.w = 80;
	msg_rect.h = 28;

	updateText();
}

NumberSpinnerComponent::~NumberSpinnerComponent()
{
	cleanup();
}

int NumberSpinnerComponent::getValue()
{
	return currentValue;
}

void NumberSpinnerComponent::setValue(int value)
{
	currentValue = value;
	updateText();
}

void NumberSpinnerComponent::onInputComponentUpdated(InputData data)
{
	if (data.mouseClicked)
	{
		if (in_rect(data.mouseX, data.mouseY, &arrowUpRect)) {
			currentValue++;
			if (currentValue > 255) 
			{
				currentValue = 0;
			}
			updateText();
		}
		if (in_rect(data.mouseX, data.mouseY, &arrowDownRect)) {
			currentValue--;
			if (currentValue < 0) 
			{
				currentValue = 255;
			}
			updateText();
		}
	}

}
