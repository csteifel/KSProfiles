CC=g++
WXFLAGS=$(shell wx-config --cxxflags)
WXLIBS=$(shell wx-config --libs)
CXXFLAGS= -std=c++11 -Wall -Wno-reorder -Wextra $(WXFLAGS)
LDLIBS+=$(WXLIBS)

objects = main.o preferences.o

all: $(objects)
	$(CC) $(CXXFLAGS) -o ksprofiles.out $(objects) $(LDLIBS)


preferences.o: preferences.cpp preferences.h
main.o: main.h main.cpp preferences.h


clean:
	-rm -f *.o

remove: clean
	-rm -f ksprofiles.out
