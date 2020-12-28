CC = gcc
FLAGS = -Wall -g

all: isort txtfind

isort: isort.c
	$(CC) $(FLAGS) isort.c -o isort
	
txtfind:txtfind.c
	$(CC) $(FLAGS) txtfind.c -o txtfind
	
 	

.PHONY: clean all

clean:
	rm -f *.o 	
