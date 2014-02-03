
#include "GameUtils.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Room.h"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

const int TOTAL_ROOMS = 5;
const int TOTAL_ENEMIES = 5;
const int P_HEALTH = 120;
const int P_STAMINA = 100;
const int P_MAGIC = 100;

// TODO Player* player = new Player();
// global player variable

bool GameUtils::battle(int numEnemies) {

	Player* player = new Player(P_HEALTH, P_STAMINA, P_MAGIC, 5, 5, 5);

	Enemy* enemy[numEnemies];
	for (int i = 0; i < numEnemies; i++) {
		//Enemy ID Constructor
		enemy[i] = new Enemy(rand() % TOTAL_ENEMIES + 1);
	}
	
	//Player Variables
	int tactic = 0;
	int enemyNo = 0;
	bool defending = false;

	//Enemy Variables
	int act = 0;
	
	//Damage Calculation
	int d = 0;
	int swordPower = 10;
	int spellPower = 5;
	int armPower = 3;
		
	//Utilities
	int r = 0;
	int i = 0;
	bool end = false;
	bool playerDead;
	char next;
	string in;
	
	//Encounter dialog
	switch(numEnemies) {
		case 1:
			cout << "\nYou encounter an enemy: " << enemy[0]->getName() << "!";
			break;
		case 2:
			cout << "\nYou encounter two enemies: " << enemy[0]->getName() << "\nand " << 
			enemy[1]->getName() << "!";
			break;
		case 3:
			cout << "\nYou encounter three enemies: " << enemy[0]->getName() << ",\n" << 
			enemy[1]->getName() << " and " << enemy[2]->getName() << "!";
			break;
		default:
			cout << "ERROR: numEnemies incorrect";
			break;
	}
	
	cout << "\n" << endl;
	
	while (!end) {
	
		//Stat phase
		player->printAllStats();
		for (i = 0; i < numEnemies; i++)
			enemy[i]->printAllStats();
	
		//Player attack phase
		cout << "\nYour Turn" << endl;
		cout << "(1) Attack\n(2) Magic\n(3) Defend\n";
		getline(cin, in);
		stringstream(in) >> tactic;
		//cin.clear();
		//cin.ignore();
		
		//Attack
		if (tactic == 1) {
		
			enemyNo = 1;
			if (numEnemies > 1) {
				cout << "Which enemy?\n";
				cout << "(1) " << enemy[0]->getName() << "\n(2) " << enemy[1]->getName();
				if (numEnemies > 2)
					cout << "\n(3) " << enemy[2]->getName();
				cout << endl;
				getline(cin, in);
				stringstream(in) >> enemyNo;
				//cin.clear();
				//cin.ignore();
			}

			//TODO store calculations in separate utility class/function
			if (enemyNo == 1 && !(enemy[0]->isDead()) && player->getStat('s') > 0) {
				d = int((player->getStat('t') + swordPower) * ((rand() % 25) + 75) / 100);
				player->setStat('s', max((player->getStat('s') - swordPower), 0));
				enemy[0]->setStat('h', max((enemy[0]->getStat('h') - d), 0));
				cout << "You slash " << enemy[0]->getName() << "! " << d << " damage.";
				if (player->getStat('s') <= 0) cout << "\nYou have no more stamina left!";
			} else if (enemyNo == 2 && numEnemies >= 2 && !(enemy[1]->isDead()) && player->getStat('s') > 0) {
				d = int((player->getStat('t') + swordPower) * ((rand() % 25) + 75) / 100);
				player->setStat('s', max((player->getStat('s') - swordPower), 0));
				enemy[1]->setStat('h', max((enemy[1]->getStat('h') - d), 0));
				cout << "You slash " << enemy[1]->getName() << "! " << d << " damage.";
				if (player->getStat('s') <= 0) cout << "\nYou have no more stamina left!";
			} else if (enemyNo == 3 && numEnemies == 3 && !(enemy[2]->isDead()) && player->getStat('s') > 0){
				d = int((player->getStat('t') + swordPower) * ((rand() % 25) + 75) / 100);
				player->setStat('s', max((player->getStat('s') - swordPower), 0));
				enemy[2]->setStat('h', max((enemy[2]->getStat('h') - d), 0));
				cout << "You slash " << enemy[2]->getName() << "! " << d << " damage.";
				if (player->getStat('s') <= 0) cout << "\nYou have no more stamina left!";
			} else if (player->getStat('s') <= 0) {
				d = int((player->getStat('t') + armPower) * ((rand() % 25) + 75) / 100);
				r = rand() % 3;
				enemy[r]->setStat('h', max((enemy[r]->getStat('h') - d), 0));
				cout << "You flail your arms at " << enemy[r]->getName() << "! " << d << " damage.";			
			} else {
				cout << "Invalid choice. Your slash misses.";
			}
			
		//Magic	
		} else if (tactic == 2) {
		
			if (player->getStat('m') > 0) {
				d = int((player->getStat('i') + spellPower) * ((rand() % 25) + 75) / 100);
				player->setStat('m', max((player->getStat('m') - spellPower * numEnemies), 0));
				for (i = 0; i < numEnemies; i++)
					enemy[i]->setStat('h', max((enemy[i]->getStat('h') - d), 0));
				cout << "You cast magic! " << d << " damage to all enemies.";
				if (player->getStat('m') <= 0) cout << "\nYou have no more magic left!";
			} else {
				cout << "You have no magic! Sparks sputter helplessly from your fingertips.";
			}
		
		//Defend
		} else if (tactic == 3) {
			bool defending = true;
			if (player->getStat('h') == P_HEALTH) {
				cout << "You defend! You heal nothing (already at full health) but you are protected.";
			} else {
				d = int((player->getStat('c')) * numEnemies * ((rand() % 25) + 75) / 100);
				player->setStat('h', min((player->getStat('h') + d), P_HEALTH));
				cout << "You defend! You heal " << d << " health points and you are protected.";
			}
		} else {
			cout << "Invalid choice. You recoil in pain.";
		}
		
		cout << "\n" << endl;
		
		//Check enemy status
		for (i = 0; i < numEnemies; i++) {
			if (!(enemy[i]->isDead()) && enemy[i]->getStat('h') <= 0) {
				cout << "Enemy " << i + 1 << ": " << enemy[i]->getName() << " died!\n" << endl;
				enemy[i]->setDead(true);
			}
		}
		if ((numEnemies == 1 && enemy[0]->isDead()) ||
				(numEnemies == 2 && enemy[0]->isDead() && enemy[1]->isDead()) ||
				(numEnemies == 3 && enemy[0]->isDead() && enemy[1]->isDead() && enemy[2]->isDead()))
			end = true;
		
		//Enemy attack phase
		for (i = 0; i < numEnemies; i++) {
			if (!(enemy[i]->isDead()) && !(player->isDead())) {
				cout << "Enemy " << i + 1 << ": " << enemy[i]->getName() << "'s Turn" << endl;
				act = rand() % 5 + 1;
				if (act != 5 && act % 2 == 1 && enemy[i]->getStat('s') > 0) {
					d = int((enemy[i]->getStat('t') + swordPower) * ((rand() % 25) + 75) / 100);
					enemy[i]->setStat('s', max((enemy[i]->getStat('s') - swordPower), 0));
					if (defending) d = d / 2;
					player->setStat('h', max((player->getStat('h') - d), 0));
					cout << enemy[i]->getName() << " attacks you! " << d << " damage.";
				} else if (act % 2 == 0 && enemy[i]->getStat('m') > 0) {
					d = int((enemy[i]->getStat('i') + spellPower) * ((rand() % 25) + 75) / 100);
					enemy[i]->setStat('m', max((enemy[i]->getStat('m') - spellPower * numEnemies), 0));
					if (defending) d = d / 2;
					player->setStat('h', max((player->getStat('h') - d), 0));
					cout << enemy[i]->getName() << " casts magic! " << d << " damage.";
				} else {
					cout << enemy[i]->getName() << " cowers in fear.";
				}
				cout << "\n" << endl;
			}
		}
		
		/*
		Outmoded (from v0.1)
		
		//Enemy 1 attack phase
		if (!isDead()1) {
			cout << "Enemy 1's Turn" << endl;
			act = rand() % 5 + 1;
			if (act != 5 && act % 2 == 1 && enemy1->getStat('s') > 0) {
				d = int((enemy1->getStat('t') + armPower) * ((rand() % 25) + 75) / 100);
				player->setStat('h', max((player->getStat('h') - d), 0));
				cout << "Fiend Crow scratches you! You lose " << d << " health points." << endl;
			} else if (act % 2 == 0 && enemy1->getStat('m') > 0) {
				d = int((enemy1->getStat('i') + spellPower) * ((rand() % 25) + 75) / 100);
				player->setStat('h', max((player->getStat('h') - d), 0));
				cout << "Fiend Crow zaps you! You lose " << d << " health points." << endl;
			} else {
				cout << "Fiend Crow cowers in fear." << endl;
			}
			cout << endl;
		}
		
		//Enemy 2 attack phase
		if (!isDead()2) {
			cout << "Enemy 2's Turn" << endl;
			act = rand() % 5 + 1;
			if (act != 5 && act % 2 == 1 && enemy2->getStat('s') > 0) {
				d = int((enemy2->getStat('t') + armPower * 2) * ((rand() % 25) + 75) / 100);
				player->setStat('h', max((player->getStat('h') - d), 0));
				cout << "Blood Wraith bites you! You lose " << d << " health points." << endl;
			} else if (act % 2 == 0 && enemy2->getStat('m') > 0) {
				d = int((enemy2->getStat('i') + spellPower) * ((rand() % 25) + 75) / 100);
				player->setStat('h', max((player->getStat('h') - d), 0));
				cout << "Blood Wraith phases through your body! You lose " << d << " health points." << endl;
			} else {
				cout << "Blood Wraith stands motionless." << endl;
			}
			cout << endl;
		}
		*/
				
		//End phase
		if (defending) defending = false;

		if (player->getStat('h') <= 0) {
			cout << "You died!\n" << endl;
			player->setDead(true);
			end = true;
		}
	}

	if (player->isDead()) {
		cout << "Game Over!" << endl;
	} else {
		cout << "You win!\n" << endl;
		player->setStat('h', P_HEALTH);
		player->setStat('s', P_STAMINA);
		player->setStat('m', P_MAGIC);
	}
	
	playerDead = player->isDead();
	
	delete player;
	for (i = 0; i < numEnemies; i++)
		delete enemy[i];
	
	return playerDead;
	
}

