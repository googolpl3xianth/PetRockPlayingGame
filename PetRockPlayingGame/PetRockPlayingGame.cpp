//
//
//Welcome to My Rock Adventure
//
//
//By Samuel Hong
//
//
//Start by pressing f5
//
//
//If you don't get any of the names look up RPS 11
//
//
//Please don't mess with the code, but at line 802 is the op code that lets you have access to everything
//
//
//Not pressing the shown options will kill you. like pressing 5 when there is no option 5.
//
//
//Thanks and hope you enjoy
//
//
//This is possible
//
//
//Put comments and suggestions here:
//
//Best game ever - Samuel
//So good - Samuel
//Perfect - Samuel
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

#include <iostream>
#include <string> 
#include <thread>
#include <chrono>
#include <random>

#include "player.h"
#include "enemy.h"

using namespace std;

void delayScroll(int delayMS, int lineCount);
character* generateEnemy();
void encounterEnemy(character* player, character* enemy);
void fightDecisions(character* player, character* enemy);
character* anEnemy = generateEnemy();

//shop
int healPotion = 0;
int strenthPotion = 0;
int fullPotion = 0;
 //item var
int weaponItem = 0;
int weaponLv;
int armorItem = 0;
int armorLv;
int randomNum;
random_device rd;

void delayScroll(int delayMS, int lineCount)
{
	for (int i = 0; i < lineCount; i++)
	{
		std::cout << "" << endl;
		this_thread::sleep_for(chrono::milliseconds(delayMS));
	}
}

character* generateEnemy()
{
	character* e = new enemy("", "");
	e->setStats(1);
	return e;
}

void shop(character* player, character* enemy) {
	std::cout << "You have $" << player->coins << " coins." << endl;
	std::cout << "1. Buy a healthPotion (+3 health and total health) $1" << endl;
	std::cout << "2. Buy a strengthPotion (+3 strength) $1" << endl;
	std::cout << "3. Buy a fullPotion (heals you to full health) $1" << endl;
	std::cout << "4. Back" << endl;
	std::cout << ">";
	int option;
	std::cin >> option;
	if (option == 1 && player->coins > 0) {
		player->coins -= 1;
		healPotion += 1;
		std::cout << "You bought a healthPotion" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
		shop(player, enemy);
	}
	else if (option == 2 && player->coins > 0) {
		player->coins -= 1;
		strenthPotion += 1;
		std::cout << "You bought a strenthPotion" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
		shop(player, enemy);
	}
	if (option == 3 && player->coins > 0) {
		player->coins -= 1;
		fullPotion += 1;
		std::cout << "You bought a fullPotion" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
		shop(player, enemy);
	}
	else if (option == 4) {
		fightDecisions(player, enemy);
	}
	else
	{
		std::cout << "You don't have enough coins" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
		shop(player, enemy);
	}
}
void potion(character* player, character* enemy) {
	std::cout << "1. Use a healthPotion (" << healPotion<< ")" << endl;
	std::cout << "2. Use a strenthPotion (" << strenthPotion << ")" << endl;
	std::cout << "3. Use a fullPotion (" << fullPotion << ")" << endl;
	std::cout << "4. Back" << endl;
	std::cout << ">";
	int option;
	std::cin >> option;
	if (option == 1 && healPotion > 0) {
		player->totalHealth += 3;
		player->currentHealth += 3;
		std::cout << "You used a healthPotion." << endl;
		healPotion -= 1;
		std::cout << "You are at " << player->currentHealth << "/" << player->totalHealth << " health." << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        potion(player, enemy);
	}
	else if (option == 2 && strenthPotion > 0) {
		player->damage += 3;
		std::cout << "You used a strenthPotion." << endl;
		strenthPotion -= 1;
        std::cout << "You now deal " << player->damage << " damage" <<  endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        potion(player, enemy);
	}
	if (option == 3 && fullPotion > 0 && player->currentHealth != player->totalHealth) {
		player->currentHealth = player->totalHealth;
		std::cout << "You used a fullPotion." << endl;
		fullPotion -= 1;
		std::cout << "You are at " << player->currentHealth << "/" << player->totalHealth << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        potion(player, enemy);

	}
	else if (option == 4) {
		fightDecisions(player, enemy);
	}
	else {
		std::cout << "You have no potions or are full health" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        potion(player, enemy);
	}
}

