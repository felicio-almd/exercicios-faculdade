all: teste
teste: avl.o main.o
	gcc -o teste avl.o main.o
avl.o: avl.c avl.h
	gcc -c avl.c
main.c: main.c avl.c
	gcc -c main.c