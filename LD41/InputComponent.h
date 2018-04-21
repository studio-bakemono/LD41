#pragma once
#include "Component.h"

class InputComponent: public Component
{
protected:
	void onUpdate(App* game);
	void onCleanup();
public:
	InputComponent();
	~InputComponent();
};
