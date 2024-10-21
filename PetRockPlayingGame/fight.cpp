#include "player.h"
#include <chrono>
#include <thread>
using namespace std;



string basicAVsA = "The enemy also shoots an arrow and you trade shots.";
string basicAVsS = "The enemy pulls out and sword as your arrow hits him.";
string basicAVsM = "The enemy cast a spell on you that disabled and damaged you.";

string basicSVsS = "The enemy swings with his own sword and you trade.";
string basicSVsM = "The enemy shoots a fireball at you but your armor blocks the damage";
string basicSVsA = "The enemy hits you from afar with an arrow.";

string basicMVsM = "You both cast curses at each other doing damage to both.";
string basicMVsA = "You summoned wind that defected the enemy's arrow back at him.";
string basicMVsS = "Your spell have no effect on the enemy's armor and he hits you with his sword";

void player::rdFight(character* player, character* enemy) {
    player->turns++;
    random_device rd;
    int randomNum;
    int crit = 1;
    randomNum = rd() % 100 - enemy->missingChance;
    if (randomNum == 1) {
        enemy->miss = true;
        cout << "The Enemy Missed!" << endl;
    }
    randomNum = rd() % 100 - player->missingChance;
    if (randomNum == 1) {
        player->miss = true;
        cout << "You Missed!" << endl;
    }
    randomNum = rd() % 5;
    if (randomNum == 3) {
        player->damage = player->damage * 2;
        crit++;
    }
    if (archer == 1) {
    randomNum = rd() % 3;
    if (randomNum == 0) {
        cout << basicAVsA << endl;
        if (player->miss == false) {
            enemy->currentHealth -= player->damage;
            cout << player->name << " hit " << enemy->name << " for " << player->damage << " damage." << endl;
            cout << enemy->name << " is at " << enemy->currentHealth << "/" << enemy->totalHealth << " health." << endl;
            if (usedFlame == true) {
                flameActive = true;
            }
        }
        if (enemy->miss == false) {
            player->currentHealth -= enemy->damage;
            cout << enemy->name << " hit " << player->name << " for " << enemy->damage << " damage." << endl;
            cout << player->name << " is at " << player->currentHealth << "/" << player->totalHealth << " health." << endl;
        }
    }
    if (randomNum == 1) {
        cout << basicAVsS << endl;
        if (player->miss == false) {
            enemy->currentHealth -= player->damage;
            cout << player->name << " hit " << enemy->name << " for " << player->damage << " damage." << endl;
            cout << enemy->name << " is at " << enemy->currentHealth << "/" << enemy->totalHealth << " health." << endl;
            if (usedFlame == true) {
                flameActive = true;
            }
        }
    }
    if (randomNum == 2) {
        cout << basicAVsM << endl;
        if (enemy->miss == false) {
            player->currentHealth -= enemy->damage;
            cout << enemy->name << " hit " << player->name << " for " << enemy->damage << " damage." << endl;
            cout << player->name << " is at " << player->currentHealth << "/" << player->totalHealth << " health." << endl;
        }
        }
    if (crit == 2) {
        crit--;
        player->damage = player->damage / 2;
    }
    if (crit == 2 && randomNum != 2) {
        cout << "Critical hit!" << endl;
    }
}
    if (swordsman == 1) {
        randomNum = rd() % 3;
        if (randomNum == 0) {
            cout << basicSVsS << endl;
            if (player->miss == false) {
                if (open != 1) {
                    enemy->currentHealth -= player->damage;
                    cout << player->name << " hit " << enemy->name << " for " << player->damage << " damage." << endl;
                    cout << enemy->name << " is at " << enemy->currentHealth << "/" << enemy->totalHealth << " health." << endl;
                    if (usedBleed == true) {
                        player->bleedActive = true;
                    }
                }
                else {
                    player->damage *= 2;
                    openDone = true;
                }
            }
            if (enemy->miss == false) {
                player->currentHealth -= enemy->damage;
                cout << enemy->name << " hit " << player->name << " for " << enemy->damage << " damage." << endl;
                cout << player->name << " is at " << player->currentHealth << "/" << player->totalHealth << " health." << endl;
                if (player->thorn > 0) {
                    enemy->currentHealth -= player->thorn;
                        cout << "You did " << player->thorn << " thorn damage" << endl;
                        cout << enemy->name << " is at " << enemy->currentHealth << "/" << enemy->totalHealth << " health." << endl;
                }
            }
        }
        if (randomNum == 1) {
            cout << basicSVsM << endl;
            if (player->miss == false) {
                if (open != 1) {
                    enemy->currentHealth -= player->damage;
                    cout << player->name << " hit " << enemy->name << " for " << player->damage << " damage." << endl;
                    cout << enemy->name << " is at " << enemy->currentHealth << "/" << enemy->totalHealth << " health." << endl;
                }
                else {
                    player->damage *= 2;
                    openDone = true;
                }
            }
        }
        if (randomNum == 2) {
            cout << basicSVsA << endl;
            if (enemy->miss == false) {
                player->currentHealth -= enemy->damage;
                cout << enemy->name << " hit " << player->name << " for " << enemy->damage << " damage." << endl;
                cout << player->name << " is at " << player->currentHealth << "/" << player->totalHealth << " health." << endl;
                if (player->thorn > 0) {
                    enemy->currentHealth -= player->thorn;
                        cout << "You did " << player->thorn << " thorn damage" << endl;
                        cout << enemy->name << " is at " << enemy->currentHealth << "/" << enemy->totalHealth << " health." << endl;
                }
            }
        }
        if (crit == 2) {
            crit--;
            player->damage = player->damage / 2;
        }
        if (crit == 2 && randomNum != 2) {
            cout << "Critical hit!" << endl;
        }
        open = false;
    }
    if (mage == 1) {
        randomNum = rd() % 3;
        if (randomNum == 0) {
            if (player->summon >= 1 && player->usingSummon == true) {
                summonChance = rd() % summon;
                player->damage = player->damage + summonChance;
                if (summonChance >= 1000) {
                    basicMVsM = "You summon a house on top of your enemy";
                }
                else if (summonChance >= 500) {
                    basicMVsM = "You summon a boat on top of your enemy";
                }
                else if (summonChance >= 100) {
                    basicMVsM = "You summon a tree on top of your enemy";
                }
                else if (summonChance >= 50) {
                    basicMVsM = "You summon a mailbox on top of your enemy";
                }
                else if (summonChance >= 10) {
                    basicMVsM = "You summon a rock on top of your enemy";
                }
                else if (summonChance > 0) {
                    basicMVsM = "You summon a pebble on top of your enemy";
                }
                else{
                    basicMVsM = "You summon... absolutely nothing";
                }
                usingSummon = false;
            }
            cout << basicMVsM << endl;
            if (player->miss == false) {
                
                enemy->currentHealth -= player->damage;
                cout << player->name << " hit " << enemy->name << " for " << player->damage << " damage." << endl;
                cout << enemy->name << " is at " << enemy->currentHealth << "/" << enemy->totalHealth << " health." << endl;
                if (player->lifeDrain >= 1 && player->usingDrain == true) {
                    player->usingDrain = false;
                    player->currentHealth += player->lifeDrain;
                    if (player->currentHealth > player->totalHealth) {
                        player->currentHealth = player->totalHealth;
                    }
                    cout << player->name << " heals " << player->lifeDrain << "hp" << endl;
                    cout << player->name << " is at " << player->currentHealth << "/" << player->totalHealth << " health." << endl;
                }
                if (player->lightning >= 1 && player->usingLightning == true) {
                    int randomNumb = rd() % (100 - player->lightning);
                    if (randomNumb == 1) {
                        enemy->miss = true;
                        cout << "the enemy is stunned" << endl;
                    }
                    player->usingLightning = false;
                }
            }
            if (enemy->miss == false) {
                player->currentHealth -= enemy->damage;
                cout << enemy->name << " hit " << player->name << " for " << enemy->damage << " damage." << endl;
                cout << player->name << " is at " << player->currentHealth << "/" << player->totalHealth << " health." << endl;
            }
        }
        if (randomNum == 1) {
            if (player->summon >= 1 && player->usingSummon == true) {
                summonChance = rd() % summon;
                player->damage = player->damage + summonChance;
                if (summonChance >= 1000) {
                    basicMVsA = "You summon a house on top of your enemy";
                }
                else if (summonChance >= 500) {
                    basicMVsA = "You summon a boat on top of your enemy";
                }
                else if (summonChance >= 100) {
                    basicMVsA = "You summon a tree on top of your enemy";
                }
                else if (summonChance >= 50) {
                    basicMVsA = "You summon a mailbox on top of your enemy";
                }
                else if (summonChance >= 10) {
                    basicMVsA = "You summon a rock on top of your enemy";
                }
                else if (summonChance > 0) {
                    basicMVsA = "You summon a pebble on top of your enemy";
                }
                else {
                    basicMVsA = "You summon... absolutely nothing";
                }
                usingSummon = false;
            }
            cout << basicMVsA << endl;
            if (player->miss == false) {
                enemy->currentHealth -= player->damage;
                cout << player->name << " hit " << enemy->name << " for " << player->damage << " damage." << endl;
                cout << enemy->name << " is at " << enemy->currentHealth << "/" << enemy->totalHealth << " health." << endl;
                if (player->lifeDrain >= 1 && player->usingDrain == true) {
                    player->currentHealth += player->lifeDrain;
                    if (player->currentHealth > player->totalHealth) {
                        player->currentHealth = player->totalHealth;
                    }
                    cout << player->name << " heals " << player->lifeDrain << "hp" << endl;
                    cout << player->name << " is at " << player->currentHealth << "/" << player->totalHealth << " health." << endl;
                    player->usingDrain = false;
                }
            }
        }
        if (randomNum == 2) {
            cout << basicMVsS << endl;
            if (enemy->miss == false) {
                player->currentHealth -= enemy->damage;
                cout << enemy->name << " hit " << player->name << " for " << enemy->damage << " damage." << endl;
                cout << player->name << " is at " << player->currentHealth << "/" << player->totalHealth << " health." << endl;
            }
        }
        if (crit == 2) {
            crit--;
            player->damage = player->damage / 2;
        }
        if (crit == 2 && randomNum != 2) {
            cout << "Critical hit!" << endl;
        }
    }
    this_thread::sleep_for(chrono::milliseconds(1000));
}

