all: server

server: main.o
	gcc main.o -o server -std=c99 -g

main.o: main.c
	gcc main.c -c main.o -std=c99 -g
