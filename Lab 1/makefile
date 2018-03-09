CPPFLAGS=-g -pthread -I/sw/include/root
LDFLAGS=-g
LDLIBS=

all: main

main: main.o
        g++ $(LDFLAGS) -o main *.o $(LDLIBS)

main.o: main.cpp
        g++ $(CPPFLAGS) -c *.cpp

clean:
        rm -rf *.o
        rm -rf main
