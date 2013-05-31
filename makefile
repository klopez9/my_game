
# specify compiler and flags
GXX=g++

# specify target
all: game.exe

# specify the object files that the target depends on
# also specify the object files needed to create the executable
game.exe: Character.o Driver.o
	$(GXX) Character.o Driver.o -o game.exe

# specify how the object files should be created from source files

Character.o: Character.cpp Character.h
	$(GXX)  -c  Character.cpp

Driver.o: Driver.cpp
	$(GXX)  -c  Driver.cpp


# specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o *~ core game.exe
