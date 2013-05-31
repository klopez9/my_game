
#ifndef BLAH_H__
#define BLAH_H__

#include <string>

using namespace std;

class Character {

	private:
		int health, stamina, magic;
		
		int con, str, intel;
	
	public:
		Character();
		Character(int h, int s, int m, int c, int t, int i);
		
		int getStat(char stat);
		void setStat(char stat, int val);
		void printStat(char stat);

};

#endif
