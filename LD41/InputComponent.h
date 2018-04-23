#pragma once
#include "Component.h"
#include <vector>

class InputData
{
public:
	bool quit = false;
	bool mouseClicked = false;
	int mouseX = 0;
	int mouseY = 0;
};

class InputComponentObserver
{
public:
	virtual void onInputComponentUpdated(InputData data) = 0;
};

class InputComponent: public Component
{
private:
	std::vector<class InputComponentObserver*> observers;
	void notifyObservers(InputData data);
protected:
	void onUpdate(App* game);
	void onCleanup();
public:
	void addObserver(InputComponentObserver* observer);
	void removeObserver(InputComponentObserver* observer);
	InputComponent();
	~InputComponent();
};

int in_rect(int x, int y, struct SDL_Rect *r);
