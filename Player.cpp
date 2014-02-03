
#include "Player.h"
#include <iostream>

//#define ERROR "\033[31mERROR: \033[0m"

using namespace std;

//string notFound = "stat not found";

Player::Player() {
	health = 0;
	stamina = 0;
	magic = 0;
	totalHealth = health;
	totalStamina = stamina;
	totalMagic = magic;
	con = 0;
	str = 0;
	intel = 0;
	name = "Player";
	dead = false;
}

Player::Player(int h, int s, int m, int c, int t, int i) {
	health = h;
	stamina = s;
	magic = m;
	totalHealth = health;
	totalStamina = stamina;
	totalMagic = magic;
	con = c;
	str = t;
	intel = i;
	name = "Player";
	dead = false;
}

Player::Player(int h, int s, int m, int c, int t, int i, string n) {
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
}

