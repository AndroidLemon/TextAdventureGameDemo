#include "Character.h"

Character::Character()
{
	playerPTR = this;
}

Character::Character(string n)
{
	name = n;
}

Character::~Character()
{
	//cout << name << " has been slain in battle! \n";
	//delete playerPTR;
	//playerPTR = nullptr;
	//cout << "Goodbye cruel world.";
}

Character * Character::targetChar(vector<Character*> *enemies)
{

	cout << "Choose a target: \n\n";
	int choice;
	for (int i = 0; i < enemies->size(); i++) {
		cout
			<< i + 1 << ") " << (*enemies)[i]->getName() << ((*enemies)[i]->isAlive()  ? "" : " (Dead)" )  << endl;
	}

	while (cin >> choice && (choice > enemies->size() || choice <= 0)) {
		cout << "Invalid target! \n";
	}
	return (*enemies)[choice - 1];
}

void Character::targetParty(vector<Character*>* enemies, vector<Character*>* party)
{
	int choice;
	cout
		<< "Which party would you like to view? \n"
		<< "1.) Your party\n"
		<< "2.) Enemy party\n";
	cin >> choice;
	switch (choice) {
	case 1:
		showCharacter(targetChar(party));
		break;
	case 2:
		showCharacter(targetChar(enemies));
		break;
	default:
		cout << "This isn't the time for games! Make your move! \n";
		cin.clear();
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		break;
	}
}

void Character::setMaxHP(int hp)
{
	maxHP = hp;
}

void Character::setHP(int hp)
{
	hitPoints = hp;
}

void Character::setStrength(int str)
{
	strength = str;
}

void Character::setDefense(int def)
{
	defense = def;
}

void Character::setMagic(int mag)
{
	magic = mag;
}

void Character::setResistance(int res)
{
	resistance = res;
}

void Character::setLuck(int lk)
{
	luck = lk;
}

void Character::setLife(bool l)
{
	living = l;
}

void Character::setFatigued(bool f)
{
	fatigued = f;
}

void Character::setDefending(bool d)
{
	defending = d;
}

void Character::showCharacter(const Character* person)
{
	cout << *person << endl << endl;
}

Character * Character::operator++()
{
	setMaxHP(maxHP += rand() % 30);
	setStrength(strength += rand() % 5);
	setDefense(defense += rand() % 5);
	setMagic(magic += rand() % 5);
	setResistance(resistance += rand() % 5);
	setLuck(luck += rand() % 5);

	return this;
}

void Character::heal(double healingFactor)
{
	cout << name << " is taking a breather, restoring HP!\n";
	cout << hitPoints << "HP -> ";
	hitPoints += (maxHP * healingFactor);
	if (hitPoints > maxHP)
		hitPoints = maxHP;
	cout << hitPoints << "HP. \n\n";
}

void Character::defend()
{
	cout << name << " raises their defenses! \n";
	setDefending(true);
}

bool Character::isCriticalHit(int luck)
{
	{
		if (luck >= (1 + rand() % 200))
			return 1;
		else
			return 0;
	}
}

void groupAttack(Character* group)
{
	int tempAttack = 0;

	for (int i = 0; i < 3; i++) {

		tempAttack += (group[i].getStrength() + group[i].getMagic());
	}
}

ostream & operator<<(ostream & os, const Character & right)
{
	os
		<< "Name: " << right.name << endl
		<< "HP: " << right.hitPoints << "/" << right.maxHP << endl
		<< "Strength: " << right.strength << endl
		<< "Defense: " << right.defense << endl
		<< "Magic: " << right.magic << endl
		<< "Resistance: " << right.resistance << endl
		<< "Luck: " << right.luck;
	return os;
}
