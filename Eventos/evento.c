#include "evento.h"
// Definindo a estrutura Evento
typedef struct evento {
    char nome[50];
    char tipo[50];
    struct evento *prox;
    Times *times; // Lista encadeada de times associados ao evento
} Evento;

void salvar_eventos_e_times(Evento *lista_eventos) {
    FILE *arquivo = fopen("eventos_e_times.txt", "w"); // Abre o arquivo para escrita (cria um novo arquivo ou sobrescreve o existente)

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
    
    Evento *evento_atual = lista_eventos;
    while (evento_atual != NULL) {
        // Escreve os dados do evento no arquivo
        fprintf(arquivo, "Nome do evento: %s\tTipo do evento: %s\n", evento_atual->nome, evento_atual->tipo);

        Times *time_atual = evento_atual->times;
        while (time_atual != NULL) {
            // Escreve os dados do time associado ao evento no arquivo
            fprintf(arquivo, "Nome do time: %s\tOrigem: %s\tTécnico: %s\tQuantidade de jogadores: %d\n", time_atual->nome, time_atual->origem, time_atual->tecnico, time_atual->qtd_jogadores);
            time_atual = time_atual->prox;
        }
        evento_atual = evento_atual->prox;
    }

    fclose(arquivo); // Fecha o arquivo após terminar de escrever
    printf("Eventos e times salvos com sucesso no arquivo eventos_e_times.txt.\n");
}

// Função para criar um novo evento e adicioná-lo à lista
void adicionar_evento(Evento **lista_eventos) {

    Evento *novo_evento = (Evento *)malloc(sizeof(Evento));
    
    if (novo_evento == NULL) {
        printf("Erro ao alocar memória para o novo evento.\n");
        return;
    }
    
    preencher_Evento(novo_evento);

    novo_evento->times = NULL; // Inicialmente, não há times associados ao evento
    
    novo_evento->prox = *lista_eventos; // O próximo evento agora será o antigo primeiro evento na lista
    
    *lista_eventos = novo_evento; // Atualizar o ponteiro para o primeiro evento na lista
    salvar_eventos_e_times(*lista_eventos);
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
    salvar_eventos_e_times(*lista_eventos);
}

// Função para adicionar um time a um evento
void adicionar_time_a_evento(Evento *evento) {
    Times *novo_time = (Times *)malloc(sizeof(Times));
    
    if (novo_time == NULL) {
        printf("Erro ao alocar memória para o novo time.\n");
        return;
    }
    
    adicionar_time(novo_time);
    
    novo_time->prox = evento->times; // O próximo time agora será o antigo primeiro time na lista
    
    evento->times = novo_time; // Atualizar o ponteiro para o primeiro time na lista
    salvar_eventos_e_times(evento);
}

