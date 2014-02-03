
# specify compiler and flags
GXX=g++ -g

# specify target
all: game.exe

# specify the object files that the target depends on
# also specify the object files needed to create the executable
game.exe: Character.o Enemy.o Player.o Room.o GameUtils.o Driver1.o
	$(GXX) Character.o Enemy.o Player.o Room.o GameUtils.o Driver1.o -o game.exe

# specify how the object files should be created from source files

Character.o: Character.cpp Character.h
	$(GXX)  -c  Character.cpp
	
Enemy.o: Enemy.cpp Enemy.h
	$(GXX)	-c	Enemy.cpp
	
Player.o: Player.cpp Player.h
	$(GXX)	-c	Player.cpp

Room.o: Room.cpp Room.h
	$(GXX)	-c	Room.cpp

GameUtils.o: GameUtils.cpp GameUtils.h
	$(GXX)	-c	GameUtils.cpp

Driver.o: Driver1.cpp
	$(GXX)  -c  Driver1.cpp


# specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	$(RM) -f *.o *~ core game.exe a.out