void dungeon(character* player) {
    player->currentHealth = player->totalHealth;
    player->enemyDeaths = 0;
    int raid = 0;
    raid++;
    while (raid == 1) {
        cout << "Pick a dungeon to raid" << endl;
        cout << "1.Stone age (level requirement of 1)" << endl;
        cout << "2.Roman age (level requirement of 20)" << endl;
        cout << "3.Medieval age (level requirement of 40)" << endl;
        cout << "4.Modern day (level requirement of 60)" << endl;
        cout << "5.Area 51 (level requirement of 80)" << endl;
        cout << ">" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        cin >> player->dugeonOpt;
        if (player->dugeonOpt == 1) {
            player->stoneAge = 1;
            cout << "Pick a difficulty" << endl;
            cout << "1.Easy (level requirement of 1)" << endl;
            cout << "2.Medium (level requirement of 5)" << endl;
            cout << "3.Hard (level requirement of 10)" << endl;
            cout << "4.Insane (level requirement of 15)" << endl;
            cout << ">" << endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
            cin >> player->stoneAge2;
            if (player->stoneAge2 == 1) {\
                anEnemy->name = "Rock Brute";
                player->enemyXp = 33;
                player->coinBuff = 1;
                player->dungeonLv = 1;
                raid--;
            }
            else if (player->stoneAge2 == 2 && player->playerLv >= 5) {
                anEnemy->name = "Rock Brute";
                player->enemyXp = 66;
                player->coinBuff = 2;
                player->dungeonLv = 2;
                raid--;
            }
            else if (player->stoneAge2 == 3 && player->playerLv >= 10) {
                anEnemy->name =  "Rock Brute";
                player->enemyXp = 132;
                player->coinBuff = 3;
                player->dungeonLv = 3;
                raid--;
            }
            else if (player->stoneAge2 == 4 && player->playerLv >= 15) {
                anEnemy->name = "Rock Brute";
                player->enemyXp = 264;
                player->coinBuff = 4;
                player->dungeonLv = 4;
                raid--;
            }
            else {
                cout << "You don't have the required level." << endl;
            }
        }
        else if (player->dugeonOpt == 2 && player->playerLv >= 20) {
            player->enemyDeaths = 7;
            player->romanAge = 1;
            cout << "Pick a difficulty" << endl;
            cout << "1.Easy (level requirement of 20)" << endl;
            cout << "2.Medium (level requirement of 25)" << endl;
            cout << "3.Hard (level requirement of 30)" << endl;
            cout << "4.Insane (level requirement of 35)" << endl;
            cout << ">" << endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
            cin >> player->romanAge2;
            if (player->romanAge2 == 1 && player->playerLv >= 20) {
                anEnemy->name = "Roman soldier";
                player->enemyXp = 528;
                player->coinBuff = 5;
                player->dungeonLv = 5;
                raid--;
            }
            else if (player->romanAge2 == 2 && player->playerLv >= 25) {
                anEnemy->name = "Roman soldier";
                player->enemyXp = 1056;
                player->coinBuff = 6;
                player->dungeonLv = 6;
                raid--;
            }
            else if (player->romanAge2 == 3 && player->playerLv >= 30) {
                anEnemy->name = "Roman soldier";
                player->enemyXp = 2112;
                player->coinBuff = 7;
                player->dungeonLv = 7;
                raid--;
            }
            else if (player->romanAge2 == 4 && player->playerLv >= 35) {
                anEnemy->name = "Roman soldier";
                player->enemyXp = 4224;
                player->coinBuff = 8;
                player->dungeonLv = 8;
                raid--;
            }
            else {
                cout << "You don't have the required level." << endl;
            }
        }
        else if (player->dugeonOpt == 3 && player->playerLv >= 40) {
            player->enemyDeaths = 13;
            player->mediAge = 1;
            cout << "Pick a difficulty" << endl;
            cout << "1.Easy (level requirement of 40)" << endl;
            cout << "2.Medium (level requirement of 45)" << endl;
            cout << "3.Hard (level requirement of 50)" << endl;
            cout << "4.Insane (level requirement of 55)" << endl;
            cout << ">" << endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
            cin >> player->mediAge2;
            if (player->mediAge2 == 1 && player->playerLv >= 40) {
                anEnemy->name = "Knight";
                player->enemyXp = 8448;
                player->coinBuff = 9;
                player->dungeonLv = 9;
                raid--;
            }
            else if (player->mediAge2 == 2 && player->playerLv >= 45) {
                anEnemy->name = "Knight";
                player->enemyXp = 16896;
                player->coinBuff = 10;
                player->dungeonLv = 10;
                raid--;
            }
            else if (player->mediAge2 == 3 && player->playerLv >= 50) {
                anEnemy->name = "Knight";
                player->enemyXp = 33792;
                player->coinBuff = 11;
                player->dungeonLv = 11;
                raid--;
            }
            else if (player->mediAge2 == 4 && player->playerLv >= 55) {
                anEnemy->name = "Knight";
                player->enemyXp = 67584;
                player->coinBuff = 12;
                player->dungeonLv = 12;
                raid--;
            }
            else {
                cout << "You don't have the required level." << endl;
            }
        }
        else if (player->dugeonOpt == 4 && player->playerLv >= 60) {
            player->enemyDeaths = 19;
            player->modAge = 1;
            cout << "Pick a difficulty" << endl;
            cout << "1.Easy (level requirement of 60)" << endl;
            cout << "2.Medium (level requirement of 65)" << endl;
            cout << "3.Hard (level requirement of 70)" << endl;
            cout << "4.Insane (level requirement of 75)" << endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
            cin >> player->modAge2;
            if (player->modAge2 == 1 && player->playerLv >= 60) {
                anEnemy->name = "Army Soldier";
                player->enemyXp = 135168;
                player->coinBuff = 13;
                player->dungeonLv = 13;
                raid--;
            }
            else if (player->modAge2 == 2 && player->playerLv >= 65) {
                anEnemy->name = "Army Soldier";
                player->enemyXp = 270336;
                player->coinBuff = 14;
                player->dungeonLv = 14;
                raid--;
            }
            else if (player->modAge2 == 3 && player->playerLv >= 70) {
                anEnemy->name = "Army Soldier";
                player->enemyXp = 540672;
                player->coinBuff = 15;
                player->dungeonLv = 15;
                raid--;
            }
            else if (player->modAge2 == 4 && player->playerLv >= 75) {
                anEnemy->name = "Army Soldier";
                player->enemyXp = 1081344;
                player->coinBuff = 16;
                player->dungeonLv = 16;
                raid--;
            }
            else {
                cout << "You don't have the required level." << endl;
            }
        }
        else if (player->dugeonOpt == 5 && player->playerLv >= 80) {
        player->enemyDeaths = 25;
            player->areaAge = 1;
            cout << "Pick a difficulty" << endl;
            cout << "1.Easy (level requirement of 80)" << endl;
            cout << "2.Medium (level requirement of 85)" << endl;
            cout << "3.Hard (level requirement of 90)" << endl;
            cout << "4.Insane (level requirement of 95)" << endl;
            cout << "5.Impossible (level requirement of 100)" << endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
            cin >> player->areaAge2;
            if (player->areaAge2 == 1 && player->playerLv >= 80) {
                anEnemy->name = "Guard";
                player->enemyXp = 2162688;
                player->coinBuff = 17;
                player->dungeonLv = 17;
                raid--;
            }
            else if (player->areaAge2 == 2 && player->playerLv >= 85) {
                anEnemy->name = "Guard";
                player->enemyXp = 4325376;
                player->coinBuff = 18;
                player->dungeonLv = 18;
                raid--;
            }
            else if (player->areaAge2 == 3 && player->playerLv >= 90) {
                player->name = "Guard";
                player->enemyXp = 8650752;
                player->coinBuff = 19;
                player->dungeonLv = 19;
                raid--;
            }
            else if (player->areaAge2 == 4 && player->playerLv >= 95) {
                anEnemy->name = "Guard";
                player->enemyXp = 17301504;
                player->coinBuff = 20;
                player->dungeonLv = 20;
                raid--;
            }
            else if (player->areaAge2 == 5 && player->playerLv >= 100) {
                anEnemy->name = "Guard";
                player->enemyXp = 34603008;
                player->coinBuff = 21;
                player->dungeonLv = 21;
                raid--;
            }
            else {
                cout << "You don't have the required level." << endl;
            }
        }
        else {
            cout << "You don't have the required level." << endl;
        }
    }
    fightDecisions(player, anEnemy);
}

