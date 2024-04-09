#include "time.h"
#include "../Funções/funcao.h"

// Definindo a estrutura Time
typedef struct times {
    char nome[50];
    char origem[50];
    char tecnico[50];
    int qtd_jogadores;
    struct time *prox;
} Times;

// Função para criar um novo time e adicioná-lo à lista
void adicionar_time(Times *times) {
    Times *novo_time = (Times *)malloc(sizeof(Times));
    
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

    novo_time->prox = NULL;

    if(novo_time == NULL || strcmp (times->nome, novo_time->nome) >0){
        times->prox = novo_time;
        return novo_time;
    }
    
    Times *ant = NULL;
    Times *atual = times;

     while (atual != NULL && strcmp(atual->nome, novo_time->nome) < 0)
    {
        ant = atual;
        atual = atual->prox;
    }

    ant->prox = times;
    novo_time->prox = atual;

    return times;
}

Times *buscar_times(Times *times){
    char i[20];
    Printf("Informe o nome");
    scanf(" %[^\n]", i);
    Times *aux = times;


    while(aux != NULL && strcmp(aux->nome,i) != 0){
        aux = aux->prox;
        return aux;
    }
}

void editar_times(Times *times){
    Times *aux = buscar_times(times);
        char origem[20];
        Printf("Insira a nova origem");
        scanf(" %[^\n]", origem);
        char tecnico[50];
         Printf("Insira o novo tecnico");
        scanf(" %[^\n]", tecnico);
        int qnt_jogadores;
        Printf("Insira a nova quantidade de jogadores");
        scanf("%d", qnt_jogadores);
    
        strcpy(aux->origem,origem);
        strcpy(aux->tecnico,tecnico);
        aux->qtd_jogadores = qnt_jogadores;
}



// Função para imprimir todos os times na lista
void imprimir_times(const Times *times) {
    printf("\nLista de times:\n");
    Times *time_atual = times;
    while (time_atual != NULL) {
        printf("Nome: %s\n", time_atual->nome);
        printf("Origem: %s\n", time_atual->origem);
        printf("Técnico: %s\n", time_atual->tecnico);
        printf("Quantidade de jogadores: %d\n\n", time_atual->qtd_jogadores);
        time_atual = time_atual->prox;
    }
}