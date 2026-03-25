#pragma once
#include <vector>
#include "Character.h"

// Orchestrates a full battle encounter.
// Coordinates TurnScheduler, ActionResolver, and BattleState to run
// the turn loop without owning any of the low-level logic itself.
class BattleOrchestrator {
public:
    // Returns true if the party wins, false if they are wiped out.
    bool run(std::vector<Character*>& party, std::vector<Character*>& enemies);
};
