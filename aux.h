#define AUX_h


typedef int Boolean;

/**
 * Estrutura que define as informacoes basicas de cada palavra.
 * 
 * Elementos:
 * 
 * > char* palavra
 *   A palavra que será guardada.
 * 
 * > int contagem
 *   Quantidade de vezes que a palavra aparece.
 * 
 * > int* linha
 *   Linhas em que a palavra aparece.
*/
typedef struct tokenPalavra {
    char* palavra;
    int contagem;
    int* linha;
} TokenPalavra;

/**
 * Estrutura que define o conteúdo de cada linha.
 * 
 * > char* conteudo
 *   A string que vai do primeiro caracter até o \n.
 * 
 * > int tamanho
 *   Número de tokens na linha.
*/
typedef struct linha {
    char* conteudo;
    int tamanho;
} Linha;

/**
 * O arquivo tokenizado.
 * 
 * >int numLinhas
 *  Número de linhas no arquivo.
 * 
 * > Linha* linhas
 *   Array das linhas do arquivo. 
*/
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
 * Substitui todos os char especiais pedidos, como $%#\().
*/
void substituiTodoChar(char* original);

/**
 * Insere uma nova struct Linha em um struct Arquivo.
*/
void insereLinha(Arquivo * arquivo, char* linha);

/**
 * Lê um arquivo e retorna a estrutura Arquivo com as linhas.
*/
Arquivo * lerArquivo(FILE * file);

/**
 * Funcao que atualiza um token adicionando todas as suas linhas no array token.linhas.
*/
void updateToken(TokenPalavra* token, int linha);

/**
 * Funcao que imprime um token e todas as suas informacoes. Deve ser usada quando
 * o token e encontrado na memoria.
*/
void printToken(TokenPalavra* token, Arquivo* arquivo);

/**
 * Funcao que cria um token.
*/
TokenPalavra * criarToken(char* palavra, int linha);
