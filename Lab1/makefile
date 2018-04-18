CPPFLAGS=-g -pthread -I/sw/include/root
LDFLAGS=-g 
LDLIBS=

all: STL_Decoder

STL_Decoder: STL_Decoder.o
	g++ $(LDFLAGS) -o STL_Decoder *.o $(LDLIBS) -Wall

STL_Decoder.o: STL_Decoder.cpp
	g++ $(CPPFLAGS) -c *.cpp -Wall

clean:
	rm -rf *.o
	rm -rf STL_Decoder
