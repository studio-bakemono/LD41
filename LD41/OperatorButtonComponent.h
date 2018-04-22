#pragma once
#include "GraphicsComponent.h"
class OperatorButtonComponent :
	public GraphicsComponent
{
private:
	char currentOperator;
	int posx;
	int posy;
protected:
	void onUpdate(App* game);
	void onCleanup();
public:
	OperatorButtonComponent(SDL_Renderer* renderer, int posx, int posy);
	~OperatorButtonComponent();
};
