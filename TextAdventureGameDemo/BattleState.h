#pragma once
#include <vector>
#include <ostream>
#include <iostream>
#include "Character.h"

// Stateless utilities for querying and displaying battle group state.
class BattleState {
public:
    // Returns true if at least one member of the group is still alive.
    static bool checkGroupAlive(std::vector<Character*>& group);

    // Prints each character in the group to the given stream (default: cout).
    static void displayGroup(std::vector<Character*>& group, std::ostream& os = std::cout);
};
