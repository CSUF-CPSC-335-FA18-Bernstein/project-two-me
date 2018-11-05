
all: experiment test project2.o

test: project2_test
	./project2_test

project2.o: project2.hh project2.cc
	g++ -c -std=c++11 project2.cc -o project2.o

project2_test: project2.hh project2_test.cc project2.o
	g++ -std=c++11 project2_test.cc project2.o -o project2_test

experiment: project2.hh timer.hh experiment.cc project2.o
	g++ -std=c++11 experiment.cc  project2.o -o experiment

clean:
	rm -f project2.o project2_test experiment

