#include "enemy.h"

using namespace std;

int enemyDeaths = 0;

void enemy::fight(character* player, character* other)
{
	other->currentHealth -= player->damage;
	cout << player->name << " hit " << other->name << " for " << player->damage << " damage." << endl;
	cout << other->name << " is at " << other->currentHealth << "/" << other->totalHealth << " health." << endl;
}

void enemy::setStats(int level)
{
	int baseStat = 2 * level;
	int x = rand() % baseStat + 1;

	damage = x;
	currentHealth = totalHealth = x * 2;
}

void enemy::setAlive(bool status) {
	isAlive = status;
}