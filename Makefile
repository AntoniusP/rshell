FLAGS=-Wall -Werror -ansi -pedantic

all: rshell
	g++ $(FLAGS) ./src/main.cpp ./src/Or.cpp ./src/Semicolon.cpp \
	./src/And.cpp  ./src/Test.cpp ./src/Command.cpp -o ./bin/rshell

rshell:
	mkdir -p ./bin
	
clean:
	rm bin/rshell