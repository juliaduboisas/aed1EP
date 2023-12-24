#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int checaComando(char* comando){ //checa a validade de um comando e qual comando foi
    if(strcmp(comando, "fim") == 0) { //se for "fim", retorna NULLe
        printf("$\n");
        return 0;
    }
    if(strcmp(comando, "busca")== 0){ //se for "busca", entra em busca
        printf("Buscando...\n"); //debug
        return 1; //retorna a palavra procurada
    }
    return -1;
}

//COMO COLOCAR NO MAIN
int main(){
    //chechaComando()
    char comando[50], palavra[50];
    printf("> ");
    scanf("%s", comando);
    int retornoComando = checaComando(comando);
    while(retornoComando!=0){
        if(retornoComando == 1){
            scanf("%s", palavra);
            //realizar busca
        } else {
            printf("Comando precisa ser 'busca' ou 'fim'.\n");
        }
        printf("> ");
        scanf("%s", comando);
        retornoComando = checaComando(comando);
    }
    return 0;
}