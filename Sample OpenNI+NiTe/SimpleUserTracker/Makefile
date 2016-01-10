CC              := g++
LIBRARIES       := -lOpenNI2 -lglut -lGL -lGLU -lGLEW -lNiTE2
OBJECTS         := SimpleUserTracker

.PHONY: clean

all: test

test: 
	$(CC) -o $(OBJECTS) main.cpp $(LIBRARIES) $(ICLUDE) 
clean:
	rm -f *.o
