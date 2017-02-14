FLAGS=-Wall -Werror -ansi -pedantic

all: rshell cmdComponent Connector Command ArgList
	
rshell:
	mkdir bin
	g++ $(FLAGS) src/main.cpp -o bin/main
	
cmdComponent:
	mkdir bin
	g++ %(FLAGS) src/cmdComponent.cpp -o bin/cmdComponent

Connector:
	mkdir bin
	g++ $(FLAGS) src/Connector.cpp -o bin/Connector

Command:
	mkdir bin
	g++ $(FLAGS) src/Command.cpp -o bin/Command

ArgList:
	mkdir bin
	g++ $(FLAGS) src/Arglist.cpp -o bin/Arglist
	