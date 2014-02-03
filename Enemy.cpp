
#include "Enemy.h"
#include <iostream>

//#define ERROR "\033[31mERROR: \033[0m"

using namespace std;

//string notFound = "stat not found";

Enemy::Enemy() {
	health = 0;
	stamina = 0;
	magic = 0;
	totalHealth = health;
	totalStamina = stamina;
	totalMagic = magic;
	con = 0;
	str = 0;
	intel = 0;
	name = "Enemy";
	dead = false;
	id = 0;
}

Enemy::Enemy(int h, int s, int m, int c, int t, int i) {
	health = h;
	stamina = s;
	magic = m;	
	totalHealth = health;
	totalStamina = stamina;
	totalMagic = magic;
	con = c;
	str = t;
	intel = i;
	name = "Enemy";
	dead = false;
	id = 0;
}

Enemy::Enemy(int h, int s, int m, int c, int t, int i, string n) {
	health = h;
	stamina = s;
	magic = m;	
	totalHealth = health;
	totalStamina = stamina;
	totalMagic = magic;
	con = c;
	str = t;
	intel = i;
	name = n;
	dead = false;
	id = 0;
}

Enemy::Enemy(int i) {
	id = i;
	dead = false;
	
	switch(id) {
		case 1:
			health = 30;
			stamina = 30;
			magic = 30;
			con = 1;
			str = 5;
			intel = 5;
			name = "Thunder Crow";
			break;
		case 2:
			health = 50;
			stamina = 50;
			magic = 10;
			con = 3;
			str = 1;
			intel = 1;
			name = "Zombie";
			break;
		case 3:
			health = 60;
			stamina = 40;
			magic = 40;
			con = 1;
			str = 3;
			intel = 3;
			name = "Blood Wraith";
			break;
		case 4:
			health = 25;
			stamina = 25;
			magic = 25;
			con = 1;
			str = 1;
			intel = 1;
			name = "Large Rat";
			break;
		case 5:
			health = 40;
			stamina = 20;
			magic = 100;
			con = 1;
			str = 2;
			intel = 4;
			name = "Dark Mage";
			break;
		default:
			health = 0;
			stamina = 0;
			magic = 0;
			con = 0;
			str = 0;
			intel = 0;
			name = "Enemy";
			break;
	}
	
	totalHealth = health;
	totalStamina = stamina;
	totalMagic = magic;
}
