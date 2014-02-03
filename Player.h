
#ifndef PLAYER_H__
#define PLAYER_H__

#include "Character.h"

class Player: public Character {

	public:
		Player();
		Player(Character c);
		Player(Character c, string name);
		Player(int h, int s, int m, int c, int t, int i);
		Player(int h, int s, int m, int c, int t, int i, string n);
		
};

#endif
