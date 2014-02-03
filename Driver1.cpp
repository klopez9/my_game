
#include "GameUtils.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void driver0() {

	/* Game Structure
	 * Main Menu
	 * * Game
	 * * * Room
	 * * * * Explore Decision Tree
	 * * * * * Battle Mode
	 * * * * * Discover Treasure
	 * * * * * Empty
	 * * * * New Room
	 * * Instructions
	
	*/
	
	GameUtils g;
	string in;
	bool endProgram = false;
	int menu;
	
	/*TODO set all output strings as global constants in c++ header (.hpp) file
	contained in a namespace, and include .hpp file in driver, utils, etc.
	OR put all string in a .txt file and read from the file
	*/

	cout << "\nYou walk into a dimly lit room. The\n" <<
					"walls are stone, and the air is cold.\n" <<
					"With a shudder, you grab a torch and\n" <<
					"walk to the end of the room, where a\n" <<
					"large wooden door awaits. You pause in\n" <<
					"front of the door--next to it is a stone\n" <<
					"slab with some sort of inscription.\n" << endl;
	
	while (!endProgram) {
		cout << "(1) Start\n(2) Instructions\n(3) Quit\n";
		getline(cin, in);
		stringstream(in) >> menu;
		switch(menu) {
			case 1:
				g.game();
				endProgram = true;
				break;
			case 2:
				cout << "\nYou brush off dust as you read the\n" <<
								"inscription on the slab:\n\n" <<
								"\t----------------------------------------\n" <<
								"\tWelcome to the Labyrinth.\n\n" <<
								"\tInside lies a treasure beyond your\n" <<
								"\twildest dreams, and horrors beyond your\n" <<
								"\tdeepest nightmares. To find this\n" <<
								"\ttreasure, you must roam through a series\n" <<
								"\tof rooms. But be warned: the doors are\n" <<
								"\tpossessed by wicked spirits, and may\n" <<
								"\tchange where they lead. A map is useless\n" <<
								"\there. Some rooms contain monsters,\n" <<
								"\tothers, small treasures, and others\n" <<
								"\tnothing at all. A person could go insane\n" <<
								"\there, spending his life searching for\n" <<
								"\tthe treasure--or for the exit. But with\n" <<
								"\ta little luck, you might find both.\n" << 
								"\t----------------------------------------\n" << endl;
				break;
			case 3:
				cout << "\nYou wonder what might have happened if\n" <<
								"you went through that door. Instead, you\n" <<
								"run straight out the way you came." << endl;
				cout << "Press Enter to quit." << endl;
				cin.ignore();
				endProgram = true;
				break;
			default:
				cout << "\nYou mumble to yourself. Nothing happens.\n" << endl;
				// should never be accessed
		}
	}

}

int main() {
	driver0();
}
