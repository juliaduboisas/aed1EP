#include <stdlib.h>

#ifndef AUX_h 
#include "aux.h"
#endif

/**
 * Nó da lista ligada.
 * 
 * Elementos:
 * 
 * > TokenPalavra* token
 *   Ponteiro para um token, que possui
 *   o string que é a palavra em si,
 *   a quantidade de vezes que ela aparece,
 *   e a matriz dos índices das linhas em que
 *   ela aparece.
 * 
 * > noLista* proximo
 *   Ponteiro para o proximo elemento
 *   da lista.
*/
typedef struct noLista {
    TokenPalavra* token;
    struct noLista * proximo;
} NoLista;

/**
 * Uma lista ligada, cujos nós são structs com
 * TokenPalavras e o próximo elemento.
 * 
 * Elementos:
 * 
 * > NoLista * primeiro
 *  Ponteiro para o primeiro elemento da lista 
 * 
*/
typedef struct lista{
    NoLista * primeiro;
} Lista;

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