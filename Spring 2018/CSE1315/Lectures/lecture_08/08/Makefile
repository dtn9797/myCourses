CXXFLAGS += --std=c++14

all: binary_buffers binary_bytes stringstreams chars

# Build with the debug option
debug: CXXFLAGS += -g
debug: all

binary_buffers: binary_buffers.o 
	$(CXX) $(CXXFLAGS) -o binary_buffers binary_buffers.o
binary_bytes: binary_bytes.o 
	$(CXX) $(CXXFLAGS) -o binary_bytes binary_bytes.o
stringstreams: stringstreams.o 
	$(CXX) $(CXXFLAGS) -o stringstreams stringstreams.o
chars: chars.o 
	$(CXX) $(CXXFLAGS) -o chars chars.o

binary_buffers.o: binary_buffers.cpp 
	$(CXX) $(CXXFLAGS) -c binary_buffers.cpp
binary_bytes.o: binary_bytes.cpp 
	$(CXX) $(CXXFLAGS) -c binary_bytes.cpp
stringstreams.o: stringstreams.cpp 
	$(CXX) $(CXXFLAGS) -c stringstreams.cpp
chars.o: chars.cpp 
	$(CXX) $(CXXFLAGS) -c chars.cpp

clean:
	-rm -f *.o *.gch *~ a.out binary_buffers binary_bytes stringstreams chars

