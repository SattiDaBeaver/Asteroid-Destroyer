all: compile link

run: all exe

compile: 
	g++ -c main.cpp io.cpp game.cpp player.cpp -Isrc/include

link : 
	g++ main.o io.o game.o player.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

exe:
	./main

clean:
	del -f io.o player.o game.o main.exe *.o 
