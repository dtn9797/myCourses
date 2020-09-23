CXXFLAGS += -std=c++14

all: map map2 map3 regex

debug: CXXFLAGS += -g
debug: rebuild

rebuild: clean all

clean:
	-rm -f *.o *.gch *~ a.out map map2 map3 regex

