#include <stdlib.h>

#include "aux.h"

/**
 * Estrutura que define cada elemento da lista.
*/
typedef struct noLista {
    TokenPalavra* token;
    struct noLista * proximo;
} NoLista;

/**
 * Estrutura que define a lista.
*/
typedef struct lista{
    NoLista * primeiro;
} Lista;

/**
 * Funcao que cria um token para a lista.
*/
TokenPalavra * criarTokenLista(char* palavra, int linha);

/**
 * Funcao que cria a lista inicial.
*/
Lista * criarLista();

/**
 * Funcao que insere um tokenPalavra* token em uma Lista* lista. 
*/
Boolean insereLista(Lista * lista, TokenPalavra * token);

/**
 * Funcao que busca em uma lista. Se encontra a palavra, já imprime seu token,
 * e se nao a encontra, imprime que ela nao foi encontrada.
*/
TokenPalavra * buscaLista (Lista * lista, char * palavraBuscada);

/**
 * Funcao que indexa a lista dado certo arquivo. Retorna o numero de linhas
 * do arquivo.
*/
int criarIndexLista(Lista * lista, FILE * file, Arquivo * arquivo);