void encounterEnemy(character* player, character* enemy)
{
    player->turns = 0;
    enemy->damage *= player->dungeonLv * player->dungeonLv * player->dungeonLv;
    enemy->currentHealth *= player->dungeonLv * player->dungeonLv * player->dungeonLv;
    enemy->totalHealth *= player->dungeonLv * player->dungeonLv * player->dungeonLv;
    while (player->isAlive && enemy->isAlive)
    {
        player->fight(player, enemy);
    }
    if (player->flameActive == true) {
        player->flameActive = false;
    }
    if (player->bleedActive == true) {
        player->bleedActive = false;
    }
    enemy->damage /= player->dungeonLv * player->dungeonLv * player->dungeonLv;
    enemy->currentHealth /= player->dungeonLv * player->dungeonLv * player->dungeonLv;
    enemy->totalHealth /= player->dungeonLv * player->dungeonLv * player->dungeonLv;
    if (player->openDone == true) {
        player->damage /= 2;
        player->openDone = false;
    }
    if (player->enemyDeaths == 6) {
        player->enemyDeaths = 0;
        dungeon(player);
    }
    else if (player->enemyDeaths == 11) {
        player->enemyDeaths = 0;
        dungeon(player);
    }
    else if (player->enemyDeaths == 18) {
        player->enemyDeaths = 0;
        dungeon(player);
    }
    else if (player->enemyDeaths == 25) {
        player->enemyDeaths = 0;
        dungeon(player);
    }
    else if (player->enemyDeaths == 30) {
        player->enemyDeaths = 0;
        dungeon(player);
    }
    else {
        fightDecisions(player, enemy);
    }

}

