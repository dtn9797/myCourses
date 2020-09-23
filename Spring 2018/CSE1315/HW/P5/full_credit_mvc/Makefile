# Makefile for Library Management System
CXXFLAGS += --std=c++11

all: div lms test_library test_publication test_view test_genre test_media test_age

debug: CXXFLAGS += -g
debug: rebuild

rebuild: clean all

lms: main.o controller.o view.o library.o publication.o 
	$(CXX) $(CXXFLAGS) -o lms main.o controller.o view.o library.o publication.o 
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp
controller.o: controller.cpp *.h
	$(CXX) $(CXXFLAGS) -c controller.cpp
test_view: test_view.o controller.o view.o library.o publication.o 
	$(CXX) $(CXXFLAGS) -o test_view test_view.o controller.o view.o library.o publication.o 
test_view.o: test_view.cpp *.h
	$(CXX) $(CXXFLAGS) -c test_view.cpp
test_library: test_library.o library.o publication.o
	$(CXX) $(CXXFLAGS) -o test_library test_library.cpp library.o publication.o
test_library.o: test_library.cpp *.h
	$(CXX) $(CXXFLAGS) -c test_library.cpp
library.o: library.cpp *.h
	$(CXX) $(CXXFLAGS) -c library.cpp
test_publication: test_publication.o publication.o 
	$(CXX) $(CXXFLAGS) -o test_publication test_publication.o publication.o 
test_publication.o: test_publication.cpp *.h
	$(CXX) $(CXXFLAGS) -c test_publication.cpp
publication.o: publication.cpp *.h
	$(CXX) $(CXXFLAGS) -c publication.cpp
test_genre: test_genre.o 
	$(CXX) $(CXXFLAGS) -o test_genre test_genre.cpp 
test_genre.o: test_genre.cpp *.h
	$(CXX) $(CXXFLAGS) -c test_genre.cpp
test_media: test_media.o 
	$(CXX) $(CXXFLAGS) -o test_media test_media.cpp 
test_media.o: test_media.cpp *.h
	$(CXX) $(CXXFLAGS) -c test_media.cpp
test_age: test_age.o 
	$(CXX) $(CXXFLAGS) -o test_age test_age.cpp 
test_age.o: test_age.cpp *.h
	$(CXX) $(CXXFLAGS) -c test_age.cpp
clean:
	-rm -f *.o *.gch lms test_age test_genre test_media test_publication test_library test_view test_view_actual.txt
div:
	@echo
	@echo 'X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-'
	@echo '-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X'
	@echo 'X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-'
	@echo '-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X'
	@echo
