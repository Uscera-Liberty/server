all: server

server: main.o
	gcc main.o -o server

main.o: main.c
	gcc main.c -c main.o
