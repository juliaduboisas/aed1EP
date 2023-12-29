#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef AUX_h 
#include "aux.h"
#endif

#define TRUE 1
#define FALSE 0
#define TAMANHO 1000

/**
 * Estrutura que define um no da arvore.
*/
typedef struct noArvore{
    TokenPalavra * tokenPalavra; 
    struct noArvore * esq; //filho esquerdo do nó atual
    struct noArvore * dir; //filho direito do nó atual
} NoArvore; //Estrutura tipo 'noArvore'

/**
 * Estrutura que define a arvore.
*/
typedef struct arvore {
    NoArvore * raiz; //Nó raiz que permite acessar todos os subnós
} Arvore; //Estrutura tipo 'arvore'

/**
 * Funcao que insere elementos (em ordem alfabetica) na arvore
*/
Boolean insereArvore(Arvore * arvore, TokenPalavra * token); /*Parâmetros são a arvore
                                                             onde os tokens serão inseridos
                                                             e token contém as informações 
                                                             sobre a palavra*/ 
                                                          
/**
 * Funcao que cria a arvore inicial.
*/
Arvore * criarArvore(); //funcão que retorna um ponteiro para estrutura tipo 'Arvore'

/**
 * Funcao que cria uma arvore a partir de um arquivo.
*/
int criarIndexArvore(Arvore * arvore, FILE * file, Arquivo * arquivo);