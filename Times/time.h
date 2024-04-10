// Definição da estrutura Time
#include "../Funções/funcao.c"

typedef struct times Times;

// Protótipos das funções
void adicionar_time(Times *times);
void imprimir_times(const Times *times);
Times *buscar_times(Times *times);
void editar_times(Times *times);

