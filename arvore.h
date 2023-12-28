#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "lista.h"

#define TRUE 1
#define FALSE 0
#define TAMANHO 1000

/**
 * Estrutura que define um no da arvore.
*/
typedef struct noArvore{
    TokenPalavra palavra;
    struct noArvore * esq;
    struct noArvore * dir;
} NoArvore;

/**
 * Estrutura que define a arvore.
*/
typedef struct arvore {
    NoArvore * raiz;
} Arvore;

/**
 * Funcao que cria a arvore inicial.
*/
Arvore * criarArvore();