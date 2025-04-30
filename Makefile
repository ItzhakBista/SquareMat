# itzhak173@gmail.com

CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

all: main tests

main: main.o SquareMat.o
	$(CXX) $(CXXFLAGS) -o main main.o SquareMat.o

tests: SquareMat_test.o SquareMat.o
	$(CXX) $(CXXFLAGS) -o tests SquareMat_test.o SquareMat.o

main.o: main.cpp SquareMat.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

SquareMat_test.o: SquareMat_test.cpp SquareMat.hpp
	$(CXX) $(CXXFLAGS) -c SquareMat_test.cpp

SquareMat.o: SquareMat.cpp SquareMat.hpp
	$(CXX) $(CXXFLAGS) -c SquareMat.cpp

Main: main
	./main

test: tests
	./tests

valgrind: main
	valgrind --leak-check=full ./main

clean:
	rm -f *.o main tests
