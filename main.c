#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv){
    if(argc != 3){ //Testa de a funcao recebeu os argumentos necessarios. Se nao recebeu, avisa o usuario e sai. 
        printf("Esse programa deve ser executado usando: %s nome_do_arquivo.txt tipo_de_lista\n", argv[0]);
        return 1;
    }
    if(strcmp(argv[2], "lista") != 0 && strcmp(argv[2], "arvore") != 0){ //Testa a validade do segundo argumento. Se nao for valido, avisa o usuario e sai.
        printf("O segundo argumento deve ser 'lista' ou 'arvore'\n");
        return 2;
    }
    FILE * file = fopen(argv[1], "r");
    if(file == NULL){ //Testa se o arquivo existe e pode ser lido.
        printf("O arquivo selecionado nao foi encontrado ou nao pode ser lido. Esse programa deve ser executado com um arquivo existente.\n");
        return 3;
    }
    
    
    
    
    //TODO O TEXTO DO PROGRAMA TEM QUE SER ESCRITO ANTES DESSE PONTO
    fclose(file);
    return 0;
}