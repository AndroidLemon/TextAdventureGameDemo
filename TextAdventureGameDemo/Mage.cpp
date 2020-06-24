#include "Mage.h"

Mage::Mage()
{
	name = "Merric";
	setMaxHP(150 + rand() % 150);
	setHP(maxHP);
	setStrength(10 + rand() % 30);
	setDefense(15 + rand() % 30);
	setLuck(10 + rand() % 25);
	setMagic(35 + rand() % 15);
	setResistance(30 + rand() % 20);
}

Mage::Mage(string n) : Character(n)
{
	setMaxHP(100 + rand() % 150);
	setHP(maxHP);
	setStrength(10 + rand() % 30);
	setDefense(15 + rand() % 30);
	setLuck(10 + rand() % 25);
	setMagic(35 + rand() % 15);
	setResistance(30 + rand() % 20);
}

Mage::~Mage()
{
}

void Mage::attack(Character * enemy, int damageFactor)
{
	//int critRate = ((luck + 1) / 256) * 100;

	if (!enemy->isAlive()) {
		cout << enemy->getName() << " is already dead!\n";
		return;
	}

	int damageDone = 5 * (this->getMagic() - (.5* enemy->getResistance())) / damageFactor;

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

void Mage::manaWave(vector<Character*>& enemies)
{
	const int MANA_WAVE_DAMAGE_FACTOR = 2;
	cout << name << " cast out a wave of magic at all enemies! \n";

	for (int i = 0; i < enemies.size(); i++) {
		attack(enemies[i], MANA_WAVE_DAMAGE_FACTOR);
	}
}

void Mage::options(vector<Character*>& enemies, vector <Character*> &party)
{
	bool turnUsed = false;
	int choice;
	cout
		<< "Available actions: \n"
		<< "1.) Attack \n"
		<< "2.) Defend \n"
		<< "3.) Treat wounds \n"
		<< "4.) Mana Wave \n"
		<< "5.) Lesser Healing \n"
		<< "6.) View Character \n";

	do {
		cout << "Choose an action!\n";
		cin >> choice;
		switch (choice) {

		case 1:
			cout << "Which enemy will you attack? ";
			attack(targetChar(&enemies));
			turnUsed = true;
			break;

		case 2:
			defend();
			turnUsed = true;
			break;

		case 3:
			heal();
			turnUsed = true;
			break;

		case 4:
			manaWave(enemies);
			turnUsed = true;
			break;

		case 5:
			lesserHealing(party);
			turnUsed = true;
			break;

		case 6:
			targetParty(&enemies, &party);
			break;

		default:
			cout << "This isn't the time for games! Make your move! \n";
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			turnUsed = false;
			break;
		}

	} while (!turnUsed);
	return;
}

void Mage::lesserHealing(vector<Character*> &party)
{
	double lesserHealFactor = 0.20;
	cout << name << " casts Lesser Healing on the party!\n\n";

	for (int i = 0; i < party.size(); i++) {

		party[i]->heal(lesserHealFactor);
	}
}
