#include "BytePanelComponent.h"



void BytePanelComponent::onUpdate(App * game)
{
	for (int b = 0; b<BEATCOUNT; b++) {
		bitButtons[b]->update(game);
	}
}

void BytePanelComponent::onCleanup()
{

}

void BytePanelComponent::onTuringComponentUpdated(TuringComponentInputData data)
{
	for (int b = 0; b<BEATCOUNT; b++) {
		bitButtons[b]->flip(data.bits[b]);
	}
}

BytePanelComponent::BytePanelComponent(SDL_Renderer* renderer, int panelsize, int posx, int posy, int alphaOff)
{

	int buttonspace = panelsize / 8;
	int position = posx + buttonspace / 5;
	int buttonsize = buttonspace - buttonspace / 5;
	
	bit0 = new BitButtonComponent("brown_button.png", renderer, position, posy, buttonsize, alphaOff);
	bit1 = new BitButtonComponent("red_button.png", renderer, position += buttonspace, posy, buttonsize, alphaOff);
	bit2 = new BitButtonComponent("orange_button.png", renderer, position += buttonspace, posy, buttonsize, alphaOff);
	bit3 = new BitButtonComponent("yellow_button.png", renderer, position += buttonspace, posy, buttonsize, alphaOff);
	bit4 = new BitButtonComponent("green_button.png", renderer, position += buttonspace, posy, buttonsize, alphaOff);
	bit5 = new BitButtonComponent("lightblue_button.png", renderer, position += buttonspace, posy, buttonsize, alphaOff);
	bit6 = new BitButtonComponent("blue_button.png", renderer, position += buttonspace, posy, buttonsize, alphaOff);
	bit7 = new BitButtonComponent("purple_button.png", renderer, position += buttonspace, posy, buttonsize, alphaOff);
	bitButtons.push_back(bit0);
	bitButtons.push_back(bit1);
	bitButtons.push_back(bit2);
	bitButtons.push_back(bit3);
	bitButtons.push_back(bit4);
	bitButtons.push_back(bit5);
	bitButtons.push_back(bit6);
	bitButtons.push_back(bit7);
}


BytePanelComponent::~BytePanelComponent()
{

}
