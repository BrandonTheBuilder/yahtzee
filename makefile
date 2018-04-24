# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g -std=c++11
LDFLAGS =  /usr/lib/libgtest_main.a -lgtest -lpthread
# /usr/lib/libgtest.a /usr/lib/libgtest_main.a -lpthread

# ****************************************************
# Targets needed to bring the executable up to date

main: main.cpp game/yahtzee.h game/die.h
	$(CXX) $(CXXFLAGS) -o main main.cpp game/yahtzee.cpp game/scoring.cpp game/die.cpp

test: test_scoring.o
	$(CXX) $(CXXFLAGS) -o Test test_scoring.o $(LDFLAGS)

test_scoring.o: scoring.o
	$(CXX) $(CXXFLAGS) -c test_scoring.cpp

scoring.o: game/scoring.cpp
	$(CXX) $(CXXFLAGS) -c game/scoring.cpp

clean:
	rm -rf *o Test main 