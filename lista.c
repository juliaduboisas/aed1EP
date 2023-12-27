#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "lista.h"

#define TRUE 1
#define FALSE 0

TokenPalavra criarTokenLista(char* palavra, int linha){ //esse token e sensivel a maiusculas
    TokenPalavra token; //cria o token
    //atualiza as variáveis do token
    token.palavra = palavra; //se quisermos, podemos inserir a funcao toLowercase de aux.h e tirar de leitorTextos.c
    token.contagem = 1;
    token.linha = (int*)malloc(token.contagem*(sizeof(int)));
    token.linha[token.contagem-1] = linha;
    return token; //retorna o token criado
}

void updateToken(TokenPalavra* token, int linha){
    token->contagem++; //aumenta a contagem de aparicoes da palavra
    //adiciona a nova linha em que aparece em um array
    token->linha = (int*)reallocarray(token->linha, token->contagem, (sizeof(int)));
    token->linha[token->contagem-1] = linha;
} //nessa funcao, se alguém escrever "hello hello hello" a linha vai aparecer triplicada, creio que e
  //situacao de arrumar na impressao (mais trabalho arrumar aqui que la)

void printToken(TokenPalavra* token){
    printf("palavra: %s\n", token->palavra); //imprime a palavra
    printf("contagem: %i\n", token->contagem); //imprime a contagem
    printf("linhas: ");
    for(int i = 1; i<=token->contagem; i++){ //loop que imprime todas as linhas
        printf("%i ", token->linha[i-1]);
    }
    printf("\n\n");
}

Lista * criarLista(){
    Lista * lista = (Lista*)malloc(sizeof(Lista));
    lista->primeiro = NULL;

    return lista;
}

Boolean insereLista(Lista * lista, TokenPalavra * token){
    NoLista * p;
    NoLista * anterior;
    NoLista * novo = (NoLista*) malloc (sizeof(NoLista));

    //definir os valores do novo token
    novo->token = token;
    
    anterior = NULL;
    p = lista->primeiro;

    while(p){
        //estabelecer a diferenca entre duas palavras
        //retorna 0 se sao iguais, >0 se o primeiro caracterer que difere da primeira e menor alfabeticamente que o da segunda
        //e <0 se o primeiro caracterer que difere da primeira e maior alfabeticamente que o da segunda
        int cmp = strcmp(novo->token->palavra, p->token->palavra);
        if (cmp == 0){ //palavras iguais
            for (int i = 0; i < novo->token->contagem; i++) {
                updateToken(p->token, novo->token->linha[i]);
            }
            return TRUE;
        } else if(cmp > 0){ //antes alfabeticamente
            anterior = p;
        } else{ //depois alfabeticamente
            novo->proximo = p;
        }
        p = p->proximo; //passa para a proxima palavra
    }
    if(anterior) anterior->proximo = novo; // se houver anterior
    else lista->primeiro = novo; //se nao houver anterior
    return TRUE;
}

void imprimeLista(Lista * lista){
    NoLista * p;
    for(p = lista->primeiro; p; p=p->proximo){
        printToken(p->token);
    }
}

//TokenPalavra buscaLista(Lista * lista, char * palavraBuscada){
//    
//}

/////////////////////////////////////////////////////// comentar isso antes de mandar o makefile
int main(){ //casos de teste
    TokenPalavra token1 = criarTokenLista("anakim", 3);
    TokenPalavra token2 = criarTokenLista("lulu", 7);
    TokenPalavra token22 = criarTokenLista("lulu", 8);
    TokenPalavra token3 = criarTokenLista("zebra", 3);
    Lista* lista = criarLista();
    insereLista(lista, &token3);
    insereLista(lista, &token1);
    insereLista(lista, &token2);
    insereLista(lista, &token22);
    imprimeLista(lista);
    return 0;
}