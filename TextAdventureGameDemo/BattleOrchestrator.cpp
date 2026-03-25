#include "BattleOrchestrator.h"
#include "TurnScheduler.h"
#include "ActionResolver.h"
#include "BattleState.h"
#include <iostream>

using namespace std;

bool BattleOrchestrator::run(vector<Character*>& party, vector<Character*>& enemies) {
    cout << "Ready yourself! Enemies are approaching!\nYour current party status (Hit ENTER when ready):\n\n";
    BattleState::displayGroup(party);
    cin.get();
    cout << "Enemies encountered!!\n";
    BattleState::displayGroup(enemies);

    TurnScheduler scheduler(party, enemies);
    ActionResolver resolver;

    try {
        while (BattleState::checkGroupAlive(party) && BattleState::checkGroupAlive(enemies)) {
            // Player turn
            Character* player = scheduler.nextPlayer();
            resolver.resolvePlayerAction(player, enemies, party);

            if (!BattleState::checkGroupAlive(enemies)) break;

            // Enemy turn
            Character* enemy = scheduler.nextEnemy();
            resolver.resolveEnemyAction(enemy, party);
        }
    }
    catch (const std::out_of_range& oor) {
        cout << " One of you lot stepped out of range and now everyone in this reality is dead. Good job, ya buzzkills.\n"
             << oor.what();
        system("pause");
        return false;
    }

    return BattleState::checkGroupAlive(party);
}