void player::fight(character* player, character* other)
{
    if (Knock == true) {
        Knock = false;
        return;
    }
    random_device rd;
    int randomNumb;
    int option;
    cout << "" << endl;
    if (player->archer == 1) {
        cout << "1. Arrow" << endl;
        if (player->sharpness > 0 ) {
            cout << "2. Sharpness Arrow" << endl;
        }
        if (player->bomb > 0) {
            cout << "3. Bomb" << endl;
        }
        if (player->knock > 0) {
            cout << "4. Knockback" << endl;
        }
        if (player->flame > 0) {
            cout << "5. Flame Arrow" << endl;
        }
        if (player->scatter > 0) {
            cout << "6. Scatter Arrow" << endl;
        }
        cout << ">" << endl;
        cin >> option;
        if (option == 1) {
            basicAVsA = "The enemy also shoots an arrow and you trade shots.";
            basicAVsS = "The enemy pulls out and sword as your arrow hits him.";
            basicAVsM = "The enemy cast a spell on you that disabled and damaged you.";
            rdFight(player, other);
        }
        else if (option == 2 && player->sharpness > 0) {
            player->damage = player->damage + player->sharpness;
            basicAVsA = "You trade shots with the enemy but you deal more damage";
            basicAVsS = "Your sharp arrow cuts through the enemy's armor";
            basicAVsM = "The enemy points a wand at you and your hand forcefully drops your bow";
            rdFight(player, other);
            player->damage = player->damage - player->sharpness;
        }
        else if (option == 3 && player->bomb > 0) {
            bombPlaced = true;
            basicAVsA = "Your bomb hits the enemy as the enemy's arrow hits you";
            basicAVsS = "Your bomb knocks the enemy senseless";
            basicAVsM = "The enemy conjures a shield to block the hit";
            rdFight(player, other);
        }
        else if (option == 4 && player->knock > 0) {
            cout << "You Knock the enemy back giving you time to take stock" << endl;
            Knock = true;
            return;
        }
        else if (option == 5 && player->flame > 0) {
            usedFlame = true;
            basicAVsA = "You trade shots with the enemy but the enemy is now on fire.";
            basicAVsS = "Your flame arrow stops the enemy in its tracks";
            basicAVsM = "The enemy sucks the flame into a vortex";
            rdFight(player, other);
        }
        else if (option == 6 && player->scatter > 0) {
            player->scatter++;
            randomNumb = rd() % player->scatter;
            player->damage = player->damage * randomNumb;
            cout << "You hit the enemy with " << randomNumb << " shots" << endl;
            basicAVsA = "You trade shots with the enemy but you hit it with more shots";
            basicAVsS = "You overwhelmed the enemy with arrows from afar";
            basicAVsM = "The enemy summons a zombie from the dead to block all the hits";
            rdFight(player, other);
            player->damage = player->damage / randomNumb;
            player->scatter--;
        }
    }
    if (player->swordsman== 1) {
        cout << "1. Sword" << endl;
        if (player->sharpen > 0) {
            cout << "2. Sharpen" << endl;
        }
        if (player->blazing > 0) {
            cout << "3. Blazing Blades" << endl;
        }
        cout << ">" << endl;
        cin >> option;
        if (option == 1) {
            basicSVsS = "The enemy swings with his own sword and you trade.";
            basicSVsM = "The enemy shoots a fireball at you but your armor blocks the damage";
            basicSVsA = "The enemy hits you from afar with an arrow.";
            rdFight(player, other);
        }
        else if (option == 2 && player->sharpen == 1) {
            player->damage = player->damage * 2;
            basicSVsA = "You get shot while trying to sharpen your sword";
            basicSVsS = "The enemy hits you with a sword but you successfully sharpen your sword";
            basicSVsM = "The enemy points a wand And nothing happens so you successfully sharpen your sword";
            open = 1;
            rdFight(player, other);
            open = 0;
        }
        else if (option == 3 && player->blazing > 0) {
            usedBleed = true;
            basicSVsA = "Your arm is hit with an arrow and you drop your sword";
            basicSVsS = "You swing your sword maddly but you are still hit";
            basicSVsM = "You strike the enemy as they start to cast a spell and do full damage";
            bleedActive = true;
            rdFight(player, other);
        }
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
    if (player->mage == 1) {
        cout << "1. Fireball" << endl;
        if (player->sharpness > 0) {
            cout << "2. Life drain" << endl;
        }
        if (player->bomb > 0) {
            cout << "3. Lightning" << endl;
        }
        if (player->knock > 0) {
            cout << "4. Summon" << endl;
        }
        if (player->flame > 0) {
            cout << "5. Bizzard" << endl;
        }
        if (player->scatter > 0) {
            cout << "6. Void" << endl;
        }
        cout << ">" << endl;
        cin >> option;
        if (option == 1) {
            basicMVsM = "You both cast curses at each other doing damage to both.";
            basicMVsA = "You summoned wind that defected the enemy's arrow back at him.";
            basicMVsS = "Your spell have no effect on the enemy's armor and he hits you with his sword";
            rdFight(player, other);
        }
        else if (option == 2 && player->lifeDrain > 0) {
            player->usingDrain = true;
            basicMVsA = "You suck out the enemy's life source healing you";
            basicMVsS = "You spell has no effect and you are hit";
            basicMVsM = "The enemy also cast a spell and you both take damage";
            rdFight(player, other);
        }
        else if (option == 3 && player->lightning > 0) {
            player->usingLightning = true;
            basicMVsA = "You strike the enemy with a bolt";
            basicMVsS = "The enemy strikes you before you start";
            basicMVsM = "The enemy also hits you with a spell";
            rdFight(player, other);
            stun = 0;
        }
        else if (option == 4 && player->summon > 0) {
            usingSummon = true;
            basicMVsA = "You summon a object that blocks an enemy's shot and hits them";
            basicMVsS = "The enemy bats away the object and hits you in the chest";
            basicMVsM = "The enemy also summons an object and you are both hit";
            rdFight(player, other);
            summonChance = 0;
        }
        else if (option == 5 && player->blizzard > 0) {
            other->missingChance += blizzard;
            basicMVsA = "You conjure a blizzard that tosses an arrow back at the enemy";
            basicMVsS = "The enemy dives you with a sword";
            basicMVsM = "The enemy wraps vines around you and you both take damage";
            rdFight(player, other);
            other->missingChance -= blizzard;
        }
        else if (option == 6 && player->Void > 0) {
            player->missingChance = 0;
            basicMVsA = "You suck the enemy into the void";
            basicMVsS = "the enemy hits you as the void pull them in";
            basicMVsM = "You are hit by something invisible as the enemy gravitates towards the void";
            rdFight(player, other);
            player->missingChance = 5;
        }
    }
    if (flameActive == true) {
        other->currentHealth -= player->flame;
        cout << "The enemy took " << player->flame << " flame damage" << endl;
        cout << other->name << " is at " << other->currentHealth << "/" << other->totalHealth << " health." << endl;
    }
    if (bleedActive == true) {
        other->currentHealth -= player->blazing;
        cout << "The enemy took " << player->blazing << " bleed damage" << endl;
        cout << other->name << " is at " << other->currentHealth << "/" << other->totalHealth << " health." << endl;
    }
    if (player->bombPlaced == true) {
        if (player->turns == 3) {
            player->damage = player->damage * bomb;
            cout << "The bomb has blown!" << endl;
            other->currentHealth -= player->damage;
            cout << player->name << " hit " << other->name << " for " << player->damage << " damage with a bomb." << endl;
            cout << other->name << " is at " << other->currentHealth << "/" << other->totalHealth << " health." << endl;
            player->damage = player->damage / 3;
        }
    }
    if (player->currentHealth > 0) {
        player->isAlive = true;
    }
    else if (player->currentHealth <= 0) {
        player->isAlive = false;
        player->bombPlaced = false;
        player->flameActive = false;
        std::cout << "Dungeon Failed" << endl;
    }
	if (other->currentHealth > 0) {
		other->isAlive = true;
	}
	else if (other->currentHealth <=0) {
		other->isAlive = false;
        player->enemyDeaths++;
        player->bombPlaced = false;
        player->flameActive = false;
        std::cout << "The enemy dropped " << coinBuff << " coin(s)" << endl;
        std::cout << "+" << player->enemyXp << "Xp" << endl;
        player->playerXp = player->playerXp + player->enemyXp;
        if(playerXp >= tPlayerXp && player->currentHealth > 0){
        while (playerXp >= tPlayerXp && player->currentHealth > 0) {
            player->playerLv++;
            player->damage += playerLv;
            player->currentHealth += playerLv;
            player->totalHealth += playerLv;
            std::cout << "You leveled up" << endl;
            std::cout << "You are now Lv" << player->playerLv << endl;
            std::cout << player->playerXp << "/" << player->tPlayerXp << "Xp" << endl;
            player->tPlayerXp = player->tPlayerXp * 3;
        }
                player->unlockPoints++;
                std::cout << "Your next level requires " << player->tPlayerXp << "Xp" << endl;
                std::cout << player->playerXp << "/" << player->tPlayerXp << "Xp" << endl;
                std::cout << "You now get to choose what to unlock or upgrade" << endl;
                std::cout << player->space << endl;
                int powerOpt = 0;
                if (player->archer == 1 && player->unlockPoints > 0) {
                    while (player->unlockPoints > 0) {
                        std::cout << "1.Sharpness (User arrows deal 5 more damage, upgrading would add 5, level requirement of 1)" << endl;
                        std::cout << "2.Bomb (User throws a bomb that explodes, dealing massive damage after 3 turns, level requirement of 20)" << endl;
                        std::cout << "3.Knockback (User shoots an arrow that knocks the enemy out and allows you to buy and use potions, level requirement of 40)" << endl;
                        std::cout << "4.Flame (The enemy catches fire causing it to frequently takes damage until it dies, upgrading would add more damage, level requirement of 60)" << endl;
                        std::cout << "5.Scatter shot (User shoots 3 arrows and has a chance up to x3 more damage, upgrading would add 3 arrow more, level requirement of 80)" << endl;
                        std::cout << ">" << endl;
                        cin >> powerOpt;
                        if (powerOpt == 1) {
                            levelSharp++;
                            player->sharpness += 10;
                            std::cout << "You upgraded sharpness" << endl;
                            std::cout << "Lv" << levelSharp << endl;
                            player->unlockPoints--;
                        }
                        else if (powerOpt == 2 && playerLv >= 20 && bomb != 1) {
                            player->bomb += 1;
                            std::cout << "You unlocked Bomb" << endl;
                            player->unlockPoints--;
                        }
                        else if (powerOpt == 3 && playerLv >= 40 && knock != 1) {
                            player->knock += 1;
                            std::cout << "You unlocked Knockback" << endl;
                            player->unlockPoints--;
                        }
                        else if (powerOpt == 4 && playerLv >= 60) {
                            levelFlam++;
                            player->flame += playerLv;
                            std::cout << "You upgraded flame" << endl;
                            std::cout << "Lv" << levelFlam << endl;
                            player->unlockPoints--;
                        }
                        else if (powerOpt == 5 && playerLv >= 80) {
                            levelScat++;
                            player->scatter += 3;
                            std::cout << "You upgraded scatter shot" << endl;
                            std::cout << "Lv" << levelScat << endl;
                            player->unlockPoints--;
                        }
                        else {
                            std::cout << "You can't upgrade this" << endl;
                        }
                    }
                }
                if (player->swordsman == 1 && player->unlockPoints > 0) {
                    while (player->unlockPoints > 0) {
                        std::cout << "1.Hardness (User gains increased amount of health, upgrading would increase health, level requirement of 1)" << endl;
                        std::cout << "2.Sharpen (User takes a turn sharpening their sword, making it do double damage for the rest of the fight, level requirement of 20)" << endl;
                        std::cout << "3.Thorn (When an enemy hits you they take damage, upgrading would increase that damage, level requirement of 40)" << endl;
                        std::cout << "4.First strike (User always hits first so the enemy dies before it could hit you, level requirement of 60)" << endl;
                        std::cout << "5.Blazing Blades (User hits the enemy making them have a bleed effect, this can stack, upgrading would increase the damage for bleeding, level requirment of 80)" << endl;
                        std::cout << ">" << endl; 
                        cin >> powerOpt;
                        if (powerOpt == 1) {
                            levelHard++;
                            player->hardness += 10;
                            std::cout << "You upgraded hardness" << endl;
                            std::cout << "Lv" << levelHard << endl;
                            player->totalHealth = player->totalHealth + 5;
                            player->currentHealth = player->currentHealth + 5;
                            std::cout << "Your health is now " << currentHealth << "/" << totalHealth << endl;
                            player->unlockPoints--;
                        }
                        else if (powerOpt == 2 && player->sharpen != 1 && playerLv >= 20) {
                            player->sharpen = 1;
                            std::cout << "You unlocked sharpen" << endl;
                            player->unlockPoints--;
                        }
                        else if (powerOpt == 3 && playerLv >= 40) {
                            levelThorn++;
                            player->thorn += 10;
                            std::cout << "You upgraded thorn" << endl;
                            std::cout << "Lv" << levelThorn << endl;
                            player->unlockPoints--;
                        }
                        else if (powerOpt == 4 && player->firstStrike != 1 && playerLv >= 60) {
                            player->firstStrike = 1;
                            std::cout << "You unlocked firstStrike" << endl;
                            player->unlockPoints--;
                        }
                        else if (powerOpt == 5 && playerLv >= 80) {
                            levelBlaze++;
                            player->blazing = player->blazing + playerLv;
                            std::cout << "You upgraded blazing blades" << endl;
                            std::cout << "Lv" << levelBlaze << endl;
                            player->unlockPoints--;
                        }
                        else {
                            std::cout << "You can't upgrade that" << endl;
                            std::cout << "" << endl;
                        }
                    }
                }
                if (mage == 1 && unlockPoints > 0) {
                    while (player->unlockPoints > 0) {
                        std::cout << "1.Life drain (User takes life force from the enemy and uses it to heal him/herself, upgrading would buff the amount of healing you get)" << endl;
                        std::cout << "2.lightning (Has a 30% chance at stunning enemy from taking his next turn, upgrading would increase the chance)" << endl;
                        std::cout << "3.Summon (User summons and random item that ramdomly adds a lot or a little more damge, upgrading will increase your chance of more damage)" << endl;
                        std::cout << "4.Blizzird (User creates a blizzard that hinders the enemy's ability to see causing misses, upgrading will increase damage)" << endl;
                        std::cout << "5.Void (User produces a void that has 100% accuracy and never misses, upgrading will increase damage)" << endl;
                        std::cout << ">" << endl; 
                        cin >> powerOpt;
                        if (powerOpt == 1) {
                            levelDrain++;
                            player->lifeDrain += 10;
                            std::cout << "You upgraded life drain" << endl;
                            std::cout << "Lv" << levelDrain << endl;
                            player->unlockPoints--;
                        }
                        else if (powerOpt == 2 && player->lightning <= 90 && player->playerLv >= 20) {
                            levelLight++;
                            player->lightning += 5;
                            std::cout << "You upgraded lightning" << endl;
                            std::cout << "Lv" << levelLight << endl;
                            player->unlockPoints--;
                        }
                        else if (powerOpt == 3 && player->playerLv >= 40) {
                            levelSummon++;
                            player->summon += 5;
                            std::cout << "You upgraded summon" << endl;
                            std::cout << "Lv" << levelSummon << endl;
                            player->unlockPoints--;
                        }
                        else if (powerOpt == 4 && player->playerLv >= 60) {
                            levelBliz++;
                            player->blizzard += 5;
                            std::cout << "You upgraded Blizzard" << endl;
                            std::cout << "Lv" << levelBliz << endl;
                            player->unlockPoints--;
                        }
                        else if (powerOpt == 5 && player->playerLv >= 80) {
                            levelVoid++;
                            player->Void += playerLv;
                            std::cout << "You upgraded Void" << endl;
                            std::cout << "Lv" << levelVoid << endl;
                            player->unlockPoints--;
                        }
                        else {
                            std::cout << "You can't upgrade that" << endl;
                            std::cout << "" << endl;
                        }
                    }
                }
            }
	}
    this_thread::sleep_for(chrono::milliseconds(1000));
}


void player::setStats(int level)
{
    int x = 0;
	int baseStat = level * 2;
	x = rand() % baseStat + level;

	damage = x;
	currentHealth = totalHealth = x * 3;
}

void player::setAlive(bool status) {
	isAlive = status;
}