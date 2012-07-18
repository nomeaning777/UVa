all: main

main: main.cpp
	g++ -o main main.cpp -O2 -Wall

test: main
	./main < sample.in > sample.myans
	diff -b -q sample.myans sample.out

