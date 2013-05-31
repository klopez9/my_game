
#include "Character.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

void driver() {

	Character* player = new Character(100, 100, 100, 5, 5, 5);
	Character* enemy1 = new Character(50, 50, 50, 1, 1, 1);
	Character* enemy2 = new Character(50, 50, 50, 1, 3, 3);
	
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
	
	while (!gameEnd) {
	
		//Player attack phase
		cout << "Your turn" << endl;
		cout << "Use 's'lash, cast 'f'ire, or 'r'est?: ";
		cin >> attack;
		if (attack == 's' || attack == 'S') {
			cout << attack << endl;
			cout << "Which enemy, 1 or 2?: ";
			cin >> en;
			if (en == 1 && !isDead1 && player->getStat('s') > 0) {
				cout << en << endl;
				d = int((player->getStat('t') + swordPower) * ((rand() % 15) + 75) / 100);
				player->setStat('s', max((player->getStat('s') - swordPower), 0));
				enemy1->setStat('h', max((enemy1->getStat('h') - d), 0));
				cout << "You slash enemy 1! " << d << " damage." << endl;
			} else if (en == 2 && !isDead2 && player->getStat('s') > 0) {
				cout << en << endl;
				d = int((player->getStat('t') + swordPower) * ((rand() % 15) + 75) / 100);
				player->setStat('s', max((player->getStat('s') - swordPower), 0));
				enemy2->setStat('h', max((enemy2->getStat('h') - d), 0));
				cout << "You slash enemy 2! " << d << " damage." << endl;
			} else {
				cout << en << endl;
				cout << "Invalid choice. Your slash misses." << endl;
			}
		} else if (attack == 'f' || attack == 'F') {
			cout << attack << endl;
			d = int((player->getStat('i') + spellPower) * ((rand() % 15) + 75) / 100);
			player->setStat('m', max((player->getStat('m') - spellPower * 2), 0));
			enemy1->setStat('h', max((enemy1->getStat('h') - d), 0));
			enemy2->setStat('h', max((enemy2->getStat('h') - d), 0));
			cout << "You cast fire! " << d << " damage to both enemies." << endl;
		} else if (attack == 'r' || attack == 'R') {
			cout << attack << endl;
			d = int((player->getStat('c')) * ((rand() % 15) + 75) / 100);
			player->setStat('h', min((player->getStat('h') + d), 100));
			cout << "You rest! You heal " << d << " health points." << endl;
		} else {
			cout << attack << endl;
			cout << "Invalid choice. You recoil from pain." << endl;
		}
		
		//Check enemy status
		if (!isDead1 && enemy1->getStat('h') <= 0) {
			cout << "Enemy 1 died!" << endl;
			isDead1 = true;
		}
		if (!isDead2 && enemy2->getStat('h') <= 0) {
			cout << "Enemy 2 died!" << endl;
			isDead2 = true;
		}
		if (isDead1 && isDead2) {
			gameEnd = true;
		}
		
		//Enemy 1 attack phase
		if (!isDead1) {
			cout << "Enemy 1's Turn" << endl;
			act = rand() % 5 + 1;
			if (act != 5 && act % 2 == 1 && enemy1->getStat('s') > 0) {
				cout << act << endl;
				d = int((enemy1->getStat('t') + armPower) * ((rand() % 15) + 75) / 100);
				player->setStat('h', max((player->getStat('h') - d), 0));
				cout << "Enemy 1 scratches you! You lose " << d << " health points." << endl;
			} else if (act % 2 == 0 && enemy1->getStat('m') > 0) {
				cout << act << endl;
				d = int((enemy1->getStat('i') + spellPower) * ((rand() % 15) + 75) / 100);
				player->setStat('h', max((player->getStat('h') - d), 0));
				cout << "Enemy 1 zaps you! You lose " << d << " health points." << endl;
			} else {
				cout << act << endl;
				cout << "Enemy 1 cowers in fear." << endl;
			}
		}
		
		//Enemy 2 attack phase
		if (!isDead2) {
			cout << "Enemy 2's Turn" << endl;
			act = rand() % 5 + 1;
			if (act != 5 && act % 2 == 1 && enemy2->getStat('s') > 0) {
				cout << act << endl;
				d = int((enemy2->getStat('t') + armPower * 2) * ((rand() % 15) + 75) / 100);
				player->setStat('h', max((player->getStat('h') - d), 0));
				cout << "Enemy 2 bites you! You lose " << d << " health points." << endl;
			} else if (act % 2 == 0 && enemy2->getStat('m') > 0) {
				cout << act << endl;
				d = int((enemy2->getStat('i') + spellPower) * ((rand() % 15) + 75) / 100);
				player->setStat('h', max((player->getStat('h') - d), 0));
				cout << "Enemy 2 phases through your body! You lose " << d << " health points." << endl;
			} else {
				cout << act << endl;
				cout << "Enemy 2 stands motionless." << endl;
			}
		}
		
		//Stat phase
		if (!gameEnd) {
			cout << "Player:\nHealth: " << player->getStat('h') <<
							"\tMagic: " << player->getStat('m') <<
							"\tStamina: " << player->getStat('s') << "\n" << 
							"Enemy 1:\nHealth: " << enemy1->getStat('h') << 
							"\tMagic: " << enemy1->getStat('m') << 
							"\tStamina: " << enemy1->getStat('s') << "\n" <<
							"Enemy 2:\nHealth: " << enemy2->getStat('h') << 
							"\tMagic: " << enemy2->getStat('m') << 
							"\tStamina: " << enemy2->getStat('s') << endl;
		}
		if (player->getStat('h') <= 0) {
			cout << "You died!" << endl;
			gameEnd = true;
		}
	}
	
	if (gameEnd) {
		if (isDead1 && isDead2) {
			cout << "You win!" << endl;
		} else {
			cout << "You lose!" << endl;
		}
	}
	
}

int main() {
	driver();
}
