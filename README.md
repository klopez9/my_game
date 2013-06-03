my_game
-------

### Labyrinth ###

This is a simple text-based RPG adventure game.

##### v0.2 #####

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

##### v0.1 #####

*	**Comments**
	
	This is a bare-bones version of the battle phase of the game. In future versions, the player will be exploring different rooms, and there will be a chance for an enemy encounter every time the player enters a new room. This serves as a preview to the format of the battle phase for the main game.
		
*	**Features**
	
	Player fights two nameless Enemies
	
	All `Character`s have three actions: melee attack, magic attack, or rest
	
	Attacks consume `stamina` or `magic` depending on type
	
	`Character`s take turns making actions until either both Enemies die (win) or Player dies (lose)
	
	Random number generation factors into damage calculations--seed value is constant for testing purposes
	
