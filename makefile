run: main.o player.o monsters.o map.o  commands.o
	g++ player.o monsters.o map.o  Commands.o main.o -o main.exe

main.o: main.cpp commands.o
	g++ -c main.cpp

commands.o: commands.cpp Commands.h map.o
	g++ -c Commands.cpp

map.o : map.cpp map.h monsters.o player.o  
	g++ -c map.cpp

player.o: player.cpp player.h monsters.o  
	g++ -c player.cpp

monsters.o: monsters.cpp monsters.h
	g++ -c monsters.cpp

clean:
	rm *.o
	rm *.exe
