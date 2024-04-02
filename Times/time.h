// Definição da estrutura Time
typedef struct time Time;

// Definição da estrutura Times
typedef struct {
    Time *primeiro_time;
} Times;

// Protótipos das funções
void adicionar_time(Times *times);
void imprimir_times(const Times *times);
