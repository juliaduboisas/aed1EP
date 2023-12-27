#include <stdio.h>
#include <string.h>
#include <time.h>

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
    clock_t begin = clock(); //comeca a marcar o tempo para carregar o arquivo e construir o indice
    FILE * file = fopen(argv[1], "r");
    if(file == NULL){ //Testa se o arquivo existe e pode ser lido.
        printf("O arquivo selecionado nao foi encontrado ou nao pode ser lido. Esse programa deve ser executado com um arquivo existente.\n");
        return 3;
    }
    //FIM DE TESTES DE ERROS DE EXECUCAO INVALIDA
    
    //LEITURA, INDEXACAO E PRINT DE INFORMACOES INICIAIS
    Lista * lista = NULL;
    //Arvore * arvore = NULL;
    Arquivo * arquivo = (Arquivo*)malloc(1*(sizeof(Arquivo)));
    arquivo->numLinhas = 0;
    arquivo->linhas = (Linha*) malloc(sizeof(Linha));

    if(strcmp(argv[2], "lista") == 0){ //define o tipo de index como lista
        indexType = 0; //lista e o tipo 0, arvore sera o tipo 1
        lista = criarLista(); //cria a lista e a armazena em 'lista'
        int numLinhas = criarIndexLista(lista, file, arquivo); //indexa a lista e retorna o numero total de linhas em numLinhas
        clock_t end = clock(); //termina de marcar o tempo para carregar o arquivo e imprimir o indice
        int timeSpent = end - begin; //calcula o tempo total necessario
        //imprime infos necessarias
        printf("Tipo de indice:'lista'\n");
        printf("Arquivo de texto: '%s'\n", argv[1]);
        printf("Numero de linhas do arquivo: %i\n", numLinhas);
        printf("Tempo para carregar o arquivo e construir o indice: %05d ms\n", timeSpent);
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
            begin = clock(); //marca o momento de recebimento do comando
            //realizar busca
            TokenPalavra * resposta = NULL; //inicializa o TokenPalavra resposta
            if(indexType == 0){ //se a busca for com index em lista
                resposta = buscaLista(lista, palavra); //a resposta e o retorno da buscaLista
            }
            //else buscaArvore(arvore, palavra);
            clock_t end = clock(); //guarda o momento de finalizacao do comando (no caso, a busca)
            int timeSpent = end - begin; //calcula o tempo total de execucao
            if(resposta != NULL){ //se a palavra buscada nao estiver no texto
                printf("Palavra '%s' nao encontrada.", palavra); //imprime texto de resposta
            } else printToken(resposta, arquivo); //se a palavra estiver no texto, imprime as infos necessarioas
            printf("Tempo de busca: %05d\n", timeSpent); //imprime texto de busca
        } else { //se o comando nao for valido
            printf("Opcao invalida!\n");
        } //aguarda proximo comando, ate o usuario digitar 'fim'
        printf("> ");
        scanf("%s", comando);
        retornoComando = checaComando(comando, palavra);
    }
    //FIM DE LOOP DE COMANDOS DO USUARIO
    
    //TODO O TEXTO DO PROGRAMA TEM QUE SER ESCRITO ANTES DESSE PONTO
    fclose(file);
    return 0;
}