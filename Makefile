CC=g++
CFLAGS=-lglut -lGL -lGLU

hellomake: redminoteGL.cpp
	$(CC) -o redminoteGL redminoteGL.cpp $(CFLAGS)
