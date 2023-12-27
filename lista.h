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
TokenPalavra criarTokenLista(char* palavra, int linha);

/**
 * Funcao que atualiza um token adicionando todas as suas linhas em token.linhas.
*/
void updateToken(TokenPalavra* token, int linha);

/**
 * Funcao que imprime um token e todas as suas informacoes.
*/
void printToken(TokenPalavra* token);

TokenPalavra * buscaLista (Lista * lista, char * palavraBuscada);