# COMP345 - Project Make File
CC=g++

CFLAGS=-Wall

OUT=main
all:
	$(CC) $(CFLAGS) Character.cpp CharacterDecorator.cpp ItemDecorator.cpp main.cpp -o $(OUT)
clean:
	rm -rf *.o $(OUT)
doc:
	doxygen doc_generator
