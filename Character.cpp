
#include "Character.h"
#include <iostream>

#define ERROR "\033[31mERROR: \033[0m"

using namespace std;

string notFound = "stat not found";

Character::Character() {
	health = 0;
	stamina = 0;
	magic = 0;
	totalHealth = 0;
	totalStamina = 0;
	totalMagic = 0;
	con = 0;
	str = 0;
	intel = 0;
	name = "Character";
	dead = false;
}

Character::Character(int h, int s, int m, int c, int t, int i) {
	health = h;
	stamina = s;
	magic = m;
	totalHealth = h;
	totalStamina = s;
	totalMagic = m;
	con = c;
	str = t;
	intel = i;
	name = "Character";
	dead = false;
}

Character::Character(int h, int s, int m, int c, int t, int i, string n) {
	health = h;
	stamina = s;
	magic = m;
	totalHealth = h;
	totalStamina = s;
	totalMagic = m;
	con = c;
	str = t;
	intel = i;
	name = n;
	dead = false;
}

int Character::getStat(char stat) {
	switch(stat) {
		case 'h':
			return health;
		case 's':
			return stamina;
		case 'm':
			return magic;
		case 'c':
			return con;
		case 't':
			return str;
		case 'i':
			return intel;
		default:
			cerr << ERROR << notFound << endl;
			return 0;
	}
}

void Character::setStat(char stat, int val) {
	switch(stat) {
		case 'h':
			health = val;
			break;
		case 's':
			stamina = val;
			break;
		case 'm':
			magic = val;
			break;
		case 'c':
			con = val;
			break;
		case 't':
			str = val;
			break;
		case 'i':
			intel = val;
			break;
		default:
			cerr << ERROR << notFound << endl;
			break;
	}
}

void Character::printStat(char stat) {
	switch(stat) {
		case 'h':
			cout << health;
			break;
		case 's':
			cout << stamina;
			break;
		case 'm':
			cout << magic;
			break;
		case 'c':
			cout << con;
			break;
		case 't':
			cout << str;
			break;
		case 'i':
			cout << intel;
			break;
		default:
			cerr << ERROR << notFound << endl;
			break;
	}
}

void Character::printAllStats() {
	cout << "-------------------" << name << "--------------------" <<
					"\nHealth: " << health << "/" << totalHealth <<
					"\tStamina: " << stamina << "/" << totalStamina <<
					"\tMagic: " << magic << "/" << totalMagic << endl;
}

string Character::getName() {
	return name;
}

void Character::setName(string n) {
	name = n;
}

int Character::isDead() {
	return dead;
}

void Character::setDead(bool d) {
	dead = d;
}

