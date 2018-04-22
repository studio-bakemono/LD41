#pragma once

#include "Component.h"
#include "Turing.h"
#include <vector>

class TuringComponentInputData
{
public:
	BS bits;
};

class TuringComponentObserver
{
public:
	virtual void onTuringComponentUpdated(TuringComponentInputData data) = 0;
};

class TuringComponent : public Component
{
private:
	Turing machine;
	int nextbeat = BEATCOUNT;
	std::vector<class TuringComponentObserver*> observers;
	void notifyObservers(TuringComponentInputData data);
protected:
	void onUpdate(App* game);
	void onCleanup();
public:
	void addObserver(TuringComponentObserver* observer);
	void removeObserver(TuringComponentObserver* observer);
	TuringComponent();
	~TuringComponent();
};
