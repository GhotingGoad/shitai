# Makefile

# To-do
# 1. include conditional statements to detect OS for cross-platform compile operation
# 2. add some form of version control using parsing of values through "menu(int argc, char *argv[])"
# ^ https://stackoverflow.com/questions/3024197/what-does-int-argc-char-argv-mean

# -pie = terminal, -no-pie = no terminal
CFLAGS = -no-pie
# ./obj = RELATIVE PATH/obj folder
OBJS=./obj/main.o ./obj/collision.o ./obj/cTexture.o ./obj/cTimer.o ./obj/game.o ./obj/tetromino.o
# replace accordingly if you have development library directory elsewhere
INCDIR = /usr/include/SDL2
LIBDIR = /usr/lib

shitai : main.o collision.o cTexture.o cTimer.o game.o tetromino.o
	g++ $(OBJS) -o ./bin/shitai -I$(INCDIR) -L$(LIBDIR) -lSDL2main -lSDL2 -lSDL2_image $(CFLAGS)

main.o : main.cpp global.h
	g++ -c main.cpp -o ./obj/main.o -I$(INCDIR) -L$(LIBDIR)

# %.o = all .o files, %.cpp = all .cpp files
%.o : ./src/%.cpp global.h

# $< = ./src/%.cpp (first in list of required files)
# $@ = %.o (target file)
# $^ = ./src/%.cpp global.h (all required files)
	g++ -c $< -o ./obj/$@ -I/usr/include/SDL2
