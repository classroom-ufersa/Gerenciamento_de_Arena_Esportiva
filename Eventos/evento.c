#include "evento.h"
// Definindo a estrutura Evento
typedef struct evento {
    char nome[50];
    char tipo[50];
    struct evento *prox;
    Time *times; // Lista encadeada de times associados ao evento
} Evento;

// Função para criar um novo evento e adicioná-lo à lista
void adicionar_evento(Evento **lista_eventos) {

    Evento *novo_evento = (Evento *)malloc(sizeof(Evento));
    
    if (novo_evento == NULL) {
        printf("Erro ao alocar memória para o novo evento.\n");
        return;
    }
    
    printf("Nome do evento: ");
    fgets(novo_evento->nome, 50, stdin);
    novo_evento->nome[strcspn(novo_evento->nome, "\n")] = '\0'; // Remover o '\n' do final da string
    
    printf("Tipo do evento: ");
    fgets(novo_evento->tipo, 50, stdin);
    novo_evento->tipo[strcspn(novo_evento->tipo, "\n")] = '\0'; // Remover o '\n' do final da string

    novo_evento->times = NULL; // Inicialmente, não há times associados ao evento
    
    novo_evento->prox = *lista_eventos; // O próximo evento agora será o antigo primeiro evento na lista
    
    *lista_eventos = novo_evento; // Atualizar o ponteiro para o primeiro evento na lista
    
}

// Função para remover um evento da lista
void remover_evento(Evento **lista_eventos, const char *nome_evento) {
    Evento *atual = *lista_eventos;
    Evento *anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->nome, nome_evento) == 0) {
            if (anterior == NULL) {
                // O evento a ser removido é o primeiro da lista
                *lista_eventos = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }

            free(atual);
            printf("Evento \"%s\" removido com sucesso.\n", nome_evento);
            return;
        }

        anterior = atual;
        atual = atual->prox;
    }

    printf("Evento \"%s\" não encontrado na lista.\n", nome_evento);
}

// Função para adicionar um time a um evento
void adicionar_time_a_evento(Evento *evento) {
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
    
    novo_time->prox = evento->times; // O próximo time agora será o antigo primeiro time na lista
    
    evento->times = novo_time; // Atualizar o ponteiro para o primeiro time na lista
}

// Função para remover um time de um evento
void remover_time_de_evento(Evento *evento, const char *nome_time) {
    Time *atual = evento->times;
    Time *anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->nome, nome_time) == 0) {
            if (anterior == NULL) {
                // O time a ser removido é o primeiro da lista
                evento->times = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }

            free(atual);
            printf("Time \"%s\" removido do evento \"%s\" com sucesso.\n", nome_time, evento->nome);
            return;
        }

        anterior = atual;
        atual = atual->prox;
    }

    printf("Time \"%s\" não encontrado no evento \"%s\".\n", nome_time, evento->nome);
}

// Função para imprimir todos os eventos na lista
void imprimir_eventos(const Evento *lista_eventos) {
    printf("\nLista de eventos:\n");
    const Evento *evento_atual = lista_eventos;
    while (evento_atual != NULL) {
        printf("Nome do evento: %s\n", evento_atual->nome);
        printf("Tipo do evento: %s\n", evento_atual->tipo);
        
        printf("Times associados ao evento \"%s\":\n", evento_atual->nome);
        Time *time_atual = evento_atual->times;
        while (time_atual != NULL) {
            printf("- Nome do time: %s\n", time_atual->nome);
            printf("  Origem: %s\n", time_atual->origem);
            printf("  Técnico: %s\n", time_atual->tecnico);
            printf("  Quantidade de jogadores: %d\n\n", time_atual->qtd_jogadores);
            time_atual = time_atual->prox;
        }
        
        printf("\n");
        evento_atual = evento_atual->prox;
    }
}