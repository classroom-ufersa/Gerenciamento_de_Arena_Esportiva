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
void adicionar_time(Times *times) {
    // Alocar memória para o novo time
    Times *novo_time = (Times *)malloc(sizeof(Times));
    
    if (novo_time == NULL) {
        printf("Erro ao alocar memória para o novo time.\n");
        return;
    }
    
    // Solicitar informações do novo time ao usuário
    printf("Nome do time: ");
    fgets(novo_time->nome, sizeof(novo_time->nome), stdin);
    novo_time->nome[strcspn(novo_time->nome, "\n")] = '\0'; // Remover o '\n' do final da string
    
    printf("Origem do time: ");
    fgets(novo_time->origem, sizeof(novo_time->origem), stdin);
    novo_time->origem[strcspn(novo_time->origem, "\n")] = '\0'; // Remover o '\n' do final da string
    
    printf("Nome do técnico: ");
    fgets(novo_time->tecnico, sizeof(novo_time->tecnico), stdin);
    novo_time->tecnico[strcspn(novo_time->tecnico, "\n")] = '\0'; // Remover o '\n' do final da string
    
    printf("Quantidade de jogadores: ");
    scanf("%d", &novo_time->qtd_jogadores);
    getchar(); // Limpar o buffer do teclado
    
    novo_time->prox = NULL; // O próximo do novo time é inicializado como NULL
    
    // Caso especial: lista vazia ou novo time deve ser o primeiro da lista
    if (times->prox == NULL || strcmp(novo_time->nome, times->prox->nome) < 0) {
        novo_time->prox = times->prox;
        times->prox = novo_time;
        return;
    }
    
    // Encontrar a posição correta para inserir o novo time na lista ordenada
    Times *atual = times->prox;
    Times *ant = NULL;
    
    while (atual != NULL && strcmp(atual->nome, novo_time->nome) < 0) {
        ant = atual;
        atual = atual->prox;
    }
    
    // Inserir o novo time entre ant e atual na lista
    ant->prox = novo_time;
    novo_time->prox = atual;
}


Times *buscar_times(Times *times){
    char i[20];
    printf("Informe o nome");
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
        printf("Insira a nova origem");
        scanf(" %[^\n]", origem);
        char tecnico[50];
        printf("Insira o novo tecnico");
        scanf(" %[^\n]", tecnico);
        int qnt_jogadores;
        printf("Insira a nova quantidade de jogadores");
        scanf("%d", qnt_jogadores);
    
        strcpy(aux->origem,origem);
        strcpy(aux->tecnico,tecnico);
        aux->qtd_jogadores = qnt_jogadores;
}



// Função para imprimir todos os times na lista
void imprimir_times(const Times *times) {
    printf("\nLista de times:\n");
    const Times *time_atual = times;
    while (time_atual != NULL) {
        printf("Nome: %s\n", time_atual->nome);
        printf("Origem: %s\n", time_atual->origem);
        printf("Técnico: %s\n", time_atual->tecnico);
        printf("Quantidade de jogadores: %d\n\n", time_atual->qtd_jogadores);
        time_atual = time_atual->prox;
    }
}