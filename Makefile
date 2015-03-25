CC=g++
WXFLAGS=$(shell wx-config --cxxflags)
WXLIBS=$(shell wx-config --libs)
CXXFLAGS= -std=c++11 -Wall -Wno-reorder -Wextra $(WXFLAGS)
LDLIBS+=$(WXLIBS)

objects = main.o

all: $(objects)
	$(CC) $(CXXFLAGS) -o ksprofiles.out $(objects) $(LDLIBS)


main.o: main.h main.cpp


clean:
	-rm -f *.o

remove: clean
	-rm -f ksprofiles.out
