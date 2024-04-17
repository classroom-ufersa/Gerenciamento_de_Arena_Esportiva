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

/**
 * @brief Adiciona um novo time a uma lista encadeada de times.
 * 
 * Esta função aloca memória para um novo time e o adiciona à lista encadeada de times,
 * colocando-o como primeiro elemento da lista.
 * 
 * @param atual O ponteiro para o primeiro time na lista encadeada (atual->times).
 * @param time O time a ser adicionado à lista.
 * @return Um ponteiro para o novo time adicionado, que agora é o primeiro na lista.
 * Retorna NULL em caso de falha na alocação de memória.
 */
Times *adicionar_time_a_lista(Times *atual, Times time);