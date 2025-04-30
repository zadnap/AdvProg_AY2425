all:
	g++ -std=c++17 -c main_game.cpp
	g++ -std=c++17 -c main.cpp
	g++ -std=c++17 -c util.cpp
	g++ -std=c++17 -c hangman_guesser.cpp
	g++ -std=c++17 -c assessment.cpp

	g++ -std=c++17 util.o main_game.o hangman_guesser.o assessment.o -o main_game
	g++ -std=c++17 util.o main.o hangman_guesser.o assessment.o -o main
run:
	./main

run_assessment:
	./main

test:
	chmod +x mainTest
	./mainTest
clean:
	rm -rf *.o main mainTest main_game
