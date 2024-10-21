#pragma once
#include <string>
#include <iostream>
#include <random>

using namespace std;

class character {
public:
	string name;
	string description;
    string space = "";
    int open = 0;
    bool openDone = false;
	int damage;
	int totalHealth;
	int currentHealth;
	int coins = 10;
    int coinBuff = 1;
	int enemyDeaths = 0;
	bool lifeStatus;
	bool isAlive;
    int playerLv = 1;
    int playerXp = 0;
    int tPlayerXp = 100;
    int enemyXp = 33;
    int unlockPoints = 0;
    int archer = 0;
    int swordsman = 0;
    int mage = 0;


    //dungeons
    int dungeonLv = 1;
    int dugeonOpt = 0;
    int stoneAge = 0;
    int romanAge = 0;
    int mediAge = 0;
    int modAge = 0;
    int areaAge = 0;
    int stoneAge2 = 0;
    int romanAge2 = 0;
    int mediAge2 = 0;
    int modAge2 = 0;
    int areaAge2 = 0;

    //attacks
    int sharpness = 0;
    int levelSharp = 0;

    int bomb = 0;

    int knock = 0;

    int flame = 0;
    int levelFlam = 0;
    
    int scatter = 0;
    int levelScat = 0;
    
    int hardness = 0;
    int levelHard = 0;

    int sharpen = 0;

    int thorn = 0;
    int levelThorn = 0;

    int firstStrike = 0;

    int blazing = 0;
    int levelBlaze = 0;

    
    int lifeDrain = 0;
    int levelDrain = 0;
    bool usingDrain = false;

    int lightning = 0;
    int levelLight = 0;
    bool usingLightning = false;

    int summon = 0;
    int levelSummon = 0;
    bool usingSummon = false;

    int blizzard = 0;
    int levelBliz = 0;
    bool usingBliz = false;

    int Void = 0;
    int levelVoid = 0;
    bool usingVoid = false;

    //bomb
    bool bombPlaced = false;
    int turns = 0;

    //flame
    bool usedFlame = false;
    bool flameActive = false;

    //bleed
    bool usedBleed = false;
    bool bleedActive = false;

    //stun
    int stun;

    //summon chance
    int summonChance = 0;

    //missing chance
    bool miss = false;
    int missingChance = 5;

    //knock
    bool Knock = false;

	character();
	character(string enteredName, string enteredDescription);
	void describe();
	virtual void fight(character* player, character* other) = 0;
	virtual void setAlive(bool status) = 0;
	virtual void setStats(int level) = 0;

};