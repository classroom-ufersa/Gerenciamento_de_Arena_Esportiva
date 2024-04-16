#include "../include/evento.h"
typedef struct evento {
    char nome[50];
    char tipo[50];
    struct evento *prox;
    Times *times;
} Evento;

void salvar_eventos_e_times(Evento *lista_eventos) {
    FILE *arquivo = fopen("eventos_e_times.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
    
    Evento *evento_atual = lista_eventos;
    while (evento_atual != NULL) {
        fprintf(arquivo, "Nome do evento: %s\tTipo do evento: %s\n", evento_atual->nome, evento_atual->tipo);

        Times *time_atual = evento_atual->times;
        while (time_atual != NULL) {
            fprintf(arquivo, "Nome do time: %s\tOrigem: %s\tTécnico: %s\tQuantidade de jogadores: %d\n", time_atual->nome, time_atual->origem, time_atual->tecnico, time_atual->qtd_jogadores);
            time_atual = time_atual->prox;
        }
        evento_atual = evento_atual->prox;
    }

    fclose(arquivo);
    printf("Eventos e times salvos com sucesso no arquivo eventos_e_times.txt.\n");
}

void adicionar_evento(Evento **lista_eventos) {

    Evento *novo_evento = (Evento *)malloc(sizeof(Evento));
    
    if (novo_evento == NULL) {
        printf("Erro ao alocar memória para o novo evento.\n");
        return;
    }
    
    preencher_Evento(novo_evento);

    novo_evento->times = NULL;
    
    novo_evento->prox = *lista_eventos;
    
    *lista_eventos = novo_evento;
    salvar_eventos_e_times(*lista_eventos);
}

void remover_evento(Evento **lista_eventos, const char *nome_evento) {
    Evento *atual = *lista_eventos;
    Evento *anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->nome, nome_evento) == 0) {
            if (anterior == NULL) {
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

void adicionar_time_a_evento(Evento *evento) {
    Times *novo_time = (Times *)malloc(sizeof(Times));
    
    if (novo_time == NULL) {
        printf("Erro ao alocar memória para o novo time.\n");
        return;
    }
    
    adicionar_time(novo_time);
    
    novo_time->prox = evento->times;
    
    evento->times = novo_time;
}

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
}

void imprimir_eventos(Evento *lista_eventos) {
    printf("\nLista de eventos:\n");
    Evento *evento_atual = lista_eventos;
    while (evento_atual != NULL) {
        printf("Nome do evento: %s\n", evento_atual->nome);
        printf("Tipo do evento: %s\n", evento_atual->tipo);
        
        printf("Times associados ao evento \"%s\":\n", evento_atual->nome);
        Times *time_atual = evento_atual->times;
        while (time_atual != NULL) {
            Exibi_Times(time_atual);
            time_atual = time_atual->prox;
        }
        
        printf("\n");
        evento_atual = evento_atual->prox;
    }
}

void preencher_Evento(Evento *novo_evento){
    do
    {
        printf("Nome do evento: ");
        fgets(novo_evento->nome, 50, stdin);
        novo_evento->nome[strcspn(novo_evento->nome, "\n")] = '\0';
    } while (contem_apenas_letras(novo_evento->nome) == 0);
    
    do
    {
        printf("Tipo do evento: ");
        fgets(novo_evento->tipo, 50, stdin);
        novo_evento->tipo[strcspn(novo_evento->tipo, "\n")] = '\0';
    } while (contem_apenas_letras(novo_evento->tipo) == 0);
}

Times *buscar_time_por_nome(Evento *lista_eventos) {
    char nome_evento[50];
    char nome_time[50];

    printf("Informe o nome do evento: ");
    fgets(nome_evento, sizeof(nome_evento), stdin);
    nome_evento[strcspn(nome_evento, "\n")] = '\0'; 

    Evento *evento_atual = lista_eventos;
    while (evento_atual != NULL) {
        if (strcmp(evento_atual->nome, nome_evento) == 0) {
            printf("Evento \"%s\" encontrado.\n", nome_evento);

            printf("Informe o nome do time que deseja buscar no evento \"%s\": ", nome_evento);
            fgets(nome_time, sizeof(nome_time), stdin);
            nome_time[strcspn(nome_time, "\n")] = '\0';

            Times *time_atual = evento_atual->times;
            while (time_atual != NULL) {
                if (strcmp(time_atual->nome, nome_time) == 0) {
                    printf("Time \"%s\" encontrado no evento \"%s\"!\n", nome_time, nome_evento);
                    Exibi_Times(time_atual);
                    return time_atual;
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
    nome_evento[strcspn(nome_evento, "\n")] = '\0';

    Evento *evento_atual = lista_eventos;
    while (evento_atual != NULL) {
        if (strcmp(evento_atual->nome, nome_evento) == 0) {
            printf("Evento \"%s\" encontrado.\n", nome_evento);

            printf("Informe o nome do time que deseja buscar no evento \"%s\": ", nome_evento);
            fgets(nome_time, sizeof(nome_time), stdin);
            nome_time[strcspn(nome_time, "\n")] = '\0';

            Times *time_atual = evento_atual->times;
            while (time_atual != NULL) {
                if (strcmp(time_atual->nome, nome_time) == 0) {
                    printf("Time \"%s\" encontrado no evento \"%s\"!\n", nome_time, nome_evento);
                    printf("Detalhes do time:\n");
                    
                    adicionar_time(time_atual);

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