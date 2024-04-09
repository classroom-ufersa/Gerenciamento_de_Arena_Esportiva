#include "time.h"
#include "../Funções/funcao.h"

// Definindo a estrutura Time
typedef struct time {
    char nome[50];
    char origem[50];
    char tecnico[50];
    int qtd_jogadores;
    struct time *prox;
    Time *primeiro_time; // Ponteiro para o primeiro time na lista

} Time;

// Função para criar um novo time e adicioná-lo à lista
void adicionar_time(Times *times) {
    Time *novo_time = (Time *)malloc(sizeof(Time));
    
    if (novo_time == NULL) {
        printf("Erro ao alocar memória para o novo time.\n");
        return;
    }
    
    printf("Nome do time: ");
    fgets(novo_time->nome, 50, stdin);
    novo_time->nome[strcspn(novo_time->nome, "\n")] = '\0'; // Remover o '\n' do final da string
    
    printf("Origem do time: ");
    fgets(novo_time->origem, 50, stdin);
    novo_time->origem[strcspn(novo_time->origem, "\n")] = '\0'; // Remover o '\n' do final da string
    
    printf("Nome do técnico: ");
    fgets(novo_time->tecnico, 50, stdin);
    novo_time->tecnico[strcspn(novo_time->tecnico, "\n")] = '\0'; // Remover o '\n' do final da string
    
    printf("Quantidade de jogadores: ");
    scanf("%d", &novo_time->qtd_jogadores);
    getchar(); // Limpar o buffer do teclado
    
    novo_time->prox = times->primeiro_time; // O próximo time agora será o antigo primeiro time na lista
    
    times->primeiro_time = novo_time; // Atualizar o ponteiro para o primeiro time na lista
}

// Função para imprimir todos os times na lista
void imprimir_times(const Times *times) {
    printf("\nLista de times:\n");
    Time *time_atual = times->primeiro_time;
    while (time_atual != NULL) {
        printf("Nome: %s\n", time_atual->nome);
        printf("Origem: %s\n", time_atual->origem);
        printf("Técnico: %s\n", time_atual->tecnico);
        printf("Quantidade de jogadores: %d\n\n", time_atual->qtd_jogadores);
        time_atual = time_atual->prox;
    }
}