void GameUtils::treasure(/*Player p*/) {

	//discover treasure (no battle)
	//TODO should result in stat bonus
	
	cout << "\nYou find a few coins! You put them in your pocket for safekeeping.\n" << endl;
	
}

void GameUtils::empty() {
	
	//nothing happens
	//TODO extra description?
	
	cout << "\nThere are no monsters here, so you can make your way to the exit safely.\n" << endl;
	
}

void GameUtils::configPlayer() {

	//does it return a new Player
	//or adjust Player stats
	//through setters?
	//if latter, this should be
	//placed in Player.cpp and
	//invoked on Player object

}

void GameUtils::game() {

	/* Game Flow
	 * 
	 * Zeroth Room (intro--always empty);
	 * left, right, or forward door;
	 * new room + random description;
	 * each room has random chance of:
	 * * one monster
	 * * two monsters
	 * * three monsters
	 * * treasure
	 * * empty
	 * after encounter, 1, 2, or 3 doors
	 * * fake choice--no consistent map generation
	 * TODO: after defined cutoff, final room
	 * is added to random rotation;
	 * end of game when:
	 * * death of player
	 * * TODO: beat final boss and gain treasure
	 */
	
	//Player player;
	Room* room;
	
	int roomID;
	int numDoors;
	int door = 0;
	int r;
	
	bool valid = false;
	bool playerDead = false;
	
	string in;
	
	//TODO add configPlayer()
	//configPlayer();
	//player = new Player();
	
	do {
	
		cout << "\nYou enter the next room.\n" << endl;
		
		//Generate Room
		roomID = (rand() + door) % TOTAL_ROOMS + 1;
		numDoors = rand() % 3 + 1;
		room = new Room(roomID, numDoors);
		cout << room->getDescription();
		cin.ignore();
		
		//Determine encounter
		r = rand() % 10 + 1;
		if (r <= 3) {
			playerDead = battle(1);
		} else if (r >= 4 && r <= 5) {
			playerDead = battle(2);
		} else if (r == 6) {
			playerDead = battle(3);
		} else if (r >= 7 && r <= 8) {
			treasure();
			//player = new Player();
			//TODO treasure() changes player stats
		} else {
			empty();
		}
		
		//Choose next door
		if (!(playerDead)) {
			valid = false;
			while (!valid) {
				cout << room->getDoorQuery();
				getline(cin, in);
				stringstream(in) >> door;
				//cin.clear();
				//cin.ignore();
				if ((numDoors == 1) ||
				(numDoors == 2 && (door == 1 || door == 2)) ||
				(numDoors == 3 && (door == 1 || door == 2 || door == 3))) {
					valid = true;
				} else {
					cout << "Invalid choice.\n" << endl;
				}
			}
		}
		
		//Delete current room
		delete room;

	} while (!(playerDead));
}
