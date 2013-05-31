
#include "Character.h"
#include <iostream>

#define errNotFound "\033[31mERROR: STAT NOT FOUND\033[0m";

using namespace std;

Character::Character() {
	health = 0;
	stamina = 0;
	magic = 0;
	con = 0;
	str = 0;
	intel = 0;
}

Character::Character(int h, int s, int m, int c, int t, int i) {
	health = h;
	stamina = s;
	magic = m;
	con = c;
	str = t;
	intel = i;
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
			//cout << errNotFound << endl;
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
			//cout << errNotFound << endl;
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
			//cout << errNotFound << endl;
			break;
	}
}

