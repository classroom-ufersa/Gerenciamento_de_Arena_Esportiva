#include "time.h"

struct times {
    char nome[50];
    char origem[50];
    char tecnico[50];
    int qtd_jogadores;
    struct times *prox;
};

void adicionar_time(Times *novo_time) {
    do
    {
        printf("Nome do time: ");
        fgets(novo_time->nome, 50, stdin);
        novo_time->nome[strcspn(novo_time->nome, "\n")] = '\0';
    } while (contem_apenas_letras(novo_time->nome) == 0);

    do
    {
        printf("Origem do time: ");
        fgets(novo_time->origem, 50, stdin);
        novo_time->origem[strcspn(novo_time->origem, "\n")] = '\0';
    } while (contem_apenas_letras(novo_time->origem) == 0);
    
    do
    {
        printf("Nome do técnico: ");
        fgets(novo_time->tecnico, 50, stdin);
        novo_time->tecnico[strcspn(novo_time->tecnico, "\n")] = '\0';
    } while (contem_apenas_letras(novo_time->tecnico) == 0);
    
    printf("Quantidade de jogadores: ");
    scanf("%d", &novo_time->qtd_jogadores);
    getchar(); // Limpar o buffer do teclado
}

void Exibi_Times(Times *time_atual){
        printf("Detalhes do time:\n");
        printf("- Nome do time: %s\n", time_atual->nome);     
        printf("  Origem: %s\n", time_atual->origem);
        printf("  Técnico: %s\n", time_atual->tecnico);
        printf("  Quantidade de jogadores: %d\n\n", time_atual->qtd_jogadores);
}