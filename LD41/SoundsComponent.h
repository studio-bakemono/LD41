#pragma once
#include "Component.h"
class SoundsComponent :
	public Component
{
protected:
	void onUpdate(App* game);
	void onCleanup();
public:
	SoundsComponent();
	~SoundsComponent();
};

