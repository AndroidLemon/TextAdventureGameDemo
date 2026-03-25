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
#include "BattleOrchestrator.h"
#include "BattleState.h"

using namespace std;

template<class T> void purge(std::vector<T>& v) { //Realized this morning that not only did I forget to delete the vectors, but that clearing the vector
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
	vector<Character*> party;
	vector<Character*> enemies;

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

	BattleOrchestrator orchestrator;
	if (orchestrator.run(party, enemies)) {
		cout << "\nThe battle is won!\n\n";
		characterLog << "------------------\nWIN!\n------------------\nTEAM:\n\n";
		BattleState::displayGroup(party, characterLog);
		characterLog << "\n------------------\nENEMIES FOUGHT:\n\n";
		BattleState::displayGroup(enemies, characterLog);
	}
	else {
		cout << "\nYou're dead!\n\n";
		characterLog << "------------------\nLOSS!\n------------------\nTEAM:\n\n";
		BattleState::displayGroup(party, characterLog);
		characterLog << "\n------------------\nENEMIES FOUGHT:\n\n";
		BattleState::displayGroup(enemies, characterLog);
	}

	characterLog.close(); //Close character log
	story.close();  //Close story file

	purge(party); //Delete pointers in vector, then clear vector.
	purge(enemies);
	system("pause");
	return 0;
}
