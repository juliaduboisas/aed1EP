#Configurando o Makefile

ep: aux lista arvore
	gcc aux.o lista.o arvore.o main.c -o ep

aux:
	gcc -c -o aux.o aux.c

lista:
	gcc -c -o lista.o lista.c

arvore:
	gcc -c -o arvore.o arvore.c

pedantic: aux_pedantic lista_pedantic arvore_pedantic
	gcc -ansi -std=c99 -pedantic -Wall -Werror aux_pedantic.o lista_pedantic.o arvore_pedantic.o main.c -o ep

aux_pedantic:
	gcc -ansi -std=c99 -pedantic -Wall -Werror -c -o aux_pedantic.o aux.c

lista_pedantic:
	gcc -ansi -std=c99 -pedantic -Wall -Werror -c -o lista_pedantic.o lista.c

arvore_pedantic:
	gcc -ansi -std=c99 -pedantic -Wall -Werror -c -o arvore_pedantic.o arvore.c

clean:
	rm -rf ep *.o
