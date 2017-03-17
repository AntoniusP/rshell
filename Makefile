FLAGS=-Wall -Werror -ansi -pedantic

all: rshell
	g++ $(FLAGS) ./src/main.cpp ./src/Connector.cpp ./src/Or.cpp \
	./src/Semicolon.cpp ./src/And.cpp  ./src/Test.cpp ./src/Command.cpp \
	./src/Pipe.cpp ./src/OutputR.cpp ./src/OutputR2.cpp ./src/InputR.cpp \
	-o ./bin/rshell

rshell:
	mkdir -p ./bin
	
clean:
	rm -r bin