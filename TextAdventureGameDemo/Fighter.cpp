#include "Fighter.h"

Fighter::Fighter() //Defautl constructor is a randomly generated fighter for testing. Still tweaking stat
{
	name = "Ogma";
	setMaxHP(200 + rand() % + 150);
	setHP(maxHP);
	setStrength(35 + rand() % 15);
	setDefense(30 + rand() % 20);
	setLuck(10 + rand() % 25);
	setMagic(10 + rand() % 30);
	setResistance(15 + rand() % 30);
}

Fighter::Fighter(string n) : Character(n)
{
	setMaxHP(200 + rand() % +100);
	setHP(maxHP);
	setStrength(35 + rand() % 15);
	setDefense(30 + rand() % 20);
	setLuck(10 + rand() % 25);
	setMagic(10 + rand() % 30);
	setResistance(15 + rand() % 30);
}


Fighter::~Fighter()
{
}

void Fighter::attack(Character * enemy, int damageFactor)
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

void Fighter::shieldBounce(Character * enemy, vector<Character*>& enemies)
{
	int i = rand() % enemies.size();
	cout << name << " throws their shield at " << enemy->getName() << "!\n";
	attack(enemy);
	cout << "\nThe shield bounces off a nearby wall!\n";
	attack(enemies[i], 2);
}

//void Fighter::defend() //Sets defending ststus to true, allowing for a damage reduction this turn.
//{
//	setDefending(true);
//}

void Fighter::options(vector <Character*> &enemies, vector <Character*> &party)
{
	bool turnUsed = false;
	int choice;
	cout
		<< "Available actions: \n"
		<< "1.) Attack \n"
		<< "2.) Defend \n"
		<< "3.) Treat wounds \n"
		<< "4.) Shield Bounce \n"
		<< "5.) View Character \n";
	do {
		cout << "Choose an action! \n";
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
			shieldBounce(targetChar(&enemies), enemies);
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
			break;
		}

	} while (!turnUsed);
	return;
}

/*void Fighter::heal() //Character rests, healing for 30%.
{
	hitPoints += (maxHP * .30);
	if (hitPoints > maxHP)
		hitPoints = maxHP;
}*/
