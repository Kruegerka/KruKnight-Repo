CPPFLAGS=-g -pthread -I/sw/include/root
LDFLAGS=-g
LDLIBS=

all: STL_Decoder

main: main.o
	g++ $(LDFLAGS) -o STL_Decoder *.o $(LDLIBS)

main.o: STL_Decoder.cpp
	g++ $(CPPFLAGS) -c *.cpp

clean:
	rm -rf *.o
	rm -rf STL_Decoder
