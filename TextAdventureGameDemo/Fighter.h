#pragma once
#ifndef FIGHTER_H
#define FIGHTER_H

#include "Character.h"
class Fighter : public Character
{
public:
	Fighter();
	Fighter(string n);
	~Fighter();

	void attack(Character* enemy, int damageFactor = 1);
	void shieldBounce(Character* enemy, vector <Character*> &enemies);
	void options(vector <Character*>  &enemies, vector <Character*> &party);
};

#endif // FIGHTER_H