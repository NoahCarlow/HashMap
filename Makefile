EXEC = assignment5
CPP = g++
CFLAGS = -c -Wall

$(EXEC) : Assignment5.o HashTable.o
	$(CPP) -o $(EXEC) Assignment5.o HashTable.o

Assignment5.o : Assignment5.cpp
	$(CPP) $(CFLAGS) Assignment5.cpp

HashTable.o : HashTable.h HashTable.cpp
	$(CPP) $(CFLAGS) HashTable.cpp

clean :
	rm *.o