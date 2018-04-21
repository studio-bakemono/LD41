#pragma once
#include "Component.h"
#include <vector>

class InputData
{
private:
	bool quit = false;
public:
	bool hasQuit();
};

class InputComponentObserver
{
public:
	virtual void onInputComponentUpdated(InputData data) = 0;
};

class InputComponent: public Component
{
private:
	std::vector<class InputComponentObserver*>* observers;
	InputData inputData;
	void notifyObservers();
protected:
	void onUpdate(App* game);
	void onCleanup();
public:
	void addObserver(InputComponentObserver* observer);
	void removeObserver(InputComponentObserver* observer);
	InputComponent();
	~InputComponent();
};
