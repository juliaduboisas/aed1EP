#include <stdlib.h>

typedef int Boolean;

/**
 * Estrutura que define as informacoes basicas de cada palavra.
*/
typedef struct tokenPalavra {
    char* palavra;
    int contagem;
    int* linha;
} TokenPalavra;

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
 * Funcao que atualiza um token adicionando todas as suas linhas em token.linhas.
*/
void updateToken(TokenPalavra* token, int linha);

/**
 * Funcao que imprime um token e todas as suas informacoes.
*/
void printToken(TokenPalavra* token);

/**
 * Funcao que busca em uma lista. Se encontra a palavra, já imprime seu token,
 * e se nao a encontra, imprime que ela nao foi encontrada.
*/
Boolean buscaLista (Lista * lista, char * palavraBuscada);

/**
 * Funcao que indexa a lista dado certo arquivo. Retorna o numero de linhas
 * do arquivo.
*/
int criarIndexLista(Lista * lista, FILE * file);