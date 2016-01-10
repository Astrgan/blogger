CC              := g++
LIBRARIES       := -lOpenNI2 -lglut -lGL -lGLU -lGLEW -lNiTE2
OBJECTS         := HandViver

.PHONY: clean

all: test

test: 
	$(CC) -o $(OBJECTS) main.cpp Viewer.cpp $(LIBRARIES) $(ICLUDE) 
clean:
	rm -f *.o
