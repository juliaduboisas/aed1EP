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
 * Inicializa a lista com um nó do tipo Lista e
 * dá um ponteiro nulo para ele.
*/
Lista * criarLista();

/**
 * Insere um tokenPalavra* token em uma Lista* lista.
 * Ele também verifica se a palavra já está na lista.
 * 
 * Caso sim, registra a nova linha.
 * 
 * Caso contrário, coloca ela no local adequado, alfa-
 * beticamente. 
*/
Boolean insereLista(Lista * lista, TokenPalavra * token);

/**
 * Busca linear na lista.
 * 
 * Se encontra a palavra, já retorna seu token,
 * 
 * se não a encontra, retorna o ponteiro nulo.
*/
TokenPalavra * buscaLista (Lista * lista, char * palavraBuscada);

/**
 * Funcao que indexa para uma lista as palavras de um certo arquivo.
 * Retorna o numero de linhas do arquivo.
 * 
 * Ela já limpa o arquivo e salva a palavra com letras minúsculas.
*/
int criarIndexLista(Lista * lista, FILE * file, Arquivo * arquivo);