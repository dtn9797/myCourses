CXXFLAGS = -std=c++14

all: star pointers hello

debug: CXXFLAGS += -g
debug: rebuild

rebuild: clean all

star: main.o line.o turtle.o view.o *.h
	$(CXX) $(CXXFLAGS) -o star main.o line.o turtle.o view.o `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
line.o: line.cpp *.h
	$(CXX) $(CXXFLAGS) -c line.cpp
turtle.o: turtle.cpp *.h
	$(CXX) $(CXXFLAGS) -c turtle.cpp
view.o: view.cpp *.h
	$(CXX) $(CXXFLAGS) -c view.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
pointers: pointers.cpp
	$(CXX) $(CXXFLAGS) -o pointers pointers.cpp
hello: hello.cpp hellop.cpp
	$(CXX) $(CXXFLAGS) -o hello hello.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
	$(CXX) $(CXXFLAGS) -o hellop hellop.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
clean:
	-rm -f *.o star pointers hello hellop
