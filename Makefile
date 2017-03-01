FLAGS=-Wall -Werror -ansi -pedantic

all: rshell
	g++ $(FLAGS) ./src/main.cpp ./src/cmdComponent.cpp \
	./src/Test.cpp ./src/Command.cpp -o ./bin/rshell

rshell:
	mkdir -p ./bin
	
clean:
	rm bin/rshell
#	g++ $(FLAGS) ./src/main.cpp -o ./bin/main

#cmdComponent:
#	g++ $(FLAGS) ./src/cmdComponent.cpp -o ./bin/cmdComponent

#ArgList:
#	g++ $(FLAGS) ./src/Arglist.cpp -o ./bin/Arglist

#Command:
#	g++ $(FLAGS) ./src/Command.cpp -o ./bin/Command