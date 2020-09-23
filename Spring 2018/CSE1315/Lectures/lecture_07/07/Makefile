CXXFLAGS += --std=c++14

# This is a menu unique to this particular Makefile
main:
	@echo "  'make barnyard_simple' for generic critter sounds only"
	@echo "  'make barnyard_animals' for custom critter sounds via multiple vectors"
	@echo "  'make barnyard_animals_2' to show the generic critter sound exists in derived classes"
	@echo "  'make barnyard_animals_poly' for custom critter sounds via polymorphism (preview)"
	@echo " "
	@echo "  'make mi' for simple multiple inheritance example"
	@echo "  'make diamond' for the solution to both parts of the diamond problem"
	@echo " "
	@echo "  'make read' for simple file reading"
	@echo "  'make write' for simple file writing"
	@echo "  'make reading' for example of the (temperature) Reading class"
	@echo " "
	@echo "  'make all' builds all demos (except test_enums)"
	@echo "  'make debug' builds all demos for the debugger"
	@echo "  'make clean' deletes all .o, .gch, and executable files"
	@echo " "
	@echo "Remember the TAB key!  'make e[TAB]' is quick and easy!"
	@echo " "

all: barnyard_simple barnyard_animals barnyard_animals_2 barnyard_animals_poly mi diamond read write reading

# Build all demos with the debug option
debug: CXXFLAGS += -g
debug: all

barnyard_simple: barnyard_simple.o *.h
	$(CXX) $(CXXFLAGS) -o barnyard_simple barnyard_simple.o
barnyard_animals: barnyard_animals.o *.h
	$(CXX) $(CXXFLAGS) -o barnyard_animals barnyard_animals.o
barnyard_animals_poly: barnyard_animals_poly.o *.h
	$(CXX) $(CXXFLAGS) -o barnyard_animals_poly barnyard_animals_poly.o
barnyard_animals_2: barnyard_animals_2.o *.h
	$(CXX) $(CXXFLAGS) -o barnyard_animals_2 barnyard_animals_2.o
barnyard_override: barnyard_override.o *.h
	$(CXX) $(CXXFLAGS) -o barnyard_override barnyard_override.o
mi: mi.o *.h
	$(CXX) $(CXXFLAGS) -o mi mi.o
diamond: diamond.o *.h
	$(CXX) $(CXXFLAGS) -o diamond diamond.o
read: read.o *.h
	$(CXX) $(CXXFLAGS) -o read read.o
write: write.o *.h
	$(CXX) $(CXXFLAGS) -o write write.o
reading: reading.o *.h
	$(CXX) $(CXXFLAGS) -o reading reading.o

barnyard_simple.o: barnyard_simple.cpp *.h
	$(CXX) $(CXXFLAGS) -c barnyard_simple.cpp
barnyard_animals.o: barnyard_animals.cpp *.h
	$(CXX) $(CXXFLAGS) -c barnyard_animals.cpp
barnyard_animals_poly.o: barnyard_animals_poly.cpp *.h
	$(CXX) $(CXXFLAGS) -c barnyard_animals_poly.cpp
barnyard_animals_2.o: barnyard_animals_2.cpp *.h
	$(CXX) $(CXXFLAGS) -c barnyard_animals_2.cpp
barnyard_override.o: barnyard_override.cpp *.h
	$(CXX) $(CXXFLAGS) -c barnyard_override.cpp
mi.o: mi.cpp *.h
	$(CXX) $(CXXFLAGS) -c mi.cpp
diamond.o: diamond.cpp *.h
	$(CXX) $(CXXFLAGS) -c diamond.cpp
read.o: read.cpp *.h
	$(CXX) $(CXXFLAGS) -c read.cpp
write.o: write.cpp *.h
	$(CXX) $(CXXFLAGS) -c write.cpp
reading.o: reading.cpp *.h
	$(CXX) $(CXXFLAGS) -c reading.cpp

clean:
	-rm -f *.o *.gch *~ a.out barnyard_simple barnyard_animals barnyard_animals_2 barnyard_animals_poly mi diamond read write reading
