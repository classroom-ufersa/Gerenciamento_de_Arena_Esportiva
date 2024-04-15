#include "../Times/time.c"

// Definição da estrutura Evento
typedef struct evento Evento;

// Protótipos das funções
void salvar_eventos_e_times(Evento *lista_eventos);
void adicionar_evento(Evento **lista_eventos);
void remover_evento(Evento **lista_eventos, const char *nome_evento);
void adicionar_time_a_evento(Evento *evento);
void remover_time_de_evento(Evento *evento, const char *nome_time);
void imprimir_eventos(Evento *lista_eventos);
void preencher_Evento(Evento *novo_evento);
Times *buscar_time_por_nome(Evento *lista_eventos);
void *editar_time(Evento *lista_eventos);