void fightDecisions(character* player, character* enemy)
{
    if (enemy->currentHealth > 0) {
        enemy->isAlive = true;
    }
	else{
		enemy->isAlive = false;
		character* generateEnemy();
}
	if (player->currentHealth > 0) {
		player->isAlive = true;
	}
	else {
		player->isAlive = false;
	}
	if (player->isAlive == true)
	{
		if (player->enemyDeaths == 5) {
            player->enemyXp *= 3;
			std::cout << "You are at full health." << endl;
			anEnemy->name = "A Dinosaur!";
			anEnemy->totalHealth * player->dungeonLv;
            anEnemy->damage * player->dungeonLv;
            anEnemy->totalHealth * player->dungeonLv;
			player->coins += 5;
			randomNum = rd() % 21;

			if (randomNum >= 10 && randomNum < 15) {
				weaponItem = 1;
				weaponLv = randomNum / 4;
				std::cout << "You found a weapon!" << endl;
				std::cout << "+" << randomNum / 4 << " attack" << endl;
				player->damage += randomNum / 4;
			}
			else if (randomNum >= 30) {
				armorItem = 1;
				armorLv = randomNum / 4;
				std::cout << "You found Armor!" << endl;
				std::cout << "+" << randomNum / 4 << " total health" << endl;
				player->totalHealth += randomNum / 4;
				player->currentHealth += randomNum / 4;
			}
			std::cout << "You found 5 coins!" << endl;

			//options
			std::cout << "You encounter " << anEnemy->name << endl;
			std::cout << "1. Encounter" << endl;
			int option = 0;
			std::cout << ">";
			std::cin >> option;

			//attack
			if (option == 1) {
				anEnemy->currentHealth = anEnemy->totalHealth;
				anEnemy->isAlive = true;
				encounterEnemy(player, anEnemy);
			}
		}
		else if (player->enemyDeaths == 12) {
            player->enemyXp *= 3;
			std::cout << "You are at full health." << endl;
			anEnemy->name = "The Emperor!";
			anEnemy->currentHealth * player->dungeonLv;
			anEnemy->damage * player->dungeonLv;
			anEnemy->totalHealth * player->dungeonLv;
			player->currentHealth = player->totalHealth;
			player->coins += 10;

			randomNum = rd() % 41;
			if (randomNum >= 20 && randomNum < 30) {
				weaponItem = 1;
				weaponLv = randomNum / 4;
				std::cout << "You found a weapon!" << endl;
				std::cout << "+" << randomNum / 4 << " attack" << endl;
				player->damage += randomNum / 4;
			}
			else if (randomNum >= 30) {
				armorItem = 1;
				armorLv = randomNum / 4;
				std::cout << "You found Armor!" << endl;
				std::cout << "+" << randomNum / 4 << " total health" << endl;
				player->totalHealth += randomNum / 4;
				player->currentHealth += randomNum / 4;
			}
            std::cout << "You found 10 coins!" << endl;

			//options
			std::cout << "You encounter " << anEnemy->name << endl;
			std::cout << "1. Encounter" << endl;
			int option = 0;
			std::cout << ">";
			std::cin >> option;

			//attack
			if (option == 1) {
				anEnemy->currentHealth = anEnemy->totalHealth;
				anEnemy->isAlive = true;
				encounterEnemy(player, anEnemy);
			}
		}
		else if (player->enemyDeaths == 18) {
            player->enemyXp *= 3;
			std::cout << "You are at full health." << endl;
			anEnemy->name = "The King!";
			anEnemy->currentHealth * player->dungeonLv;
			anEnemy->damage * player->dungeonLv;
			anEnemy->totalHealth * player->dungeonLv;
			player->currentHealth = player->totalHealth;
			player->coins += 15;

			randomNum = rd() % 61;
			if (randomNum >= 30 && randomNum < 45) {
				weaponItem = 1;
				weaponLv = randomNum / 4;
				std::cout << "You found a weapon!" << endl;
				std::cout << "+" << randomNum / 4 << " attack" << endl;
				player->damage += randomNum / 4;
			}
			else if (randomNum >= 45) {
				armorItem = 1;
				armorLv = randomNum / 4;
				std::cout << "You found Armor!" << endl;
				std::cout << "+" << randomNum / 4 << " total health" << endl;
				player->totalHealth += randomNum / 4;
				player->currentHealth += randomNum / 4;
			}
            std::cout << "You found 15 coins!" << endl;

			//options
			std::cout << "You encounter " << anEnemy->name << endl;
			std::cout << "1. Encounter" << endl;
			int option = 0;
			std::cout << ">";
			std::cin >> option;

			//attack
			if (option == 1) {
				anEnemy->currentHealth = anEnemy->totalHealth;
				anEnemy->isAlive = true;
				encounterEnemy(player, anEnemy);
			}
		}
		else if (player->enemyDeaths == 24) {
        player->enemyXp *= 3;
			std::cout << "You are at full health." << endl;
			anEnemy->name = "A Tank!";
			anEnemy->currentHealth * player->dungeonLv;
			anEnemy->damage * player->dungeonLv;
			anEnemy->totalHealth * player->dungeonLv;
			player->currentHealth = player->totalHealth;
			player->coins += 15;

			//options
			std::cout << "You encounter " << anEnemy->name << endl;
			std::cout << "1. Encounter" << endl;
			int option = 0;
			std::cout << ">";
			std::cin >> option;

			//attack
			if (option == 1) {
				anEnemy->currentHealth = anEnemy->totalHealth;
				anEnemy->isAlive = true;
				encounterEnemy(player, anEnemy);
			}
		}
        else if (player->enemyDeaths == 30) {
        player->enemyXp *= 3;
        std::cout << "You are at full health." << endl;
        anEnemy->name = "An Alien!";
        anEnemy->currentHealth* player->dungeonLv;
        anEnemy->damage* player->dungeonLv;
        anEnemy->totalHealth* player->dungeonLv;
        player->currentHealth = player->totalHealth;
        player->coins += 20;

        //options
        std::cout << "You encounter " << anEnemy->name << endl;
        std::cout << "1. Encounter" << endl;
        int option = 0;
        std::cout << ">";
        std::cin >> option;

        //attack
        if (option == 1) {
            anEnemy->currentHealth = anEnemy->totalHealth;
            anEnemy->isAlive = true;
            encounterEnemy(player, anEnemy);
        }
        }
		else {
        if (player->enemyDeaths == 6) {
            dungeon(player);
        }
        if (player->enemyDeaths == 12) {
            dungeon(player);
        }
        if (player->enemyDeaths == 18) {
            dungeon(player);
        }
        if (player->enemyDeaths == 24) {
            dungeon(player);
        }
        if (player->enemyDeaths == 30) {
            dungeon(player);
        }
			//options
            if (player->stoneAge2 != 0) {
                std::cout << "You encounter Lv" << player->stoneAge2 << " " << anEnemy->name << endl;
            }
            if (player->romanAge2 != 0) {
                std::cout << "You encounter Lv" << player->romanAge2 << " " << anEnemy->name << endl;
            }
            if (player->mediAge2 != 0) {
                std::cout << "You encounter Lv" << player->mediAge2 << " " << anEnemy->name << endl;
            }
            if (player->modAge2 != 0) {
                std::cout << "You encounter Lv" << player->modAge2 << " " << anEnemy->name << endl;
            }
            if (player->areaAge2 != 0) {
                std::cout << "You encounter Lv" << player->areaAge2 << " " << anEnemy->name << endl;
            }
			std::cout << "1. Encounter" << endl;
			std::cout << "2. Visit dollar store" << endl;
			std::cout << "3. Use item" << endl;
			int option = 0;
			std::cout << ">";
			std::cin >> option;

			//attack
			if (option == 1) {
				anEnemy->currentHealth = anEnemy->totalHealth;
				anEnemy->isAlive = true;
				player->coins += player->coinBuff;
				encounterEnemy(player, anEnemy);
			}
			//shop
			if (option == 2) {
				shop(player, enemy);
			}
			//potions
			if (option == 3) {
				potion(player, enemy);
			}
		}
	}
    else
    {
        int answer;
        std::cout << "Dungeon Failed" << endl;
        dungeon(player);
    }
}
		
		

		

