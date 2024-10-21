#pragma once
#include "character.h"

using namespace std;

class enemy : public character {
public:
	enemy(string enteredName, string enteredDescription) : character(enteredName, enteredDescription) {};
	void fight(character* player, character* other);
	void setStats(int level);
	void setAlive(bool status);
	bool isAlive;
};