#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "aux.h"
#include "lista.h"

#define TRUE 1
#define FALSE 0
#define TAMANHO 1000

TokenPalavra* criarTokenLista(char* palavra, int linha){ //esse token e sensivel a maiusculas
    TokenPalavra* token = (TokenPalavra*)malloc(1*(sizeof(TokenPalavra))); //cria o token
    //atualiza as variáveis do token
    token->palavra = palavra; //se quisermos, podemos inserir a funcao toLowercase de aux.h e tirar de leitorTextos.c
    token->contagem = 1;
    token->linha = (int*)malloc(token->contagem*(sizeof(int)));
    token->linha[token->contagem-1] = linha;
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
    printf("palavra [%s][%i] {", token->palavra, token->contagem); //imprime a palavra
    //printf("contagem: %i\n", token->contagem); //imprime a contagem
    //printf("linhas: ");
    for(int i = 1; i<=token->contagem; i++){ //loop que imprime todas as linhas
        printf("%i ", token->linha[i-1]);
    }
    printf("}\n");
}

Lista * criarLista(){
    Lista * lista = (Lista*)malloc(sizeof(Lista));
    lista->primeiro = NULL;

    return lista;
}

void imprimeLista(Lista * lista){
    NoLista * p;
    for(p = lista->primeiro; p; p=p->proximo){
        printToken(p->token);
    }
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
        printf("cmp {%s} {%s} = %i\n", novo->token->palavra, p->token->palavra, cmp);
        if (cmp == 0){ //palavras iguais
            for (int i = 0; i < novo->token->contagem; i++) {
                updateToken(p->token, novo->token->linha[i]);
            }
            return TRUE;
        } else if(cmp > 0){ //novo é depois alfabeticamente que p
            anterior = p;
        } else{ //nov é antes alfabeticamente que p
            novo->proximo = p;
            break;
        }
        p = p->proximo; //passa para a proxima palavra
    }
    if(anterior) anterior->proximo = novo; // se houver anterior
    else lista->primeiro = novo; //se nao houver anterior
    imprimeLista(lista);
    return TRUE;
}

Boolean buscaLista(Lista * lista, char * palavraBuscada){
    NoLista * p;
    for(p = lista->primeiro; p; p=p->proximo){
        int cmp = strcmp(p->token->palavra, palavraBuscada);
        if(cmp == 0){
            printf("Existem %i ocorrencias da palavra '%s' na(s) seguinte(s) linha(s):\n", p->token->contagem, palavraBuscada);
            for(int i = 0; i<p->token->contagem; i++){
                printf("linha: %i\n", p->token->linha[i]);
            }
            return TRUE;
        } else if(cmp > 0){
            printf("Palavra '%s' nao encontrada.\n", palavraBuscada);
            return FALSE;
        }
    }
}

int criarIndexLista(Lista * lista, FILE * file){
    char * linha;
	char * copia_ponteiro_linha;
	char * quebra_de_linha;
	char * palavra;	
	int contador_linha;

    contador_linha = 0;
 	linha = (char *) malloc((TAMANHO + 1) * sizeof(char)); //reserva cada linha

	while(file && fgets(linha, TAMANHO, file)){ //enquanto o arquivo for válido && houver mais uma linha para ler
			
		if( (quebra_de_linha = strrchr(linha, '\n')) ) *quebra_de_linha = 0; //se a linha acaba, estabele uma quebra de linha

		substituiChar(linha, ',', ' ');
		substituiChar(linha, '-', ' ');
		substituiChar(linha, '.', ' ');

		printf("linha %03d: '%s'\n", contador_linha + 1, linha); //imprime a linha 'linha'

		// fazemos uma copia do endereço que corresponde ao array de chars 
		// usado para armazenar cada linha lida do arquivo pois a função 'strsep' 
		// modifica o endereço do ponteiro a cada chamada feita a esta função (e 
		// não queremos que 'linha' deixe de apontar para o inicio do array).

		copia_ponteiro_linha = linha;

		while( (palavra = strsep(&copia_ponteiro_linha, " ")) ){

			// antes de guardar a palavra em algum tipo de estrutura usada
			// para implementar o índice, será necessário fazer uma copia
			// da mesma, uma vez que o ponteiro 'palavra' aponta para uma 
			// substring dentro da string 'linha', e a cada nova linha lida
			// o conteúdo da linha anterior é sobreescrito.
			
			
            if(strcmp(palavra, "") != 0){
                toLowercase(palavra);
                printf("\t\t'%s'\n", palavra); //remove palavras nulas e imprime palavras da linha 'linha' separadamente
                TokenPalavra * token = criarTokenLista(palavra, contador_linha + 1);
                insereLista(lista, token);
            }
            
		}

		contador_linha++;
	}

	printf(">>>>> Arquivo carregado!\n");

    return contador_linha;
}

/////////////////////////////////////////////////////// comentar isso antes de mandar o makefile
int main(){ //casos de teste
    Lista* lista = criarLista();
    FILE * file = fopen("loremIpsum.txt", "r");
    criarIndexLista(lista, file);
    fclose(file);
    imprimeLista(lista);
    return 0;
}