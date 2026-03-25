#include "ActionResolver.h"
#include "Monster.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void ActionResolver::resolvePlayerAction(Character* player, vector<Character*>& enemies, vector<Character*>& party) {
    if (!player->isAlive()) return;

    if (player->isDefending()) {
        cout << player->getName() << " no longer has their defenses raised.\n";
        player->setDefending(false);
    }
    if (player->isFatigued()) {
        cout << player->getName() << " cannot move this turn due to fatigue!\n";
        player->setFatigued(false);
        return;
    }

    cout << "\nWhat will " << player->getName() << " do?\n";
    // options() is pure virtual — dispatch is handled by the character's own class.
    player->options(enemies, party);
}

void ActionResolver::resolveEnemyAction(Character* monster, vector<Character*>& party) {
    if (!monster->isAlive()) return;

    if (monster->isDefending()) {
        cout << monster->getName() << " no longer has their defenses raised.\n";
        monster->setDefending(false);
    }

    switch (1 + rand() % 2) {
    case Monster::monsterChoices::attacks:
        monster->attack(party[rand() % party.size()]);
        break;
    case Monster::monsterChoices::defense:
        monster->defend();
        break;
    case Monster::monsterChoices::health:
        monster->heal();
        break;
    default:
        cout << "Not a choice";
        break;
    }
}
