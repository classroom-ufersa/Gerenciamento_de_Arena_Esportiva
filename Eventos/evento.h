
#include "../Times/time.c"

// Definição da estrutura Evento
typedef struct evento Evento;

// Protótipos das funções
void adicionar_evento(Evento **lista_eventos);
void remover_evento(Evento **lista_eventos, const char *nome_evento);
void adicionar_time_a_evento(Evento *evento);
void remover_time_de_evento(Evento *evento, const char *nome_time);
void imprimir_eventos(const Evento *lista_eventos);
