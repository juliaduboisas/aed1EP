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