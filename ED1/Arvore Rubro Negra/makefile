all: teste
teste: arb.o main.o
	gcc -o teste arb.o main.o
arb.o: arb.c arb.h
	gcc -c arb.c
main.c: main.c arb.c
	gcc -c main.c