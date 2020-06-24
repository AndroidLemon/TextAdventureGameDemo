#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Character
{
private:
	static int numCharacters;

protected:
	Character * playerPTR = nullptr;

	string name;
	int maxHP;
	int hitPoints;
	int strength;
	int defense;
	int magic;
	int resistance;
	int luck;
	
	bool living = true; 
	bool fatigued = false; //If a character should have a turn skipped due to a status effect, this becomes true.
	bool defending = false; // If defend action is used, set true for one turn.


public:
	Character();
	Character(string n);
	~Character();

	//Functions
	virtual void attack(Character* enemy, int damageFactor = 1) = 0;
	virtual void heal(double healingFactor = 0.35);
	virtual void defend();
	virtual void options(vector <Character*> &enemies, vector <Character*> &party) = 0;
	friend void groupAttack(Character* group);
	bool isCriticalHit(int luck); //Calculates a critical hit based on luck
	Character* targetChar(vector <Character*> *enemies);
	void targetParty(vector<Character*> *enemies, vector<Character*> *party);
	
	//Accessors
	string getName() { return name; }
	int getMaxHP() { return maxHP; }
	int getHP() { return hitPoints; }
	int getStrength() { return strength; }
	int getDefense() { return defense; }
	int getMagic() { return magic; }
	int getResistance() { return resistance; }
	int getLucky() {return luck; } // Quick Daft Punk reference, because why not?
	bool isDefending() { return defending; }
	bool isFatigued() { return fatigued; }
	bool isAlive() { return living; }
	Character* getPlayerPTR() { return playerPTR; }
	static int getNumChars() { return numCharacters; }


	//Mutators
	void setMaxHP(int hp);
	void setHP(int hp );
	void setStrength(int str );
	void setDefense(int def);
	void setMagic(int mag);
	void setResistance(int res);
	void setLuck(int lk);

	void setLife(bool l);
	void setFatigued(bool f);
	void setDefending(bool d);
	void showCharacter(const Character* person);



	//Overloaded Operators
	Character* operator++();
	friend ostream& operator<<(ostream &os, const Character &right);

};

#endif // !CHARACTER_H