#Configurando o Makefile

all: aux lista
	gcc aux.o lista.o main.c -o ep

aux:
	gcc -c -o aux.o aux.c

lista:
	gcc -c -o lista.o lista.c

clean:
	rm -rf ep *.o
