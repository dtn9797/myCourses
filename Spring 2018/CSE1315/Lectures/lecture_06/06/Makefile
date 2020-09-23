# ######
# STEP 1: This selects the C++ version to use
# ######
CXXFLAGS += --std=c++14
CXXFLAGS += -Wfatal-errors

# ######
# STEP 4: Add additional capabilities
# ######

# This is a menu unique to this particular Makefile
main:
	@echo "  'make test_enums' to see warnings and errors mixing enum classes"
	@echo "  'make enum_class' to build the simplest enum class demo (no output)"
	@echo "  'make enum_class_no_constructor' to build without initializing"
	@echo "  'make enum_class_io' to build an enum class with simplistic output"
	@echo "  'make enum_class_streams' to build with overloaded operators"
	@echo "  'make enum_class_increment' to list months via incrementing"
	@echo " "
	@echo "  'make enum_class_streams_alt' AND"
	@echo "  'make enum_class_increment_alt' same as above but using map for month's to_string"
	@echo "                                  month's to_string and Date::operator<<"
	@echo " "
	@echo "  'make all' builds all demos (except test_enums)"
	@echo "  'make debug' builds all demos for the debugger"
	@echo "  'make clean' deletes all .o, .gch, and executable files"
	@echo " "
	@echo "Remember the TAB key!  'make e[TAB]' is quick and easy!"
	@echo " "

# Build all demos
all: enum_class enum_class_increment enum_class_increment_alt enum_class_io enum_class_io_no_constructor enum_class_no_constructor enum_class_streams

# Build all demos with the debug option
debug: CXXFLAGS += -g
debug: enum_class enum_class_increment enum_class_increment_alt enum_class_io enum_class_io_no_constructor enum_class_no_constructor enum_class_streams

# ######
# STEP 2: This are the "link" rules
# ######
test_enums: test_enums.o *.h
	$(CXX) $(CXXFLAGS) -o test_enums test_enums.o
enum_class: enum_class.o *.h
	$(CXX) $(CXXFLAGS) -o enum_class enum_class.o
enum_class_increment: enum_class_increment.o date.o month.o *.h
	$(CXX) $(CXXFLAGS) -o enum_class_increment enum_class_increment.o date.o month.o
enum_class_increment_alt: enum_class_increment.o date_method.o month_alt.o *.h
	$(CXX) $(CXXFLAGS) -o enum_class_increment_alt enum_class_increment.o date_method.o month_alt.o
enum_class_io: enum_class_io.o month.o *.h
	$(CXX) $(CXXFLAGS) -o enum_class_io enum_class_io.o month.o
enum_class_io_no_constructor: enum_class_io_no_constructor.o *.h
	$(CXX) $(CXXFLAGS) -o enum_class_io_no_constructor enum_class_io_no_constructor.o
enum_class_no_constructor: enum_class_no_constructor.o *.h
	$(CXX) $(CXXFLAGS) -o enum_class_no_constructor enum_class_no_constructor.o
enum_class_streams: enum_class_streams.o date.o month.o *.h
	$(CXX) $(CXXFLAGS) -o enum_class_streams enum_class_streams.o date.o month.o
enum_class_streams_alt: enum_class_streams_alt.o date_method.o month_alt.o *.h
	$(CXX) $(CXXFLAGS) -o enum_class_streams_alt enum_class_streams_alt.o date_method.o month_alt.o

# ######
# STEP 3: These are the "compile" rules to convert each .cpp to its .o
#   Notice the "-c" flags - otherwise, g++ will complain that you don't have a main()
#   The .h files don't need rules, as they are #included into the .cpps
# ######

test_enums.o: test_enums.cpp *.h
	$(CXX) $(CXXFLAGS) -c test_enums.cpp
enum_class.o: enum_class.cpp *.h
	$(CXX) $(CXXFLAGS) -c enum_class.cpp
enum_class_increment.o: enum_class_increment.cpp *.h
	$(CXX) $(CXXFLAGS) -c enum_class_increment.cpp
enum_class_io.o: enum_class_io.cpp *.h
	$(CXX) $(CXXFLAGS) -c enum_class_io.cpp
enum_class_io_no_constructor.o: enum_class_io_no_constructor.cpp *.h
	$(CXX) $(CXXFLAGS) -c enum_class_io_no_constructor.cpp
enum_class_no_constructor.o: enum_class_no_constructor.cpp *.h
	$(CXX) $(CXXFLAGS) -c enum_class_no_constructor.cpp
enum_class_streams.o: enum_class_streams.cpp *.h
	$(CXX) $(CXXFLAGS) -c enum_class_streams.cpp
enum_class_streams_alt.o: enum_class_streams_alt.cpp *.h
	$(CXX) $(CXXFLAGS) -c enum_class_streams_alt.cpp
date.o: date.cpp *.h
	$(CXX) $(CXXFLAGS) -c date.cpp
date_method.o: date_method.cpp *.h
	$(CXX) $(CXXFLAGS) -c date_method.cpp
month.o: month.cpp *.h
	$(CXX) $(CXXFLAGS) -c month.cpp
month_alt.o: month_alt.cpp *.h
	$(CXX) $(CXXFLAGS) -c month_alt.cpp

# ######
# STEP 4: Add additional capabilities
# ######

# This is the "clean" rule, to force a complete rebuild
clean:
	-rm -f *.o *.gch *~ test_enums enum_class enum_class_increment enum_class_increment_alt enum_class_io enum_class_io_no_constructor enum_class_no_constructor enum_class_streams enum_class_streams_alt a.out