// Função para remover um time de um evento
void remover_time_de_evento(Evento *evento, const char *nome_time) {
    Times *atual = evento->times;
    Times *anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->nome, nome_time) == 0) {
            if (anterior == NULL) {
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
    salvar_eventos_e_times(evento);
}

// Função para imprimir todos os eventos na lista
void imprimir_eventos(Evento *lista_eventos) {
    printf("\nLista de eventos:\n");
    Evento *evento_atual = lista_eventos;
    while (evento_atual != NULL) {
        printf("Nome do evento: %s\n", evento_atual->nome);
        printf("Tipo do evento: %s\n", evento_atual->tipo);
        
        printf("Times associados ao evento \"%s\":\n", evento_atual->nome);
        Times *time_atual = evento_atual->times;
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

void preencher_Evento(Evento *novo_evento){
    printf("Nome do evento: ");
    fgets(novo_evento->nome, 50, stdin);
    novo_evento->nome[strcspn(novo_evento->nome, "\n")] = '\0'; // Remover o '\n' do final da string
    
    printf("Tipo do evento: ");
    fgets(novo_evento->tipo, 50, stdin);
    novo_evento->tipo[strcspn(novo_evento->tipo, "\n")] = '\0'; // Remover o '\n' do final da string
}

Times *buscar_time_por_nome(Evento *lista_eventos) {
    char nome_evento[50];
    char nome_time[50];

    printf("Informe o nome do evento: ");
    fgets(nome_evento, sizeof(nome_evento), stdin);
    nome_evento[strcspn(nome_evento, "\n")] = '\0'; // Remover o '\n' do final da string

    Evento *evento_atual = lista_eventos;
    while (evento_atual != NULL) {
        if (strcmp(evento_atual->nome, nome_evento) == 0) {
            printf("Evento \"%s\" encontrado.\n", nome_evento);

            printf("Informe o nome do time que deseja buscar no evento \"%s\": ", nome_evento);
            fgets(nome_time, sizeof(nome_time), stdin);
            nome_time[strcspn(nome_time, "\n")] = '\0'; // Remover o '\n' do final da string

            Times *time_atual = evento_atual->times;
            while (time_atual != NULL) {
                if (strcmp(time_atual->nome, nome_time) == 0) {
                    printf("Time \"%s\" encontrado no evento \"%s\"!\n", nome_time, nome_evento);
                    printf("Detalhes do time:\n");
                    printf("Nome: %s\n", time_atual->nome);
                    printf("Origem: %s\n", time_atual->origem);
                    printf("Técnico: %s\n", time_atual->tecnico);
                    printf("Quantidade de jogadores: %d\n", time_atual->qtd_jogadores);
                    return time_atual; // Retorna o ponteiro para o time encontrado
                }
                time_atual = time_atual->prox;
            }

            printf("Time \"%s\" não encontrado no evento \"%s\".\n", nome_time, nome_evento);
            return NULL;
        }
        evento_atual = evento_atual->prox;
    }

    printf("Evento \"%s\" não encontrado na lista.\n", nome_evento);
    return NULL;
}

void *editar_time(Evento *lista_eventos) {
    char nome_evento[50];
    char nome_time[50];

    printf("Informe o nome do evento: ");
    fgets(nome_evento, sizeof(nome_evento), stdin);
    nome_evento[strcspn(nome_evento, "\n")] = '\0'; // Remover o '\n' do final da string

    Evento *evento_atual = lista_eventos;
    while (evento_atual != NULL) {
        if (strcmp(evento_atual->nome, nome_evento) == 0) {
            printf("Evento \"%s\" encontrado.\n", nome_evento);

            printf("Informe o nome do time que deseja buscar no evento \"%s\": ", nome_evento);
            fgets(nome_time, sizeof(nome_time), stdin);
            nome_time[strcspn(nome_time, "\n")] = '\0'; // Remover o '\n' do final da string

            Times *time_atual = evento_atual->times;
            while (time_atual != NULL) {
                if (strcmp(time_atual->nome, nome_time) == 0) {
                    printf("Time \"%s\" encontrado no evento \"%s\"!\n", nome_time, nome_evento);
                    printf("Detalhes do time:\n");
                    
                    printf("novo nome: ");
                    scanf(" %[^\n]", time_atual->nome);

                    printf("nova origem: ");
                    scanf(" %[^\n]", time_atual->origem);
                    
                    printf("novo tecnico: ");
                    scanf(" %[^\n]", time_atual->tecnico);
                    
                    printf("nova quantidade de jogadores: ");
                    scanf("%d", &time_atual->qtd_jogadores);
                    getchar(); // Limpar o buffer do teclado

                    printf("Time \"%s\" editado com sucesso no evento \"%s\"!\n", nome_time, nome_evento);
                }
                else{
                    printf("Time \"%s\" não encontrado no evento \"%s\".\n", nome_time, nome_evento);
                    return NULL;
                }
                time_atual = time_atual->prox;
            }
        }
        else{
            printf("Evento \"%s\" não encontrado na lista.\n", nome_evento);
        }
        evento_atual = evento_atual->prox;
    }
}