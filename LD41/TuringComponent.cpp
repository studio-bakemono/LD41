#include "TuringComponent.h"
#include <algorithm>



void TuringComponent::notifyObservers(TuringComponentInputData data)
{
	for (int i = 0; i < observers.size(); i++)
	{
		observers[i]->onTuringComponentUpdated(data);
	}
}

void TuringComponent::onUpdate(App * game)
{
	nextbeat -= 1;
	if (nextbeat == 0)
	{

		nextbeat = BEATCOUNT;
		auto i = TuringComponentInputData();
		i.bits = machine.tick();
		notifyObservers(i);
	}

}

void TuringComponent::onCleanup()
{
}

void TuringComponent::addObserver(TuringComponentObserver * observer)
{
	observers.push_back(observer);
}

void TuringComponent::removeObserver(TuringComponentObserver * observer)
{
	observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

TuringComponent::TuringComponent()
{
}


TuringComponent::~TuringComponent()
{
}
