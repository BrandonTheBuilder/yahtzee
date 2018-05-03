# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g -std=c++11
LDFLAGS =  /usr/lib/libgtest_main.a -lgtest -lpthread
# /usr/lib/libgtest.a /usr/lib/libgtest_main.a -lpthread

# ****************************************************
# Targets needed to bring the executable up to date
main_obj = main.o yahtzee.o scoring.o die.o 
test_obj = test_yahtzee.o test_scoring.o
test_files = test/test_scoring.cpp

default: yahtzee test_yahtzee
	./test_yahtzee
		
yahtzee: $(main_obj)
	$(CXX) $(CXXFLAGS) -o yahtzee $(main_obj)

test_yahtzee: test_yahtzee.o
	$(CXX) $(CXXFLAGS) -o test_yahtzee $(test_files) $(LDFLAGS)

test_yahtzee.o: scoring.o 
	$(CXX) $(CXXFLAGS) -c $(test_files)

main.o: yahtzee.o scoring.o die.o
	$(CXX) $(CXXFLAGS) -c main.cpp

yahtzee.o: game/yahtzee.h die.o scoring.o
	$(CXX) $(CXXFLAGS) -c game/yahtzee.cpp

scoring.o: game/scoring.h
	$(CXX) $(CXXFLAGS) -c game/scoring.cpp

die.o: game/die.h
	$(CXX) $(CXXFLAGS) -c game/die.cpp

clean:
	rm -rf *o yahtzee test_yahtzee 