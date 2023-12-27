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
    char* conteudo;
    int tamanho;
} Linha;

typedef struct arquivo {
    int numLinhas;
    Linha* linhas;
} Arquivo;

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

/**
 * Substitui todos os char pedidos.
*/
void substituiTodoChar(char* original);

/**
 * Insere uma nova Linha em um Arquivo.
*/
void insereLinha(Arquivo * arquivo, char* linha);

/**
 * Lê um arquivo e retorna a estrutura Arquivo com as linhas.
*/
Arquivo * lerArquivo(FILE * file);