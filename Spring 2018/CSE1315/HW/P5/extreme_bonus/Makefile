# Makefile for Library
CXXFLAGS += --std=c++11

all: div main
rebuild: div clean main

debug: CXXFLAGS += -g
debug: rebuild

main: main.o controller.o view.o library.o publication.o patron.o book.o periodical.o newspaper.o audio.o video.o
	$(CXX) $(CXXFLAGS) -o lms main.o controller.o view.o library.o publication.o patron.o book.o periodical.o newspaper.o audio.o video.o
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp
controller.o: controller.cpp *.h
	$(CXX) $(CXXFLAGS) -c controller.cpp
test_view: test_view.o controller.o view.o library.o publication.o patron.o book.o periodical.o newspaper.o audio.o video.o
	$(CXX) $(CXXFLAGS) -o test_view test_view.o controller.o view.o library.o publication.o patron.o book.o periodical.o newspaper.o audio.o video.o
test_view.o: test_view.cpp view.h patron.h publication.h library.h
	$(CXX) $(CXXFLAGS) -c test_view.cpp
test_library: test_library.o library.o patron.o publication.o book.o periodical.o newspaper.o audio.o video.o
	$(CXX) $(CXXFLAGS) -o test_library test_library.o library.o patron.o publication.o book.o periodical.o newspaper.o audio.o video.o
test_library.o: test_library.cpp *.h
	$(CXX) $(CXXFLAGS) -c test_library.cpp
library.o: library.cpp *h
	$(CXX) $(CXXFLAGS) -c library.cpp
publication.o: publication.cpp *.h
	$(CXX) $(CXXFLAGS) -c publication.cpp
test_publication: test_publication.o publication.o patron.o
	$(CXX) $(CXXFLAGS) -o test_publication test_publication.o publication.o patron.o
test_publication.o: test_publication.cpp  *.h
	$(CXX) $(CXXFLAGS) -c test_publication.cpp 
test_patron: test_patron.o patron.o
	$(CXX) $(CXXFLAGS) -o test_patron test_patron.o patron.o
test_patron.o: test_patron.cpp  *.h
	$(CXX) $(CXXFLAGS) -c test_patron.cpp
patron.o: patron.cpp *.h
	$(CXX) $(CXXFLAGS) -c patron.cpp
book.o: book.cpp *.h
	$(CXX) $(CXXFLAGS) -c book.cpp
periodical.o: periodical.cpp *.h
	$(CXX) $(CXXFLAGS) -c periodical.cpp
newspaper.o: newspaper.cpp *.h
	$(CXX) $(CXXFLAGS) -c newspaper.cpp
audio.o: audio.cpp *.h
	$(CXX) $(CXXFLAGS) -c audio.cpp
video.o: video.cpp *.h
	$(CXX) $(CXXFLAGS) -c video.cpp
clean:
	-rm -f *.o lms test_age test_genre test_media test_publication test_patron test_library test_view test_view_actual.txt
div:
	# 'X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-'
	# '-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X'
	# 'X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-'
	# '-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X'
