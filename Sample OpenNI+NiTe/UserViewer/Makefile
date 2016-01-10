CC              := g++
LIBRARIES       := -lOpenNI2 -lglut -lGL -lGLU -lGLEW -lNiTE2
OBJECTS         := UserViewer


.PHONY: clean

all: test

test: 
	$(CC) -o $(OBJECTS) main.cpp Viewer.cpp $(LIBRARIES)
clean:
	rm -f *.o
