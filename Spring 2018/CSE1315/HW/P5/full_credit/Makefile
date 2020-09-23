# Makefile for Library Management System
CXXFLAGS += --std=c++14

all: main
rebuild: clean main

debug: CXXFLAGS += -g
debug: rebuild

main: main.o library.o publication.o 
	$(CXX) $(CXXFLAGS) -o lms main.o library.o publication.o 
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp
test_library: test_library.o library.o publication.o
	$(CXX) $(CXXFLAGS) -o test_library test_library.o library.o publication.o
test_library.o: test_library.cpp *.h
	$(CXX) $(CXXFLAGS) -c test_library.cpp
library.o: library.cpp *.h
	$(CXX) $(CXXFLAGS) -c library.cpp
test_publication: test_publication.o publication.o 
	$(CXX) $(CXXFLAGS) -o test_publication test_publication.o publication.o 
test_publication.o: test_publication.cpp *.h
	$(CXX) $(CXXFLAGS) -c -w test_publication.cpp
publication.o: publication.cpp *.h
	$(CXX) $(CXXFLAGS) -c publication.cpp
clean:
	-rm -f *.o lms test_publication test_library
