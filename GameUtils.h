
#ifndef GAMEUTILS_H__
#define GAMEUTILS_H__

class GameUtils {
		
	public:
		
		//Setup
		void game();
		void configPlayer();
		
		//Encounters
		bool battle(int numEnemies);
		void treasure();
		void empty();

};

#endif
