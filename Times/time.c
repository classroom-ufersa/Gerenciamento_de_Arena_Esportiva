#include "time.h"

// Definindo a estrutura Time
struct times {
    char nome[50];
    char origem[50];
    char tecnico[50];
    int qtd_jogadores;
    struct times *prox;
};

// Função para adicionar um novo time de forma ordenada na lista
void adicionar_time(Times *novo_time) {
    // Alocar memória para o novo time
    printf("Nome do time: ");
    fgets(novo_time->nome, 50, stdin);
    novo_time->nome[strcspn(novo_time->nome, "\n")] = '\0'; // Remover o '\n' do final da string time
    
    printf("Origem do time: ");
    fgets(novo_time->origem, 50, stdin);
    novo_time->origem[strcspn(novo_time->origem, "\n")] = '\0'; // Remover o '\n' do final da string
    
    printf("Nome do técnico: ");
    fgets(novo_time->tecnico, 50, stdin);
    novo_time->tecnico[strcspn(novo_time->tecnico, "\n")] = '\0'; // Remover o '\n' do final da string
    
    printf("Quantidade de jogadores: ");
    scanf("%d", &novo_time->qtd_jogadores);
    getchar(); // Limpar o buffer do teclado
}