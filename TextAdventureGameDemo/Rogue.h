#pragma once
#include "Character.h"
class Rogue : public Character
{
public:
	Rogue();
	Rogue(string n);
	~Rogue();

	void attack(Character* enemy, int damageFactor = 1);
	int multiStrike(Character* enemy, int numHits = (2 + rand() % 3));
	//void defend() { defending = true; }
	void options(vector <Character*> &enemies, vector <Character*> &party);

};

