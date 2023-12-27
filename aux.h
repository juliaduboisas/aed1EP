/**
 * Estrutura que define as informacoes basicas de cada palavra.
*/
typedef struct tokenPalavra {
    char* palavra;
    int contagem;
    int* linha;
} TokenPalavra;

/**
 * Estrutura que define o conteúdo de cada linha.
*/
typedef struct linha {
    int numLinha;
    char* conteudoLinha;
} Linha;

/**
 * Checa a validade de um comando e qual comando foi inserido, descartando
 * o resto da linha.
 *  
 * Retorna:
 * - 0 se o comando for fim.
 * - 1 se o comando for busca, e preenche o char* palavra com a palavra
 *   a ser buscada.
 * - -1 se for um comando inválido
*/
int checaComando(char* comando, char* palavra);

/**
 * Altera os caracteres de uma string de maiusculo para minusculo.
*/
void toLowercase(char* palavra);

/**
 * Substitui um char "substituir" pelo char "substituto" na string "original".
*/
void substituiChar(char* original, char substituir, char substituto);