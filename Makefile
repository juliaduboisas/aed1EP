#Configurando o Makefile

all: aux lista arvore
	gcc aux.o lista.o arvore.o main.c -o ep

aux:
	gcc -c -o aux.o aux.c

lista:
	gcc -c -o lista.o lista.c

arvore:
	gcc -c -o arvore.o arvore.c

clean:
	rm -rf ep *.o
