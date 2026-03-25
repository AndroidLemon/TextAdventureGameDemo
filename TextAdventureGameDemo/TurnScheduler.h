#pragma once
#include <vector>
#include "Character.h"

// Manages round-robin turn order for two groups.
// Calling nextPlayer()/nextEnemy() returns the next character in each group,
// wrapping back to index 0 after the last member.
class TurnScheduler {
public:
    TurnScheduler(std::vector<Character*>& party, std::vector<Character*>& enemies)
        : party(party), enemies(enemies), playerIndex(0), enemyIndex(0) {}

    Character* nextPlayer() {
        if (playerIndex == static_cast<int>(party.size())) playerIndex = 0;
        return party[playerIndex++];
    }

    Character* nextEnemy() {
        if (enemyIndex == static_cast<int>(enemies.size())) enemyIndex = 0;
        return enemies[enemyIndex++];
    }

private:
    std::vector<Character*>& party;
    std::vector<Character*>& enemies;
    int playerIndex;
    int enemyIndex;
};
