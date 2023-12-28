#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "aux.h"
#include "lista.h"
#include "arvore.h"

#define TRUE 1
#define FALSE 0
#define TAMANHO 1000


Arvore* criarArvore(){
    Arvore * arvore = (Arvore*) malloc (sizeof(Arvore));

    TokenPalavra * n = (TokenPalavra*)malloc(sizeof(TokenPalavra));

    n->palavra = "n";

    arvore->raiz = NULL;

    insereArvore(arvore, n);

    return arvore;
}

Boolean insereArvoreRec(NoArvore * raiz, NoArvore * novo){
    
    int cmp = strcmp(novo->tokenPalavra->palavra, raiz->tokenPalavra->palavra)
    if(cmp != 0){
        
        if(cmp<0){
            if(raiz->esq) return insereArvoreRec(raiz->esq, novo);
            else raiz->esq = novo;
        } else {
            if(raiz->dir) return insereArvoreRec(raiz->dir, novo);
            else raiz->dir = novo;
        }

        return TRUE;        
    }
    updateToken(raiz->tokenPalavra, novo->tokenPalavra->linha);
    return FALSE;
}

Boolean insereArvore(Arvore * arvore, TokenPalavra * token){
    NoArvore novo = (NoArvore*)malloc(sizeof(NoArvore));

    novo->tokenPalavra = token;
    novo->esq = novo->dir = NULL;

    if(arvore->raiz) return insereArvoreRec(arvore->raiz, novo);

    arvore->raiz = novo;
    return TRUE;
}