int main()
{
	srand(time(NULL));
	string intro =

		"          _____          \n"
		"      __ /__    \\__     \n"
		"   _ /      \\    __\\   \n"
		"  /          \\__ /  \\  \n"
		" |   O          O    |    \n"
		" |      ______      /    \n"
		"  \\     \\____/     /   \n"
		"   \\______________/     \n"

		"  PET ROCK'S DUNGEON ADVENTURE";

	std::cout << intro << endl;

	string playerName;
	std::cout << "What is your rock's name?" << endl;
	std::cout << "> ";
	getline(std::cin, playerName);
    std::cout << "Excellent! Let's get started with " << playerName << "'s Adventure!" << endl;
	this_thread::sleep_for(chrono::milliseconds(1000));
	delayScroll(10, 30);

	character* petRock = new player(playerName, "Just a regular rock.");
    int type = 0;
    type++;
	petRock->setStats(4);
	petRock->isAlive = true;
	anEnemy->isAlive = true;
    while (type > 0) {
        std::cout << "first pick what type of a rock do you want" << endl;
        std::cout << "1. Archer (this type can deal lots of damage while keeping a far distance)" << endl;
        std::cout << "2. Swordsman (this type can soak up damage and be able to strike first)" << endl;
        std::cout << "3. Mage (this type can take life force from an enemy to heal you and disable them for a turn)" << endl;
        std::cout << ">" << endl;
        int optionType;
        cin >> optionType;
        if (optionType == 1) {
            petRock->archer = 1;
            type--;
        }
        else if (optionType == 2) {
            petRock->swordsman = 1;
            type--;
        }
        else if (optionType == 3) {
            petRock->mage = 1;
            type--;
        }
    }
    
    cout << "pss, do u want to become OP." << endl;
        cout << "1.yes" << endl;
        cout << "2.no" << endl;
        cout << ">" << endl;
        int op;
        cin >> op;
    if (op == 1) {
        cout << "don't tell anyone I did this" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        petRock->currentHealth = 1000000;
        petRock->totalHealth = 100000000;
        petRock->damage = 10000;
        petRock->playerLv = 1000;
        petRock->sharpness = 1000;
        petRock->scatter = 1000;
        petRock->flame = 1000;
        petRock->knock = 1;
        petRock->bomb = 1;
        petRock->hardness = 1000;
        petRock->thorn = 1000;
        petRock->firstStrike = 1;
        petRock->sharpen = 1;
        petRock->blazing = 10000;
        petRock->lifeDrain = 1000;
        petRock->lightning = 95;
        petRock->summon = 200;
        petRock->blizzard = 1000;
        petRock->Void = 1000;
    }
    else {
        cout << "your loss" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    dungeon(petRock);
}