# include dependencies; rules below
include incl.defs

CC = g++
CCFLAGS = -Wextra -pedantic -std=c++11
SOURCES = main.cpp VolImage.cpp
OBJECTS = main.o VolImage.o
LIBS = -lm

volImage: $(OBJECTS)
	$(CC) $(CCFLAGS) $(OBJECTS) -o volImage $(LIBS)

main.o: main.cpp VolImage.h
	$(CC) $(CCFLAGS) main.cpp -c

VolImage.o: VolImage.cpp VolImage.h
	$(CC) $(CCFLAGS) VolImage.cpp -c

clean:
	rm -f bin/*.o 
	rm -f ./*.o
# type make depend to build dependencies
depend:
	$(CC) -M $(SOURCES) > incl.defs