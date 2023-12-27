#include <stdio.h>
#include <string.h>

#include "aux.h"
#include "lista.h"

int main(int argc, char ** argv){

    int indexType;

    //ERROS DE EXECUCAO INVALIDA
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
    //FIM DE TESTES DE ERROS DE EXECUCAO INVALIDA
    
    //LEITURA, INDEXACAO E PRINT DE INFORMACOES INICIAIS
    Lista * lista = NULL;
    //Arvore * arvore = NULL;
    if(strcmp(argv[2], "lista") == 0){
        lista = criarLista();
        criarIndexLista(lista, file);
        indexType = 0;
    }
    // else {
    //      arvore = criarArvore();
    //      indexType = 1;
    //}

    //FIM DE LEITURA, INDEXACAO E PRINT DE INFORMACOES INICIAIS

    //LOOP DE COMANDOS DO USUARIO (já funciona)
    //chechaComando()
    char comando[100], palavra[100];
    printf("> ");
    scanf("%s", comando);
    int retornoComando = checaComando(comando, palavra);
    while(retornoComando!=0){
        if(retornoComando == 1){
            //realizar busca
            printf("Buscando %s...\n", palavra); //debug
            if(indexType == 0) buscaLista(lista, palavra);
            //else buscaArvore(arvore, palavra);
        } else {
            printf("Opcao invalida!\n");
        }
        printf("> ");
        scanf("%s", comando);
        retornoComando = checaComando(comando, palavra);
    }
    //FIM DE LOOP DE COMANDOS DO USUARIO
    
    //TODO O TEXTO DO PROGRAMA TEM QUE SER ESCRITO ANTES DESSE PONTO
    fclose(file);
    return 0;
}