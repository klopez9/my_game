
#ifndef CHARACTER_H__
#define CHARACTER_H__

#include <string>

using namespace std;

class Character {

	protected:
		int health, stamina, magic;
		int totalHealth, totalStamina, totalMagic;
		int con, str, intel;
		string name;
		bool dead;
	
	public:
		Character();
		Character(int h, int s, int m, int c, int t, int i);
		Character(int h, int s, int m, int c, int t, int i, string n);
		
		int getStat(char stat);
		void setStat(char stat, int val);
		void printStat(char stat);
		void printAllStats();
		
		string getName();
		void setName(string n);
		int isDead();
		void setDead(bool d);

};

#endif
