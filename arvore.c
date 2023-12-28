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


criarArvore(){
    Arvore * arvore = (Arvore*) malloc (sizeof(Arvore));
    arvore->raiz = NULL;
    return arvore;
}

