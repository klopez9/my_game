
#include "Room.h"

using namespace std;

int TOTAL_ROOMS = 5;

Room::Room() {
	id = 0;
	doors = 0;
	description = "";
	doorQuery = "";
}
	
Room::Room(int i, int d) {
	id = i;
	doors = d;
	
	switch(id) {
		case 1:
			description = "There appears to be fountain of water at the center of the room. You look at the water cautiously, but it doesn't seem to be poisoned. You take a drink.";
			break;
		case 2:
			description = "Vines and creepers lines the walls of this room. You see a door on the ceiling of the room. It seems you'll have to climb the growths on the wall in order to reach the exit.";
			break;
		case 3:
			description = "This room has no floor. You almost trip into the gaping abyss as you walk into the room, but you catch yourself. You notice a group of stone slabs jutting out from along the walls of the room. You'll need to jump from one to another in order to reach the exit.";
			break;
		case 4:
			description = "On the far side of the room you see the ruins of some sort of monument. White stone pillars lean on white stone bricks, and the whole mass is wrapped in vines and rubble. Once, it might have been a shrine, but to what and for what purpose you can't say.";
			break;
		case 5:
			description = "You've stumbled into a long, dark, winding tunnel. You walk for a while until you hear a bone-chilling howl. You start to jog briskly. Another howl, and you break into a run.";
			break;
		default:
			description = "This room is empty.";
	}
	
	switch(doors) {
		case 1:
			doorQuery = "There is only one way out. You have no choice but to press on.";
			break;
		case 2:
			doorQuery = "Left door or right door?\n(1) Left\n(2) Right\n";
			break;
		case 3:
			doorQuery = "Left door, right door, or forward door?\n(1) Left\n(2) Right\n(3) Forward\n";
			break;
		default:
			doorQuery = "You look all around, but you can't find any doors, not even the one you came in through. You're trapped.";
	}
}
			
int Room::getID() {
	return id;
}

int Room::getDoors() {
	return doors;
}

string Room::getDescription() {
	return description;
}

string Room::getDoorQuery() {
	return doorQuery;
}

void Room::setID(int i) {
	id = i;
	
	switch(id) {
		case 1:
			description = "There appears to be fountain of water at the center of the room. You look at the water cautiously, but it doesn't seem to be poisoned. You take a drink.";
			break;
		case 2:
			description = "Vines and creepers lines the walls of this room. You see a door on the ceiling of the room. It seems you'll have to climb the growths on the wall in order to reach the exit.";
			break;
		case 3:
			description = "This room has no floor. You almost trip into the gaping abyss as you walk into the room, but you catch yourself. You notice a group of stone slabs jutting out from along the walls of the room. You'll need to jump from one to another in order to reach the exit.";
			break;
		case 4:
			description = "On the far side of the room you see the ruins of some sort of monument. White stone pillars lean on white stone bricks, and the whole mass is wrapped in vines and rubble. Once, it might have been a shrine, but to what and for what purpose you can't say.";
			break;
		case 5:
			description = "You've stumbled into a long, dark, winding tunnel. You walk for a while until you hear a bone-chilling howl. You start to jog briskly. Another howl, and you break into a run.";
			break;
		default:
			description = "This room is empty.";
	}
}

void Room::setDoors(int d) {
	doors = d;
	
	switch(doors) {
		case 1:
			doorQuery = "There is only one way out. You have no choice but to press on.";
			break;
		case 2:
			doorQuery = "Left door or right door?\n(1) Left\n(2) Right\n";
			break;
		case 3:
			doorQuery = "Left door, right door, or forward door?\n(1) Left\n(2) Right\n(3) Forward\n";
			break;
		default:
			doorQuery = "You look all around, but you can't find any doors, not even the one you came in through. You're trapped.";
	}
}

