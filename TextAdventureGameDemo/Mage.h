#pragma once
#include "Character.h"
class Mage : public Character
{
public:
	Mage();
	Mage(string n);
	~Mage();

	void attack(Character* enemy, int damageFactor = 1);
	void manaWave(vector<Character*> &enemies);
	void options(vector <Character*> &enemies, vector <Character*> &party);
	void lesserHealing(vector<Character*> &party);

	//void heal(Character * group);
};

