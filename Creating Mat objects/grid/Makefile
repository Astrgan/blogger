CC              := g++
LIBRARIES       := -lopencv_calib3d -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_highgui -lopencv_imgproc -lopencv_ml -lopencv_objdetect -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_ts -lopencv_video -lopencv_videostab
OBJECTS         := gridCV

.PHONY: clean

all: test

test: 
	$(CC) -o $(OBJECTS) main.cpp $(LIBRARIES)
        
clean:
	rm -f *.o