#pragma once
#include "character.h"

using namespace std;

class player : public character {
public:
	player(string enteredName, string enteredDescription) : character(enteredName, enteredDescription) {};
	void fight(character* player, character* other);
    void rdFight(character* player, character* enemy);
	void setStats(int level);
	void setAlive(bool status);
	bool isAlive;
};