#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "aux.h"

#define TRUE 1
#define FALSE 0

// Limpa o buffer de entrada até o caractere '\n'
void clearLine(){
    char tmp[150];
    scanf("%[^\n]%*c", tmp);
}

// Converte uma string para minúsculas
void toLowercase(char* palavra){
    for(int i = 0; palavra[i]; i++){
        palavra[i] = tolower(palavra[i]);
    }
}

// Substitui um caractere por outro em uma string
void substituiChar(char* original, char substituir, char substituto){
    for(int i = 0; original[i]; i++){
        if(original[i]==substituir) original[i] = substituto;
    }
}

void substituiTodoChar(char* original){ //modificar de acordo com o que deve ser retirado de certo texto
    substituiChar(original, '!', ' ');
	substituiChar(original, '"', ' ');
	substituiChar(original, '#', ' ');
    substituiChar(original, '$', ' ');
	substituiChar(original, '%', ' ');
	substituiChar(original, '&', ' ');
	substituiChar(original, '\'', ' ');
	substituiChar(original, '(', ' ');
    substituiChar(original, ')', ' ');
    substituiChar(original, '*', ' ');
    substituiChar(original, '+', ' ');
    substituiChar(original, ',', ' ');
    substituiChar(original, '-', ' ');
    substituiChar(original, '.', ' ');
    substituiChar(original, '/', ' ');
    substituiChar(original, ':', ' ');
    substituiChar(original, ';', ' ');
    substituiChar(original, '<', ' ');
    substituiChar(original, '>', ' ');
    substituiChar(original, '=', ' ');
    substituiChar(original, '?', ' ');
    substituiChar(original, '@', ' ');
    substituiChar(original, '[', ' ');
    substituiChar(original, ']', ' ');
    substituiChar(original, '^', ' ');
    substituiChar(original, '_', ' ');
    substituiChar(original, '`', ' ');
    substituiChar(original, '{', ' ');
    substituiChar(original, '|', ' ');
    substituiChar(original, '}', ' ');
    substituiChar(original, '~', ' ');
}

// Verifica e processa comandos de entrada
int checaComando(char* comando, char* palavra){
    if(strcmp(comando, "fim") == 0) { //se for "fim", retorna NULL
        clearLine(); //limpa o resto da linha
        printf("$\n");
        return 0;
    }
    if(strcmp(comando, "busca")== 0){ //se for "busca", entra em busca
        scanf("%s", palavra); //retorna a palavra procurada
        toLowercase(palavra); //coloca a palavra procurada em minusculas
        clearLine(); //limpa o resto da linha
        return 1; 
    }
    clearLine(); //limpa o resto da linha
    return -1;
}

// Insere uma nova linha em uma estrutura de arquivo
void insereLinha(Arquivo * arquivo, char* linha){
    arquivo->numLinhas++; //aumenta o numero total de linhas no arquivo para o numero da linha atual
    int tamLinha = strlen(linha); //determina o tamanho da linha
    arquivo->linhas = (Linha*) realloc(arquivo->linhas, (arquivo->numLinhas) * (sizeof(Linha))); //abre espaco para guardar o conteudo da linha atual
    Linha* linha_ = (Linha*) malloc(sizeof(Linha)); //abre espaco para a linha atual
    linha_->tamanho = tamLinha; //guarda o tamanho da linha na struct Linha
    linha_->conteudo = (char*)malloc(tamLinha*(sizeof(char))); //guarda espaco para o conteudo da linha na struct linha
    strcpy(linha_->conteudo, linha); //copia o conteudo da linha para a struct linha
    arquivo->linhas[arquivo->numLinhas-1] = *linha_; //guarda a linha no espaco numLinhas-1 das linhas do arquivo
}

// Lê um arquivo e armazena suas linhas em uma estrutura de arquivo
Arquivo * lerArquivo(FILE * file){ //utiliza parte da implementacao do Coutinho para separar e guardar as linhas
    char * linha;
	char * quebra_de_linha;
	int contador_linha;
    //inicia arquivo
    Arquivo * arquivo = (Arquivo*)malloc(1*(sizeof(Arquivo)));
    arquivo->numLinhas = 0;
    arquivo->linhas = (Linha*) malloc(sizeof(Linha));

    contador_linha = 0;
 	linha = (char *) malloc((1000 + 1) * sizeof(char)); //reserva cada linha

	while(file && fgets(linha, 1000, file)){ //enquanto o arquivo for válido && houver mais uma linha para ler
			
		if( (quebra_de_linha = strrchr(linha, '\n')) ) *quebra_de_linha = 0; //se a linha acaba, estabele uma quebra de linha

        printf("linha %03d: '%s'\n", contador_linha + 1, linha); //imprime a linha 'linha'

        insereLinha(arquivo, linha); //insere as linhas individualmente no arquivo
        contador_linha++;
    }
    return arquivo; //retorna o arquivo
}

// Atualiza informações de um token (como contagem e linhas)
void updateToken(TokenPalavra* token, int linha){
    token->contagem++; //aumenta a contagem de aparicoes da palavra
    //adiciona a nova linha em que aparece em um array
    token->linha = (int*)reallocarray(token->linha, token->contagem, (sizeof(int)));
    token->linha[token->contagem-1] = linha;
} //nessa funcao, se alguém escrever "hello hello hello" a linha vai aparecer triplicada, creio que e
  //situacao de arrumar na impressao (mais trabalho arrumar aqui que la)

// Imprime informações de um token, mostrando suas ocorrências em linhas específicas
void printToken(TokenPalavra* token, Arquivo* arquivo){
    printf("Existem %i ocorrencias da palavra '%s' na(s) seguinte(s) linha(s):\n", token->contagem, token->palavra);
    for(int i = 0; i<token->contagem; i++){
        printf("%05d: %s\n", token->linha[i], arquivo->linhas[token->linha[i]-1].conteudo);
    }
}


//TESTES

//chechaComando()
/*int main(){
    char comando[100], palavra[100];
    printf("> ");
    scanf("%s", comando);
    int retornoComando = checaComando(comando, palavra);
    while(retornoComando!=0){
        if(retornoComando == 1){
            //realizar busca
        } else {
            printf("Comando precisa ser 'busca' ou 'fim'.\n");
        }
        printf("> ");
        scanf("%s", comando);
        retornoComando = checaComando(comando, palavra);
    }
    return 0;
}

//lerArquivo() e insereLinha()
int main(){
    FILE * file = fopen("loremIpsum.txt", "r");
    Arquivo * a = lerArquivo(file);
    printf("O arquivo tem %i linhas\n", a->numLinhas);
    for(int i = 0; i<a->numLinhas; i++){
        printf("%i: %s\n", i, a->linhas[i].conteudo);
    }
    fclose(file);
    return 0;
}

*/