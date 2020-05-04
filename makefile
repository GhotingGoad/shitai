# Makefile

EXECPATH=./bin
HEADPATH =./include
OBJPATH=./obj
COMMANDLINEOPTIONS=-I/usr/include/SDL2 -L/usr/lib -lSDL2main -lSDL2 -lSDL2_image

shitai : main.o collision.o cTexture.o cTimer.o game.o tetromino.o
	g++ $(OBJPATH)/main.o $(OBJPATH)/collision.o $(OBJPATH)/cTexture.o $(OBJPATH)/cTimer.o $(OBJPATH)/game.o $(OBJPATH)/tetromino.o -o $(EXECPATH)/shitai $(COMMANDLINEOPTIONS)

main.o : main.cpp $(HEADPATH)/global.h
	g++ -c main.cpp -o $(OBJPATH)/main.o $(COMMANDLINEOPTIONS)

collision.o : collision.cpp $(HEADPATH)/global.h
	g++ -c collision.cpp -o $(OBJPATH)/collision.o $(COMMANDLINEOPTIONS)

cTexture.o : cTexture.cpp $(HEADPATH)/global.h
	g++ -c cTexture.cpp -o $(OBJPATH)/cTexture.o $(COMMANDLINEOPTIONS)

cTimer.o : cTimer.cpp $(HEADPATH)/global.h
	g++ -c cTimer.cpp -o $(OBJPATH)/cTimer.o $(COMMANDLINEOPTIONS)

game.o : game.cpp $(HEADPATH)/global.h
	g++ -c game.cpp -o $(OBJPATH)/game.o $(COMMANDLINEOPTIONS)

tetromino.o : tetromino.cpp $(HEADPATH)/global.h
	g++ -c tetromino.cpp -o $(OBJPATH)/tetromino.o $(COMMANDLINEOPTIONS)
