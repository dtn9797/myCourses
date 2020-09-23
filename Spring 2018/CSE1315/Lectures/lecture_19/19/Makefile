CXXFLAGS += -std=c++14

all: box_nonpoly box_override box_poly casting dynamic_cast void_star

debug: CXXFLAGS += -g
debug: rebuild

rebuild: clean all

box_nonpoly: box_nonpoly.cpp
	$(CXX) $(CXXFLAGS) -o box_nonpoly box_nonpoly.cpp
box_override: box_override.cpp
	$(CXX) $(CXXFLAGS)  -o box_override box_override.cpp
box_poly: box_poly.cpp
	$(CXX) $(CXXFLAGS)  -o box_poly box_poly.cpp
casting: casting.cpp
	$(CXX) $(CXXFLAGS)  -o casting casting.cpp
dynamic_cast: dynamic_cast.cpp 
	$(CXX) $(CXXFLAGS)  -o dynamic_cast dynamic_cast.cpp
void_star: void_star.cpp
	$(CXX) $(CXXFLAGS)  -o void_star void_star.cpp
clean:
	-rm -f *.o *.gch *~ a.out box_nonpoly box_override box_poly casting dynamic_cast void_star

