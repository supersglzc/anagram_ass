CC = gcc
CFLAGS = -Wall -std=c99

all: final_dictionary

dictionary.o: dictionary.c dictionary.h 
	$(CC) $(CFLAGS) -c dictionary.c

final_dictionary.o: final_dictionary.c dictionary.o dictionary.h
	$(CC) $(CFLAGS) -c final_dictionary.c
	
final_dictionary: final_dictionary.o 
	$(CC) $(CFLAGS) -o final_dictionary dictionary.o final_dictionary.o 

clean:
	rm *.o final_dictionary
