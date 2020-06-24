#pragma once
#include "Character.h"
class Monster :
	public Character
{
public:
	enum monsterChoices
	{
		attacks = 1,
		defense,
		health
	};

	enum monsterTypes
	{
		Wyvern,
		Direwolf,
		Draugr,
		Chimera,
		Goblin,
		Adamantoise,
		Dragon
	};

	Monster();
	Monster(int monsterType);
	~Monster();

	void attack(Character* enemy, int damageFactor = 1);
	void options(vector <Character*> &enemies, vector <Character*> &party);

};

