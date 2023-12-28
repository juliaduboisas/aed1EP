#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "lista.h"

#define TRUE 1
#define FALSE 0
#define TAMANHO 1000

TokenPalavra* criarTokenLista(char* palavra, int linha){ //esse token e sensivel a maiusculas
    TokenPalavra* token = (TokenPalavra*)malloc(1*(sizeof(TokenPalavra))); //cria o token
    //atualiza as variáveis do token
    int tamanhoPalavra = strlen(palavra); //define tamanho da palavra
    token->palavra = (char*)malloc(tamanhoPalavra*(sizeof(char))); //reserva o espaço da palavra na memória
    strcpy(token->palavra, palavra); //se quisermos, podemos inserir a funcao toLowercase de aux.h e tirar de leitorTextos.c
    token->contagem = 1;
    token->linha = (int*)malloc(token->contagem*(sizeof(int)));
    token->linha[token->contagem-1] = linha;
    return token; //retorna o token criado
}

Lista * criarLista(){
    Lista * lista = (Lista*)malloc(sizeof(Lista));
    lista->primeiro = NULL;

    return lista;
}

void imprimeLista(Lista * lista, Arquivo* arquivo){
    NoLista * p;
    for(p = lista->primeiro; p; p=p->proximo){
        printToken(p->token, arquivo);
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
    return TRUE;
}

TokenPalavra * buscaLista(Lista * lista, char * palavraBuscada){
    NoLista * p;
    for(p = lista->primeiro; p; p=p->proximo){
        int cmp = strcmp(p->token->palavra, palavraBuscada);
        if(cmp == 0){
            return p->token;
        } else if(cmp > 0){
            return NULL;
        }
    }
}

int criarIndexLista(Lista * lista, FILE * file, Arquivo * arquivo){
    char * linha;
	char * copia_ponteiro_linha;
	char * quebra_de_linha;
	char * palavra;	
	int contador_linha;

    contador_linha = 0;
 	linha = (char *) malloc((TAMANHO + 1) * sizeof(char)); //reserva cada linha

	while(file && fgets(linha, TAMANHO, file)){ //enquanto o arquivo for válido && houver mais uma linha para ler
			
		if( (quebra_de_linha = strrchr(linha, '\n')) ) *quebra_de_linha = 0; //se a linha acaba, estabele uma quebra de linha

        insereLinha(arquivo, linha);
        
		substituiTodoChar(linha);

		// fazemos uma copia do endereço que corresponde ao array de chars 
		// usado para armazenar cada linha lida do arquivo pois a função 'strsep' 
		// modifica o endereço do ponteiro a cada chamada feita a esta função (e 
		// não queremos que 'linha' deixe de apontar para o inicio do array).
        //(coutinho)

		copia_ponteiro_linha = linha;

		while( (palavra = strsep(&copia_ponteiro_linha, " ")) ){

			// antes de guardar a palavra em algum tipo de estrutura usada
			// para implementar o índice, será necessário fazer uma copia
			// da mesma, uma vez que o ponteiro 'palavra' aponta para uma 
			// substring dentro da string 'linha', e a cada nova linha lida
			// o conteúdo da linha anterior é sobreescrito. (coutinho)
			
            if(strcmp(palavra, "") != 0){
                toLowercase(palavra);
                TokenPalavra * token = criarTokenLista(palavra, contador_linha + 1);
                insereLista(lista, token);
            }
            
		}

		contador_linha++;
	}

    return contador_linha;
}

/////////////////////////////////////////////////////// comentar isso antes de mandar o makefile
/*int main(){ //casos de teste
    Lista* lista = criarLista();
    FILE * file = fopen("loremIpsum.txt", "r");
    Arquivo * arquivo = (Arquivo*)malloc(1*(sizeof(Arquivo)));
    arquivo->numLinhas = 0;
    arquivo->linhas = (Linha*) malloc(sizeof(Linha));

    int contLinha = criarIndexLista(lista, file, arquivo);
    fclose(file);
    for(int i = 0; i<contLinha; i++){
        printf("%05d: %s\n", i+1, arquivo->linhas[i].conteudo);
    }

    return 0;
}*/