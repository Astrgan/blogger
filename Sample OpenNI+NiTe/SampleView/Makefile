CC              := g++
LIBRARIES       := -lOpenNI2 -lglut -lGL -lGLU -lGLEW
OBJECTS         := sampleView

.PHONY: clean

all: test

test: 
	$(CC) -o $(OBJECTS) main.cpp Viewer.cpp $(LIBRARIES)  
clean:
	rm -f *.o
