#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * @brief Limpa a tela do console.
 * 
 * Esta função é utilizada para limpar o conteúdo da tela do console.
 */
void limpar_tela();

/**
 * @brief Verifica se uma string contém apenas letras.
 * 
 * Esta função verifica se uma string contém apenas letras do alfabeto, sem números ou outros caracteres especiais.
 * 
 * @param str A string a ser verificada.
 * @return 1 se a string contém apenas letras, 0 caso contrário.
 */
int contem_apenas_letras(char *str);

/**
 * @brief Verifica se uma string contém apenas dígitos.
 * 
 * Esta função verifica se todos os caracteres da string fornecida são dígitos ('0' a '9').
 * Retorna 1 se a string contém apenas dígitos ou 0 caso contrário.
 * 
 * @param str Ponteiro para a string a ser verificada.
 * @return 1 se a string contém apenas dígitos, 0 caso contrário.
 */
int contem_apenas_digitos(char *str);