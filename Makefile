#Configurando o Makefile

all: aux
	gcc aux.o main.c -o ep

aux:
	gcc -c -o aux.o aux.c

clean:
	rm -rf *.o
