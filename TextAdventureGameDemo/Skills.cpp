#include "Skills.h"


Skills::Skills()
{
}

Skills::~Skills()
{
}

void Skills::mosquitoSwarm(Character * target, Character * spellcaster, int damageFactor)
{
	int damage;
	cout << endl << spellcaster->getName() << " summons a swarm of bloodthirsty mosquitoes to attack" << target->getName() << "!\n";

	damage = 6 * (spellcaster->getMagic() - target->getResistance() / 2) / damageFactor;

	if (target->isDefending()) {
		damage -= (damage * .25);
	}
	if (damage <= 0) {
		damage = 0;
	}

	target->setHP(target->getHP() - damage);
	cout << damage << " damage was dealt to " << target->getName() << "!\n";
	if (target->getHP() <= 0) {
		cout << target->getName() << " has been slain in battle! \n";
		target->setLife(false);
	}

	damage /= 2;

	cout << spellcaster->getName() << " heals himself for " << damage << "!";

	cout << spellcaster->getHP() << "HP -> ";
	spellcaster->setHP(spellcaster->getHP() + damage);
	if (spellcaster->getHP() > spellcaster->getMaxHP())
		spellcaster->setHP(spellcaster->getMaxHP());
	cout << spellcaster->getHP() << "HP. \n\n";
}

void Skills::shieldBounce(Character* target, vector<Character*> &enemies, Character* user)
{
	int i = rand() % enemies.size() - 1;
	cout << user->getName() << "throws his shield at " << target->getName();
	user->attack(target);
	cout << "\n The shield bounces off a nearby wall!";
	user->attack(enemies[i]);
}

void Skills::chloroform(Character * target, Character * user) //Deals no damage, but sets fatigue on target.
{
	cout << user->getName() << "tosses a bottle of chloroform at " << target->getName() << "!\n";
	if (!target->isAlive()) {
		cout << target->getName() << " is already taking an eternal rest... \n";
	}
	else
		target->setFatigued(true);
	cout << target->getName() << "fell asleep! \n";
}
