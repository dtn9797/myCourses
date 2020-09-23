CXXFLAGS += -std=c++14 -pthread

all: main

debug: CXXFLAGS += -g
debug: main

rebuild: clean main

main: 3thread.cpp hw_concur.cpp no_mutex.cpp mutex.cpp phone.cpp test.cpp threadid3.cpp threadid.cpp
	g++ -o 3thread $(CXXFLAGS) 3thread.cpp
	g++ -o hw_concur $(CXXFLAGS) hw_concur.cpp
	g++ -o no_mutex $(CXXFLAGS) no_mutex.cpp
	g++ -o mutex $(CXXFLAGS) mutex.cpp
	g++ -o phone $(CXXFLAGS) phone.cpp
	g++ -o test $(CXXFLAGS) test.cpp
	g++ -o threadid $(CXXFLAGS) threadid.cpp
	g++ -o threadid3 $(CXXFLAGS) threadid3.cpp
clean:
	-rm -f *.o *~ 3thread hw_concur mutex no_mutex phone test threadid threadid3
