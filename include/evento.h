#include "../src/time.c"

/**
 * @struct Evento
 * @brief Estrutura para representar um evento com uma lista encadeada de times associados.
 */
typedef struct evento Evento;

/**
 * @brief Salva os eventos e seus times associados em um arquivo.
 * 
 * Esta função recebe a lista de eventos e seus times associados e salva essas informações em um arquivo.
 * 
 * @param lista_eventos Um ponteiro para a lista de eventos.
 */
void salvar_eventos_e_times(Evento *lista_eventos);

/**
 * @brief Adiciona um novo evento à lista de eventos.
 * 
 * Esta função recebe uma lista de eventos e adiciona um novo evento a essa lista.
 * 
 * @param lista_eventos Um ponteiro para a lista de eventos.
 */
void adicionar_evento(Evento **lista_eventos);

/**
 * @brief Remove um evento da lista de eventos.
 * 
 * Esta função recebe uma lista de eventos e o nome de um evento a ser removido, e remove esse evento da lista.
 * 
 * @param lista_eventos Um ponteiro para a lista de eventos.
 * @param nome_evento O nome do evento a ser removido.
 */
void remover_evento(Evento **lista_eventos, char *nome_evento);

/**
 * @brief Adiciona um time a um evento específico.
 * 
 * Esta função recebe um evento e adiciona um novo time a esse evento.
 * 
 * @param evento Um ponteiro para o evento ao qual o time será adicionado.
 */
void adicionar_time_a_evento(Evento *evento);

/**
 * @brief Remove um time de um evento específico.
 * 
 * Esta função recebe um evento e o nome de um time a ser removido desse evento, e remove o time.
 * 
 * @param evento Um ponteiro para o evento do qual o time será removido.
 * @param nome_time O nome do time a ser removido.
 */
void remover_time_de_evento(Evento *evento, char *nome_time);

/**
 * @brief Imprime todos os eventos e os times associados a eles.
 * 
 * Esta função recebe uma lista de eventos e imprime na tela todos os eventos e os times associados a cada um.
 * 
 * @param lista_eventos Um ponteiro para a lista de eventos a ser impressa.
 */
void imprimir_eventos(Evento *lista_eventos);

/**
 * @brief Preenche os dados de um novo evento.
 * 
 * Esta função recebe um ponteiro para um novo evento e solicita ao usuário que preencha os dados desse evento.
 * 
 * @param novo_evento Um ponteiro para o novo evento a ser preenchido.
 */
void preencher_Evento(Evento *novo_evento);

/**
 * @brief Busca um time pelo nome em uma lista de eventos.
 * 
 * Esta função recebe uma lista de eventos e solicita ao usuário que informe o nome do evento e do time a ser buscado.
 * 
 * @param lista_eventos Um ponteiro para a lista de eventos.
 * @return Um ponteiro para o time encontrado, ou NULL se o time não for encontrado.
 */
Times *buscar_time_por_nome(Evento *lista_eventos);

/**
 * @brief Edita as características de um time em um evento.
 * 
 * Esta função recebe uma lista de eventos, solicita ao usuário que informe o nome do evento e do time a ser editado,
 * e permite a edição das características desse time.
 * 
 * @param lista_eventos Um ponteiro para a lista de eventos.
 * @return Um ponteiro para o time editado, ou NULL se o time não for encontrado.
 */
void *editar_time(Evento *lista_eventos);

/**
 * @brief Adiciona um novo evento à lista de eventos.
 * 
 * Esta função recebe um ponteiro para a lista de eventos e um evento a ser adicionado.
 * Aloca memória para um novo evento, copia os dados do evento fornecido para o novo evento
 * e insere o novo evento no início da lista de eventos. A lista de eventos é atualizada
 * para apontar para o novo evento adicionado.
 * 
 * @param lista_eventos Ponteiro para o ponteiro da lista de eventos.
 * @param evento Evento a ser adicionado à lista de eventos.
 */
void adicionar_evento_a_lista(Evento **lista_eventos, Evento evento);

/**
 * @brief Busca um evento na lista de eventos pelo nome.
 * 
 * Esta função percorre a lista de eventos procurando por um evento com o nome especificado.
 * Se o evento for encontrado, um ponteiro para o evento é retornado; caso contrário, retorna NULL.
 * 
 * @param lista_eventos Ponteiro para a lista de eventos.
 * @param nome_evento Nome do evento a ser buscado.
 * @return Ponteiro para o evento encontrado ou NULL se o evento não for encontrado.
 */
Evento *busca_evento(Evento *lista_eventos, char *nome_evento);

/**
 * @brief Lê os eventos e times de um arquivo e os carrega em uma lista de eventos.
 * 
 * Esta função lê os eventos e os times associados a partir de um arquivo e os carrega em uma lista de eventos.
 * Aloca memória para cada evento e time lidos do arquivo. Retorna um ponteiro para a lista de eventos
 * carregada a partir do arquivo.
 * 
 * @param lista_eventos Ponteiro para a lista de eventos existente (pode ser NULL).
 * @return Ponteiro para a lista de eventos carregada a partir do arquivo.
 */
Evento *ler_eventos_e_times(Evento *lista_eventos);