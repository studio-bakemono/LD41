#include "Tape.h"
#include <algorithm>

Tape::Tape()
{
	tape.resize(256);
	for (int i = 0; i < 256; i++) 
	{
		if (i % 3 == 0)
		{
			tape[i] = 'c';
		}
		else
		{
			tape[i] = 0;
		}
	}
}

Tape::~Tape()
{

}

void Tape::notifyObservers()
{
	for (int i = 0; i < observers.size(); i++)
	{
		observers[i]->onTapeUpdated(tape);
	}
}

void Tape::changeAdress(int index, char value)
{
	tape[index] = value;
	notifyObservers();
}

char Tape::getValue(int index)
{
	return tape[index];
}

void Tape::addObserver(TapeObserver * observer)
{
	observers.push_back(observer);
}

void Tape::removeObserver(TapeObserver * observer)
{
	observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}
