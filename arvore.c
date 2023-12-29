#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Incluindo headers personalizados
#include "aux.h"
#include "lista.h"
#include "arvore.h"

#define TRUE 1
#define FALSE 0
#define TAMANHO 1000

// Função recursiva para inserir um nó em uma árvore binária de busca.
Boolean insereArvoreRec(NoArvore * raiz, NoArvore * novo){
    
    // Comparando as palavras para determinar a posição do novo nó na árvore
    int cmp = strcmp(novo->tokenPalavra->palavra, raiz->tokenPalavra->palavra);
    
    if(cmp != 0){
        // Se a palavra for diferente, prossegue com a inserção na subárvore esquerda ou direita
        if(cmp < 0){
            if(raiz->esq) 
                return insereArvoreRec(raiz->esq, novo);
            else 
                raiz->esq = novo;
        } else {
            if(raiz->dir) 
                return insereArvoreRec(raiz->dir, novo);
            else 
                raiz->dir = novo;
        }
        return TRUE;        
    }
    // Se a palavra for igual, atualiza a contagem de ocorrências do token.
    updateToken(raiz->tokenPalavra, novo->tokenPalavra->linha);
    return FALSE;
}

// Função para inserir um token em uma árvore.
Boolean insereArvore(Arvore * arvore, TokenPalavra * token){
    // Aloca espaço para um novo nó
    NoArvore novo = (NoArvore*)malloc(sizeof(NoArvore));

    // Configura as informações do novo nó
    novo->tokenPalavra = token;
    novo->esq = novo->dir = NULL;

    // Se a árvore já tiver uma raiz, insere recursivamente.
    if(arvore->raiz) 
        return insereArvoreRec(arvore->raiz, novo);

    // Caso contrário, o novo nó se torna a raiz da árvore.
    arvore->raiz = novo;
    return TRUE;
}

// Função para criar uma árvore inicial.
Arvore* criarArvore(){
    // Aloca espaço para a árvore e para um token inicial.
    Arvore * arvore = (Arvore*) malloc (sizeof(Arvore));
    TokenPalavra * n = (TokenPalavra*)malloc(sizeof(TokenPalavra));

    // Configuração inicial do token
    n->palavra = "n";

    // Configurações iniciais da árvore
    arvore->raiz = NULL;

    // Insere o token inicial na árvore
    insereArvore(arvore, n);

    return arvore;
}