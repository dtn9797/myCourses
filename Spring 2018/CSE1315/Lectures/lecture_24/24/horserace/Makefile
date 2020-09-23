CXXFLAGS += -std=c++14 -pthread

all: main

debug: CXXFLAGS += -g
debug: main

rebuild: clean main

main: horserace.o horse.o 
	g++ -o horserace $(CXXFLAGS) horserace.o horse.o
horserace.o: horserace.cpp horse.h
	g++ $(CXXFLAGS) -c horserace.cpp
horse.o: horse.cpp horse.h
	g++ $(CXXFLAGS) -c horse.cpp
clean:
	-rm -f *.o *~ horserace 

