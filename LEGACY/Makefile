# Makefile

# Compile Linux = "make ", compile Windows = "make OS=windows ", both only on x86_64 architecture.

# To-do
# 1. include conditional statements to detect OS for cross-platform compile operation
# 2. add some form of version control using parsing of values through "menu(int argc, char *argv[])"
# ^ https://stackoverflow.com/questions/3024197/what-does-int-argc-char-argv-mean

ifeq ($(OS), windows)
	CXX = x86_64-w64-mingw32-g++
	LFLAGS = -lmingw32
# -mwindows = no terminal
	CXXFLAGS = -mwindows
# replace accordingly if you have development library directory elsewhere
	INCDIR = /usr/x86_64-w64-mingw32/include/SDL2
	LIBDIR = /usr/x86_64-w64-mingw32/lib
else
# -pie = terminal, -no-pie = no terminal
	CXXFLAGS = -no-pie
	INCDIR = /usr/include/SDL2
	LIBDIR = /usr/lib
endif

# ./obj = RELATIVE PATH/obj folder
OBJS=./obj/main.o ./obj/collision.o ./obj/cTexture.o ./obj/cTimer.o ./obj/game.o ./obj/tetromino.o

shitai : main.o collision.o cTexture.o cTimer.o game.o tetromino.o
# -static-libgcc -static-libstdc++ are required static libraries for cross compilation from Linux to Windows.
	$(CXX) $(OBJS) -o ./bin/shitai -I$(INCDIR) -L$(LIBDIR) $(LFLAGS) -lSDL2main -lSDL2 -lSDL2_image -static-libgcc -static-libstdc++ $(CXXFLAGS)

main.o : main.cpp global.h
	$(CXX) -c main.cpp -o ./obj/main.o -I$(INCDIR) -L$(LIBDIR)

# %.o = all .o files, %.cpp = all .cpp files
%.o : ./src/%.cpp global.h

# $< = ./src/%.cpp (first in list of required files)
# $@ = %.o (target file)
# $^ = ./src/%.cpp global.h (all required files)
	$(CXX) -c $< -o ./obj/$@ -I$(INCDIR)