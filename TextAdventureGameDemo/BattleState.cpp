#include "BattleState.h"

using namespace std;

bool BattleState::checkGroupAlive(vector<Character*>& group) {
    for (Character* c : group) {
        if (c->isAlive()) return true;
    }
    return false;
}

void BattleState::displayGroup(vector<Character*>& group, ostream& os) {
    for (Character* c : group) {
        os << *c << endl << endl;
    }
}
