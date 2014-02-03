
#ifndef ENEMY_H__
#define ENEMY_H__

#include "Character.h"

class Enemy: public Character {
	
		int id;
		
	public:
		Enemy();
		Enemy(int h, int s, int m, int c, int t, int i);
		Enemy(int h, int s, int m, int c, int t, int i, string n);
		Enemy(int id);

};

#endif
