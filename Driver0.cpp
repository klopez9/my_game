
#include "Character.h"
#include <iostream>
#include <algorithm>

using namespace std;

void driver0() {

	Character* player = new Character(100, 100, 100, 5, 5, 5, "Player");
	
	int i[6];
	int j;
	for (j = 0; j < 6; j++)
		i[j] = rand() % 35 + 40;
	
	Character* enemy1 = new Character(i[0], i[1], i[2], 1, 1, 1, "Enemy 1");
	Character* enemy2 = new Character(i[3], i[4], i[5], 1, 3, 3, "Enemy 2");
	
	int en = 0;
	int d = 0;
	int act = 0;
	int swordPower = 10;
	int spellPower = 5;
	int armPower = 3;
	bool gameEnd = false;
	bool isDead1 = false;
	bool isDead2 = false;
	char attack;
	char next;
	
	cout << "\nYou encounter two enemies: Thunder Crow and Blood Wraith!" << endl;
	
	while (!gameEnd) {
	
		//Status phase
		
		/*
		cout << "-------------------Player--------------------" <<
						"\nHealth: " << player->getStat('h') << "/" << 100 <<
						"\tStamina: " << player->getStat('s') << "/" << 100 <<
						"\tMagic: " << player->getStat('m') << "/" << 100 << "\n" << 
						"-------------------Enemy 1--------------------" <<
						"\nHealth: " << enemy1->getStat('h') << "/" << i[0] <<
						"\tStamina: " << enemy1->getStat('s') << "/" << i[1] <<
						"\tMagic: " << enemy1->getStat('m') << "/" << i[2] << "\n" <<
						"-------------------Enemy 2--------------------" <<
						"\nHealth: " << enemy2->getStat('h') << "/" << i[3] <<
						"\tStamina: " << enemy2->getStat('s') << "/" << i[4] << 
						"\tMagic: " << enemy2->getStat('m') << "/" << i[5] << endl;
		*/
		
		player->printAllStats(100, 100, 100);
		enemy1->printAllStats(i[0], i[1], i[2]);
		enemy2->printAllStats(i[3], i[4], i[5]);
	
		//Player attack phase
		cout << "\nYour Turn" << endl;
		cout << "Use 's'lash, cast 'f'ire, or 'r'est?: ";
		cin >> attack;
		if (attack == 's' || attack == 'S') {
			cout << "Which enemy, 1 or 2?: ";
			cin >> en;
			if (en == 1 && !isDead1 && player->getStat('s') > 0) {
				d = int((player->getStat('t') + swordPower) * ((rand() % 25) + 75) / 100);
				player->setStat('s', max((player->getStat('s') - swordPower), 0));
				enemy1->setStat('h', max((enemy1->getStat('h') - d), 0));
				cout << "You slash Thunder Crow! " << d << " damage.";
			} else if (en == 2 && !isDead2 && player->getStat('s') > 0) {
				d = int((player->getStat('t') + swordPower) * ((rand() % 25) + 75) / 100);
				player->setStat('s', max((player->getStat('s') - swordPower), 0));
				enemy2->setStat('h', max((enemy2->getStat('h') - d), 0));
				cout << "You slash Blood Wraith! " << d << " damage.";
			} else {
				cout << "Invalid choice. Your slash misses.";
			}
		} else if (attack == 'f' || attack == 'F') {
			d = int((player->getStat('i') + spellPower) * ((rand() % 25) + 75) / 100);
			player->setStat('m', max((player->getStat('m') - spellPower * 2), 0));
			enemy1->setStat('h', max((enemy1->getStat('h') - d), 0));
			enemy2->setStat('h', max((enemy2->getStat('h') - d), 0));
			cout << "You cast fire! " << d << " damage to both enemies.";
		} else if (attack == 'r' || attack == 'R') {
			if (player->getStat('h') == 100) {
				cout << "You are already at full health!";
			} else {
				d = int((player->getStat('c')) * ((rand() % 25) + 75) / 100);
				player->setStat('h', min((player->getStat('h') + d), 100));
				cout << "You rest! You heal " << d << " health points.";
			}
		} else {
			cout << "Invalid choice. You recoil from pain.";
		}
		
		cout << endl;
		
		//Check enemy health
		if (!isDead1 && enemy1->getStat('h') <= 0) {
			cout << "\nEnemy 1 died!" << endl;
			isDead1 = true;
		}
		if (!isDead2 && enemy2->getStat('h') <= 0) {
			cout << "\nEnemy 2 died!" << endl;
			isDead2 = true;
		}
		if (isDead1 && isDead2) {
			gameEnd = true;
		}
		
		//Enemy 1 attack phase
		if (!isDead1) {
			cout << "\nEnemy 1's Turn" << endl;
			act = rand() % 5 + 1;
			if (act != 5 && act % 2 == 1 && enemy1->getStat('s') > 0) {
				d = int((enemy1->getStat('t') + armPower) * ((rand() % 25) + 75) / 100);
				enemy1->setStat('s', max((enemy1->getStat('s') - swordPower), 0));
				player->setStat('h', max((player->getStat('h') - d), 0));
				cout << "Thunder Crow scratches you! You lose " << d << " health points.";
			} else if (act % 2 == 0 && enemy1->getStat('m') > 0) {
				d = int((enemy1->getStat('i') + spellPower) * ((rand() % 25) + 75) / 100);
				enemy1->setStat('m', max((enemy1->getStat('m') - spellPower * 2), 0));
				player->setStat('h', max((player->getStat('h') - d), 0));
				cout << "Thunder Crow zaps you! You lose " << d << " health points.";
			} else {
				cout << "Thunder Crow cowers in fear.";
			}
			cout << endl;
		}
		
		//Enemy 2 attack phase
		if (!isDead2) {
			cout << "\nEnemy 2's Turn" << endl;
			act = rand() % 5 + 1;
			if (act != 5 && act % 2 == 1 && enemy2->getStat('s') > 0) {
				d = int((enemy2->getStat('t') + armPower * 2) * ((rand() % 25) + 75) / 100);
				enemy2->setStat('s', max((enemy2->getStat('s') - swordPower), 0));
				player->setStat('h', max((player->getStat('h') - d), 0));
				cout << "Blood Wraith bites you! You lose " << d << " health points.";
			} else if (act % 2 == 0 && enemy2->getStat('m') > 0) {
				d = int((enemy2->getStat('i') + spellPower) * ((rand() % 25) + 75) / 100);
				enemy2->setStat('m', max((enemy2->getStat('m') - spellPower), 0));
				player->setStat('h', max((player->getStat('h') - d), 0));
				cout << "Blood Wraith phases through your body! You lose " << d << " health points.";
			} else {
				cout << "Blood Wraith stands motionless.";
			}
			cout << "\n" << endl;
		}
		
		//End phase
		
		if (player->getStat('h') <= 0) {
			cout << "You died!" << endl;
			gameEnd = true;
		}
	}
	
	if (gameEnd) {
		if (isDead1 && isDead2) {
			cout << "\nYou win!\n" << endl;
		} else {
			cout << "\nYou lose!\n" << endl;
		}
	}
	
	delete player;
	delete enemy1;
	delete enemy2;
	
}

int main() {
	driver0();
}
