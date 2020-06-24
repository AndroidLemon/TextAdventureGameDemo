#include "Monster.h"



Monster::Monster()
{
	switch (rand() % Goblin) //Boss characters like Dragon and Adamantoise should be specifically instantiated
	{
	case Wyvern: //Fierce and vicious, they're fragile, but hit hard.
		name = "Wyvern";
		setMaxHP(100 + rand() % 100);
		setHP(maxHP);
		setStrength(40 + rand() % 20);
		setDefense(15 + rand() % 10);
		setLuck(10 + rand() % 10);
		setMagic(20 + rand() % 30);
		setResistance(10 + rand() % 15);
		break;

	case Direwolf: // Wolves are more physically balanced, but vulnerable to magic.
		name = "Direwolf";
		setMaxHP(100 + rand() % 200);
		setHP(maxHP);
		setStrength(35 + rand() % 15);
		setDefense(30 + rand() % 20);
		setLuck(10 + rand() % 15);
		setMagic(10 + rand() % 30);
		setResistance(10 + rand() % 10);
		break;

	case Draugr: // Undead soldiers. Physically bulky and strong.
		name = "Draugr";
		setMaxHP(150 + rand() % 250);
		setHP(maxHP);
		setStrength(35 + rand() % 15);
		setDefense(35 + rand() % 20);
		setLuck(10 + rand() % 5);
		setMagic(10 + rand() % 5);
		setResistance(15 + rand() % 15);
		break;

	case Chimera: //An amalgamation of multiple creatures, they're proficient in many areas. Watch out!
		name = "Chimera";
		setMaxHP(100 + rand() % 250);
		setHP(maxHP);
		setStrength(30 + rand() % 15);
		setDefense(25 + rand() % 15);
		setLuck(10 + rand() % 20);
		setMagic(30 + rand() % 15);
		setResistance(15 + rand() % 20);
		break;

	case Goblin: //Goblins are cunning, so high preference in luck and magic reistance.
		name = "Goblin";
		setMaxHP(50 + rand() % 175);
		setHP(maxHP);
		setStrength(15 + rand() % 10);
		setDefense(20 + rand() % 10);
		setLuck(30 + rand() % 20);
		setMagic(20 + rand() % 30);
		setResistance(30 + rand() % 30);
		break;

	default:
		break;
	}

}

Monster::Monster(int monsterType) //This constructor allows for a specific instance of a monster to be created.
{
	switch (monsterType)
	{
	case Wyvern: //Fierce and vicious, they're fragile, but hit hard.
		name = "Wyvern";
		setMaxHP(100 + rand() % 100);
		setHP(maxHP);
		setStrength(40 + rand() % 20);
		setDefense(15 + rand() % 10);
		setLuck(10 + rand() % 10);
		setMagic(20 + rand() % 30);
		setResistance(10 + rand() % 15);
		break;

	case Direwolf: // Wolves are more physically balanced, but vulnerable to magic.
		name = "Direwolf";
		setMaxHP(100 + rand() % 200);
		setHP(maxHP);
		setStrength(35 + rand() % 15);
		setDefense(30 + rand() % 20);
		setLuck(10 + rand() % 15);
		setMagic(10 + rand() % 30);
		setResistance(10 + rand() % 10);
		break;

	case Draugr: // Undead soldiers. Physically bulky and strong.
		name = "Draugr";
		setMaxHP(150 + rand() % 250);
		setHP(maxHP);
		setStrength(35 + rand() % 15);
		setDefense(35 + rand() % 20);
		setLuck(10 + rand() % 5);
		setMagic(10 + rand() % 5);
		setResistance(15 + rand() % 15);
		break;

	case Chimera: //An amalgamation of multiple creatures, they're proficient in many areas. Watch out!
		name = "Chimera";
		setMaxHP(100 + rand() % 250);
		setHP(maxHP);
		setStrength(30 + rand() % 15);
		setDefense(25 + rand() % 15);
		setLuck(10 + rand() % 20);
		setMagic(30 + rand() % 15);
		setResistance(15 + rand() % 20);
		break;

	case Goblin: //Goblins are cunning, so high preference in luck and magic reistance.
		name = "Goblin";
		setMaxHP(50 + rand() % 175);
		setHP(maxHP);
		setStrength(15 + rand() % 10);
		setDefense(20 + rand() % 10);
		setLuck(30 + rand() % 20);
		setMagic(20 + rand() % 30);
		setResistance(30 + rand() % 30);
		break;

	case Adamantoise: // This massive beast sports incredibly high defense and strength. Be careful!
		name = "Adamantoise";
		setMaxHP(300 + rand() % 350);
		setHP(maxHP);
		setStrength(30 + rand() % 15);
		setDefense(40 + rand() % 20);
		setLuck(10 + rand() % 10);
		setMagic(20 + rand() % 30);
		setResistance(30 + rand() % 30);
		break;

	case Dragon: //Dragons are mythic creatures with many powers. If you see one, well, it was nice knowing you. 
		//(If I ever get that skills list working, I'd love to have different types of dragon breath)
		name = "Dragon";
		setMaxHP(200 + rand() % 250);
		setHP(maxHP);
		setStrength(40 + rand() % 15);
		setDefense(25 + rand() % 20);
		setLuck(10 + rand() % 10);
		setMagic(40 + rand() % 30);
		setResistance(30 + rand() % 30);
	default:
		break;
	}
}


Monster::~Monster()
{
}

void Monster::attack(Character * enemy, int damageFactor)
{
	int damageDone;
	cout << name << " is attacking!\n";

	if (!enemy->isAlive()) {
		cout << enemy->getName() << " is already dead!\n" << name << " feasts on the remains!\n";
		++(*this);
		heal();
		cout << *this << endl;
		return;
	}

	if (this->getStrength() >= this->getMagic()) {
		damageDone = 5 * (this->getStrength() - (.5* enemy->getDefense())) / damageFactor;
	}
	else {
		damageDone = 5 * (this->getMagic() - (.5*enemy->getDefense())) / damageFactor;
	}

	if (enemy->isDefending()) {
		damageDone -= (damageDone * .25);
	}
	if (isCriticalHit(luck)) {
		cout << "Critical strike! \n";
		damageDone *= 2;
	}

	if (damageDone <= 0) {
		damageDone = 0;
	}

	enemy->setHP(enemy->getHP() - damageDone);
	cout << damageDone << " damage was dealt to " << enemy->getName() << "!\n";
	if (enemy->getHP() <= 0) {
		cout << enemy->getName() << " has been slain in battle! \n";
		enemy->setLife(false);
		enemy->setHP(0);
	}
	return;
}

void Monster::options(vector <Character*> &enemies, vector <Character*> &party)
{
}
