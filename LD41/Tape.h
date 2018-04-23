#pragma once
#include <vector>

class TapeObserver
{
public:
	virtual void onTapeUpdated(std::vector<unsigned char> tape) = 0;
};

class Tape
{
private:
	std::vector<unsigned char> tape;
	std::vector<class TapeObserver*> observers;
	void notifyObservers();

public:
	Tape();
	~Tape();
	void changeAdress(int index, char value);
	char getValue(int index);
	void addObserver(TapeObserver* observer);
	void removeObserver(TapeObserver* observer);

};

