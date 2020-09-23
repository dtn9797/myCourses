CXXFLAGS += --std=c++14

all: decorator

# Build with the debug option
debug: CXXFLAGS += -g
debug: all

decorator: main.o walking_robot.o flying_robot.o diving_robot.o robot_decorator.o beep_robot_decorator.o chug_robot_decorator.o *.h
	$(CXX) $(CXXFLAGS) -o decorator *.o

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp
beep_robot_decorator.o: beep_robot_decorator.cpp *.h
	$(CXX) $(CXXFLAGS) -c beep_robot_decorator.cpp
chug_robot_decorator.o: chug_robot_decorator.cpp *.h
	$(CXX) $(CXXFLAGS) -c chug_robot_decorator.cpp
diving_robot.o: diving_robot.cpp *.h
	$(CXX) $(CXXFLAGS) -c diving_robot.cpp
flying_robot.o: flying_robot.cpp *.h
	$(CXX) $(CXXFLAGS) -c flying_robot.cpp
robot_decorator.o: robot_decorator.cpp *.h
	$(CXX) $(CXXFLAGS) -c robot_decorator.cpp
walking_robot.o: walking_robot.cpp *.h
	$(CXX) $(CXXFLAGS) -c walking_robot.cpp

clean:
	-rm -f *.o *.gch *~ a.out decorator
