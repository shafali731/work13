all: signals.o
	gcc -o out signals.o

signals.o: signals.c
	gcc -c signals.c

run:
	./out

clear:
	rm go
	rm *.o
