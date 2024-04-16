#include "../src/funcao.c"

/**
 * @struct Times
 * @brief Estrutura para representar um time.
 */
typedef struct times Times;

/**
 * @brief Adiciona um novo time à lista de times.
 * 
 * Esta função recebe uma lista de times e solicita ao usuário as informações
 * necessárias para criar um novo time.
 * 
 * @param times Ponteiro para a lista de times à qual o novo time será adicionado.
 */
void adicionar_time(Times *times);


/**
 * @brief Exibe os detalhes de um time.
 * 
 * Esta função recebe um ponteiro para um time e imprime na tela os detalhes
 * desse time, incluindo nome, origem, técnico e quantidade de jogadores.
 * 
 * @param time_atual Ponteiro para o time cujos detalhes serão exibidos.
 */
void Exibi_Times(Times *time_atual);
