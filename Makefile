 all:
	g++ src/main.cpp -o bin/test -std=c++17 
	clear
	./bin/test 0 0 7 8