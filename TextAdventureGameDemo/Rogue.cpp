#include "Rogue.h"


Rogue::Rogue()
{
	name = "Navarre";
	setMaxHP(125 + rand() % 200);
	setHP(maxHP);
	setStrength(25 + rand() % 30);
	setDefense(20 + rand() % 30);
	setLuck(35 + rand() % 25);
	setMagic(30 + rand() % 20);
	setResistance(10 + rand() % 40);
}

Rogue::Rogue(string n) : Character(n)
{
	setMaxHP(100 + rand() % 200);
	setHP(maxHP);
	setStrength(20 + rand() % 30);
	setDefense(20 + rand() % 30);
	setLuck(35 + rand() % 25);
	setMagic(30 + rand() % 20);
	setResistance(10 + rand() % 40);
}

Rogue::~Rogue()
{
}

void Rogue::attack(Character * enemy, int damageFactor) //Damage factor is needed due to the multiAttack function
{
	//int critRate = ((luck + 1) / 256) * 100;

	if (!enemy->isAlive()) {
		cout << "Enemy is already dead!\n";
		return;
	}

	int damageDone = 5 * (this->getStrength() - (.5* enemy->getDefense())) / damageFactor;

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

int Rogue::multiStrike(Character* enemy, int numHits)
{
	const int multiDamageFactor = 4; //Each hit does approx 1/4 damage, but each has a chance to crit. High luck has high rewards!

	if (!enemy->isAlive()) {
		return 0;
	}

	if (numHits > 0 && (enemy != nullptr)) {
		attack(enemy, multiDamageFactor);
		return multiStrike(enemy, numHits - 1);
	}
	else
		return 0;
}


void Rogue::options(vector <Character*> &enemies, vector <Character*> &party)
{
	bool turnUsed = false;
	int choice;
	cout
		<< "Available actions: \n"
		<< "1.) Attack \n"
		<< "2.) Defend \n"
		<< "3.) Treat wounds \n"
		<< "4.) MultiStrike \n"
		<< "5.) View Character \n";


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
			multiStrike(targetChar(&enemies));
			turnUsed = true;
			break;

		case 5:
			targetParty(&enemies, &party);
			break;

		default:
			cout << "This isn't the time for games! Make your move! \n";
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			turnUsed = false;
		}
	} while (!turnUsed);
	return;
}
