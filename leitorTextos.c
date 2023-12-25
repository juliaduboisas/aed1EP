#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aux.h"

#define TAMANHO 1000

//funcao main utiliza o inteiro argc (número de palavras de argv) e o ponteiro para ponteiro de char argv (palavras)
//dentre essas palavras, a primeira (argv[0]) sempre será o nome do arquivo executável e, portanto, argc sempre contará uma
//palavra a mais do que os argumentos
int main(int argc, char ** argv){

	FILE * in;
	char * linha;
	char * copia_ponteiro_linha;
	char * quebra_de_linha;
	char * palavra;	
	int contador_linha;

	if(argc == 2) {

		in = fopen(argv[1], "r"); //abre o arquivo txt no qual a busca é realizada

		printf(">>>>> Carregando arquivo...\n");

		contador_linha = 0;
 		linha = (char *) malloc((TAMANHO + 1) * sizeof(char)); //reserva cada linha

		while(in && fgets(linha, TAMANHO, in)){ //enquanto o arquivo for válido && houver mais uma linha para ler
			
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

				lowercaseSearch(palavra);
				if(strcmp(palavra, "")!=0) printf("\t\t'%s'\n", palavra); //remove palavras nulas e imprime palavras da linha 'linha' separadamente


			}

			contador_linha++;
		}

		printf(">>>>> Arquivo carregado!\n");

		return 0;
	}

	return 1;
}