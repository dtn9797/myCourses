CXXFLAGS += -std=c++14

all: cp_constructor_and_asgn_op date iteration order_book vector

debug: CXXFLAGS += -g
debug: rebuild

rebuild: clean all

%.o: %.cpp *.h
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	-rm -f *.o *.gch *~ a.out cp_constructor_and_asgn_op date iteration order_book vector

