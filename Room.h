
#ifndef ROOM_H__
#define ROOM_H__

#include <string>

using namespace std;

class Room {
	
		int id;
		int doors;
		
		string description;
		string doorQuery;
		
	public:
		Room();
		Room(int i, int d);
		
		int getID();
		int getDoors();
		string getDescription();
		string getDoorQuery();
		
		void setID(int i);
		void setDoors(int d);
		
};

#endif
