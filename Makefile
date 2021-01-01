CC = gcc
FLAGS = -Wall -g

all: isort txtfind

isort: isort.c isort.h
	$(CC) $(FLAGS) isort.c -o isort
	
txtfind:txtfind.c txtfind.h
	$(CC) $(FLAGS) txtfind.c -o txtfind
	
 	

.PHONY: clean all

clean:
	rm -f isort txtfind
