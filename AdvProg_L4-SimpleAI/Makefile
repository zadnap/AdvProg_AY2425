all:
	g++ -std=c++17 -c main_simpleai.cpp
	g++ -std=c++17 -c util.cpp
	g++ -std=c++17 -c simpleai.cpp
	g++ -std=c++17 util.o main_simpleai.o simpleai.o -o main_simpleai
run:
	./main_simpleai
test:
	chmod +x mainTest
	./mainTest
clean:
	rm -rf *.o main mainTest main_simpleai
