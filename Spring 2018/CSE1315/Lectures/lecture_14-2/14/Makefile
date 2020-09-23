CXXFLAGS += -std=c++14
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: dialog1 dialog2 dialog3 virtual1 virtual2 factory observer

debug: CXXFLAGS += -g
debug: rebuild

rebuild: clean all

dialog1: dialog1.cpp dialogs.o *.h
	$(CXX) $(CXXFLAGS) -o dialog1 dialog1.cpp dialogs.o  $(GTKFLAGS)

dialog2: dialog2.cpp *.h
	$(CXX) $(CXXFLAGS) -o dialog2 dialog2.cpp $(GTKFLAGS)

dialog3: dialog3.cpp hello.o *.h
	$(CXX) $(CXXFLAGS) -o dialog3 dialog3.cpp hello.o  $(GTKFLAGS)

virtual1: virtual1.cpp *.h
	$(CXX) $(CXXFLAGS) -o virtual1 virtual1.cpp

virtual2: virtual2.cpp *.h
	$(CXX) $(CXXFLAGS) -o virtual2 virtual2.cpp 

dialogs.o: dialogs.cpp *.h
	$(CXX) $(CXXFLAGS) -c dialogs.cpp $(GTKFLAGS)

hello.o: hello.cpp *.h
	$(CXX) $(CXXFLAGS) -c hello.cpp $(GTKFLAGS)

factory: factory.cpp *.h
	$(CXX) $(CXXFLAGS) -o factory factory.cpp

observer: observer.cpp *.h
	$(CXX) $(CXXFLAGS) -o observer observer.cpp

clean:
	-rm -f *.o *.gch *~ dialog1 dialog2 dialog3 virtual1 virtual2 factory observer
