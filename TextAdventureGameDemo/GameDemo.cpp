//This is a simple turn based battle game 
//
// Albert Jackson
// 5/10/18

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "Character.h"
#include "Fighter.h"
#include "Mage.h"
#include "Monster.h"
#include "Rogue.h"

using namespace std;

void PlayerTakeTurn(Character* player, vector <Character*> &enemies, vector <Character*> &party);
void enemyTakeTurn(Character* monster, vector <Character*> &enemies);
bool encounter(vector <Character*> &party, vector <Character*> &enemies);
bool checkPartyStatus(vector <Character*> &group);
void displayGroup(vector <Character*> &group, ostream &os = cout);

template<class T> void purge(std::vector<T> & v) { //Realized this morning that not only did I forget to delete the vectors, but that clearing the vector
												   //doesn't take ownership of deleting the pointers inside the vector. So here's a good excuse for that template! I should really learn how to use Smart and Shared Pointers.
	for (auto item : v) {
		delete item;
	}
	v.clear();
}

int main() {

	srand(time(0));

	fstream story("readTest.txt", ios::in);
	fstream characterLog("characterLog.txt", ios::out | ios::app); //Since characters have random stats, I thought it would be fun to log them and encounters.
	string line;
	vector <Character*> party;
	vector <Character*> enemies;

	if (story.is_open()) {
		while (!story.eof()) {

			getline(story, line, '$');
			cout << line;
			cin.get();
		}
	}
	else {
		cout << "Story file not found! Continuing on without it.\n\n";
	}

	party.push_back(new Rogue());
	party.push_back(new Fighter());
	party.push_back(new Mage());

	enemies.push_back(new Monster());
	enemies.push_back(new Monster());
	enemies.push_back(new Monster());
	enemies.push_back(new Monster());
	enemies.push_back(new Monster());
	//enemies.push_back(new Monster());

	if (encounter(party, enemies)) {
		cout << "\nThe battle is won!\n\n";
		characterLog << "------------------\nWIN!\n------------------\nTEAM:\n\n";
		displayGroup(party, characterLog);
		characterLog << "\n------------------\nENEMIES FOUGHT:\n\n";
		displayGroup(enemies, characterLog);
	}
	else {
		cout << "\nYou're dead!\n\n";
		characterLog << "------------------\nLOSS!\n------------------\nTEAM:\n\n";
		displayGroup(party, characterLog);
		characterLog << "\n------------------\nENEMIES FOUGHT:\n\n";
		displayGroup(enemies, characterLog);
	}

	characterLog.close(); //Close character log
	story.close();  //Close story file

	purge(party); //Delete pointers in vector, then clear vector.
	purge(enemies);
	system("pause");
	return 0;
}

void PlayerTakeTurn(Character* player, vector <Character*> &enemies, vector <Character*> &party) {
	if (!player->isAlive())
	{
		return; //Character is dead, so skip turn. 
	}

	if (player->isDefending()) {
		cout << player->getName() << " no longer has their defenses raised.\n";
		player->setDefending(false); //End defending status.
	}
	if (player->isFatigued()) {
		cout << player->getName() << "cannot move this turn due to fatigue! \n";
		player->setFatigued(false); //End fatigued status and skip turn.
		return;
	}

	cout << "\nWhat will " << player->getName() << " do?\n";

	if (dynamic_cast<Fighter*>(player) != nullptr) {
		dynamic_cast<Fighter*>(player)->options(enemies, party);
	}

	else if (dynamic_cast<Mage*>(player) != nullptr) {
		dynamic_cast<Mage*>(player)->options(enemies, party);
	}

	else if (dynamic_cast<Rogue*>(player) != nullptr)
	{
		dynamic_cast<Rogue*>(player)->options(enemies, party);
	}
}

void enemyTakeTurn(Character* monster, vector <Character*> &enemies) {
	if (!monster->isAlive()) {
		return;
	}

	if (monster->isDefending()) {
		cout << monster->getName() << " no longer has their defenses raised.\n";
		monster->setDefending(false);
	}

	switch (1 + rand() % 2)
	{
	case Monster::monsterChoices::attacks:
		monster->attack(enemies[rand() % (enemies.size())]);
		break;

	case Monster::monsterChoices::defense:
		monster->defend();
		break;
	case Monster::monsterChoices::health:
		monster->heal();

	default:
		cout << "Not a choice"; //Shouldn't actually trigger, but just a debugging check.
		break;
	}
}

bool encounter(vector <Character*> &party, vector <Character*> &enemies) {
	bool partyAlive = true;
	bool enemiesAlive = true;
	int i = 0;
	int j = 0;

	cout << "Ready yourself! Enemies are approaching! \nYour current party status (Hit ENTER when ready): \n\n";
	displayGroup(party);
	cin.get();
	cout << "Enemies encountered!!\n";
	displayGroup(enemies);

	try {
		while (partyAlive && enemiesAlive) {
			if (i == party.size()) {
				i = 0;
			}
			PlayerTakeTurn(party[i], enemies, party);
			enemiesAlive = checkPartyStatus(enemies);
			i++;

			if (j == enemies.size()) {
				j = 0;
			}
			enemyTakeTurn(enemies[j], party);
			partyAlive = checkPartyStatus(party);
			j++;
		}

		if (enemiesAlive) {
			return false; //You lose!
		}
		else if (partyAlive) {
			return true; // You Win!
		}
	}
	catch (const std::out_of_range& oor) {
		cout << " One of you lot stepped out of range and now everyone in this reality is dead. Good job, ya buzzkills.\n" << oor.what();
		system("pause");
		EXIT_FAILURE;
	}
}

bool checkPartyStatus(vector <Character*> &group) {

	int deadMemberCount = 0;

	for (int i = 0; i < group.size(); i++) {
		if (!group[i]->isAlive()) {
			deadMemberCount++;
		}
	}

	if (deadMemberCount == group.size()) {
		return false; //All party members are dead.
	}
	else if (deadMemberCount < group.size()) {
		return true; //At least one member is still alive, so battle continues.
	}
}

void displayGroup(vector <Character*> &group, ostream &os) {

	for (int i = 0; i < group.size(); i++) {
		os << *(group[i]) << endl << endl;
	}
}