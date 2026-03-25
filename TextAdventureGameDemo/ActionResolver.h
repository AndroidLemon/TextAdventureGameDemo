#pragma once
#include <vector>
#include "Character.h"

// Resolves a single character's action for their turn.
// Player actions are menu-driven; enemy actions are randomized.
class ActionResolver {
public:
    void resolvePlayerAction(Character* player, std::vector<Character*>& enemies, std::vector<Character*>& party);
    void resolveEnemyAction(Character* monster, std::vector<Character*>& party);
};
