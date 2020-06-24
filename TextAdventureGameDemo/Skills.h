#pragma once
#ifndef SKILLS_H
#define SKILLS_H
#include <iostream>
#include <vector>
#include "Character.h"
using namespace std;


static class Skills
{
public:
	Skills();
	~Skills();

	static void mosquitoSwarm(Character* target, Character * spellcaster, int damageFactor = 1);
	static void shieldBounce(Character* target, vector<Character*> &enemies, Character* user);
	static void chloroform(Character* target, Character* user);
};
#endif // !SKILLS_H