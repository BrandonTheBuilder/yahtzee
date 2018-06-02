# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g -std=c++11
LDFLAGS =  /usr/lib/libgtest_main.so -lgtest -lpthread

# ****************************************************
# Targets needed to bring the executable up to date
main_obj = main.o yahtzee.o scoring.o
req_obj = yahtzee.o scoring.o
test_files = test/test_scoring.cpp test/test_yahtzee.cpp

default: yahtzee test
	./test_yahtzee

yahtzee: $(main_obj)
	$(CXX) $(CXXFLAGS) -o yahtzee $(main_obj)

test: $(req_obj) 
	$(CXX) $(CXXFLAGS) -o test_yahtzee $(test_files) $(req_obj) $(LDFLAGS)

main.o: $(req_obj) 
	$(CXX) $(CXXFLAGS) -c main.cpp

yahtzee.o: game/yahtzee.h scoring.o
	$(CXX) $(CXXFLAGS) -c game/yahtzee.cpp game/die.h

scoring.o: game/scoring.h
	$(CXX) $(CXXFLAGS) -c game/scoring.cpp

die.o: game/die.h
	$(CXX) $(CXXFLAGS) -c game/die.h

clean:
	rm -rf *o yahtzee test_yahtzee
