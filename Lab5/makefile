CC=g++
CFLAGS=-c -Wall -std=c++11
LDFLAGS= -lX11
SOURCES=main.cpp gcontext.cpp x11context.cpp shape.cpp line.cpp matrix.cpp triangle.cpp image.cpp mydrawingbase.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=lab5

all: $(SOURCES) $(EXECUTABLE)

# pull in dependency info for *existing* .o files
-include $(OBJECTS:.o=.d)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
	$(CC) -MM $(CFLAGS) $< > $*.d

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) *.d
