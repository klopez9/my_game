my_game
-------

### Labyrinth ###

This is a simple text-based RPG adventure game.

#### v0.3 ####

* **New Features**

	Altered game structure and flow. There is a start menu with instructions, and the player can now progress through multiple rooms. The game is over when the player loses all their health.
	
	Each room has multiple qualities: a description, a type, and a certain number of doors. The description has no effect on gameplay; it's merely interesting text that can add to the story. The type determines the main gameplay of the room. Battle Rooms feature monsters which must be slain to proceed. Treasure Rooms contain a collection of coins or other valuables. (Later, treasure rooms will be used to increase stats.) Empty Rooms have nothing.

	Added new enemy types, each with unique stats: Zombie, Large Rat, Dark Mage.
	
	The player's battle moves have slightly changed. During battle, the player can 'Attack' a single monster, use 'Magic' to attack all monsters, or 'Defend' to regain health and lower damage from enemy attacks.
	
* **Logic Changes**

	`Driver0` handles the top scope of the game (start menu) while `GameUtils` handles the game segment
	
	Start menu features new intro and instruction dialogues

	Added `Player` and `Enemy` classes, which will become extensions of the `Character` class
	
	`Character`, `Player` and `Enemy` classes all have currently unused `con`, `str` and `intel` variables which may be used to modify other stats in future versions
	
	`GameUtils` has an unused method `configPlayer` which will be used to customize stats and level up the player character in future versions

#### v0.2 ####

* **Changes**

	Added data members `bool dead` and `string name` to Character class for future use
	
	Added accessors/mutators for new data members, as well as new method `printAllStats()` which prints the `health`, `stamina`, and `magic` variables of a given `Character` object
	
	Added error message for `getStat()` method of `Character` class (displayed if incoming `char stat` is invalid)
	
	Changed access specifier of `Character` data members to `protected` for use by future subclasses
	
	Renamed driver file--driver files will follow the format DriverN.cpp, where N is the version number
	
	Both Enemies will now have randomly-generated `health`, `stamina` and `magic` data members (seed value remains constant for testing purposes), and `name`s are set to "Enemy 1" and "Enemy 2"
	
	Unofficial Enemy names are "Thunder Crow" and "Blood Wraith"
	
	`Character` stats are now listed before the main battle phase, rather than after
	
	Increased range of random number offset in damage calculations
	
	Added prompt for when Player attempts to heal past max `health`
	
	Fixed bug: Enemy attacks did not reduce their `stamina` or `magic`
		
	Fixed bug: memory leaks--`Character` objects were not being deleted before program termination

#### v0.1 ####

*	**Comments**
	
	This is a bare-bones version of the battle phase of the game. In future versions, the player will be exploring different rooms, and there will be a chance for an enemy encounter every time the player enters a new room. This serves as a preview to the format of the battle phase for the main game.
		
*	**Features**
	
	Player fights two nameless Enemies
	
	All `Character`s have three actions: melee attack, magic attack, or rest
	
	Attacks consume `stamina` or `magic` depending on type
	
	`Character`s take turns making actions until either both Enemies die (win) or Player dies (lose)
	
	Random number generation factors into damage calculations--seed value is constant for testing purposes
	
