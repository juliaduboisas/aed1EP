#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "aux.h"

#define TRUE 1
#define FALSE 0

void clearLine(){
    char tmp[150];
    scanf("%[^\n]%*c", tmp);
}

void lowercaseSearch(char* palavra){
    for(int i = 0; palavra[i]; i++){
        palavra[i] = tolower(palavra[i]);
    }
}

int checaComando(char* comando, char* palavra){
    if(strcmp(comando, "fim") == 0) { //se for "fim", retorna NULL
        clearLine();
        printf("$\n");
        return 0;
    }
    if(strcmp(comando, "busca")== 0){ //se for "busca", entra em busca
        scanf("%s", palavra); //retorna a palavra procurada
        lowercaseSearch(palavra);
        clearLine();
        return 1; 
    }
    clearLine();
    return -1;
}

//COMO COLOCAR NO MAIN
/*int main(){
    //chechaComando()
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
}*/