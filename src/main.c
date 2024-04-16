#include "evento.c"

int main() {
    Evento *lista_eventos = NULL;
    char opcao;
    int n = 1;

    lista_eventos = ler_eventos_e_times(lista_eventos);

    do {
        printf(" ====== Menu ======\n");
        printf("1. Adicionar evento\n");
        printf("2. Remover evento\n");
        printf("3. Adicionar time a um evento\n");
        printf("4. Remover time de um evento\n");
        printf("5. Imprimir eventos\n");
        printf("6. Buscar time\n");
        printf("7. Editar time\n");
        printf("8. Sair\n");
        printf(" ==================\n");
        printf("Escolha uma opção: ");
        
        char entrada[50];
        fgets(entrada, sizeof(entrada), stdin);
        entrada[strcspn(entrada, "\n")] = '\0';

        if (strlen(entrada) == 1 && isdigit(entrada[0]) && entrada[0] >= '1' && entrada[0] <= '8') {
            opcao = entrada[0];
        } else {
            printf("Opção inválida. Tente novamente.\n");
            continue;
        }

        switch (opcao) {
            case '1':
                adicionar_evento(&lista_eventos);
                salvar_eventos_e_times(lista_eventos);
                limpar_tela();
                break;
            case '2': {
                char nome_evento_remover[50];
                printf("Digite o nome do evento que deseja remover: ");
                fgets(nome_evento_remover, sizeof(nome_evento_remover), stdin);
                nome_evento_remover[strcspn(nome_evento_remover, "\n")] = '\0';
                
                remover_evento(&lista_eventos, nome_evento_remover);
                salvar_eventos_e_times(lista_eventos);
                limpar_tela();
                break;
            }
            case '3': {
                char nome_evento_adicionar_time[50];
                printf("Digite o nome do evento ao qual deseja adicionar um time: ");
                fgets(nome_evento_adicionar_time, sizeof(nome_evento_adicionar_time), stdin);
                nome_evento_adicionar_time[strcspn(nome_evento_adicionar_time, "\n")] = '\0';

                Evento *evento_atual = lista_eventos;
                while (evento_atual != NULL) {
                    if (strcmp(evento_atual->nome, nome_evento_adicionar_time) == 0) {
                        adicionar_time_a_evento(evento_atual);
                        break;
                    }
                    evento_atual = evento_atual->prox;
                }
                
                if (evento_atual == NULL) {
                    printf("Evento \"%s\" não encontrado na lista.\n", nome_evento_adicionar_time);
                }
                salvar_eventos_e_times(lista_eventos);
                limpar_tela();
                break;
            }
            case '4': {
                char nome_evento_remover_time[50];
                printf("Digite o nome do evento do qual deseja remover um time: ");
                fgets(nome_evento_remover_time, sizeof(nome_evento_remover_time), stdin);
                nome_evento_remover_time[strcspn(nome_evento_remover_time, "\n")] = '\0';

                Evento *evento_atual = lista_eventos;
                while (evento_atual != NULL) {
                    if (strcmp(evento_atual->nome, nome_evento_remover_time) == 0) {
                        char nome_time_remover[50];
                        printf("Digite o nome do time que deseja remover do evento \"%s\": ", nome_evento_remover_time);
                        fgets(nome_time_remover, sizeof(nome_time_remover), stdin);
                        nome_time_remover[strcspn(nome_time_remover, "\n")] = '\0';
                        remover_time_de_evento(evento_atual, nome_time_remover);
                        break;
                    }
                    evento_atual = evento_atual->prox;
                }
                if (evento_atual == NULL) {
                    printf("Evento \"%s\" não encontrado na lista.\n", nome_evento_remover_time);
                }
                salvar_eventos_e_times(lista_eventos);
                limpar_tela();
                break;
            }
            case '5':
                imprimir_eventos(lista_eventos);
                limpar_tela();
                break;
            case '6':
                buscar_time_por_nome(lista_eventos);
                limpar_tela();
                break;
            case '7':
                editar_time(lista_eventos);
                salvar_eventos_e_times(lista_eventos);
                limpar_tela();
                break;
            case '8':
                printf("Saindo...\n");
                n = 0;
                break;
        }
    } while (n != 0);

    while (lista_eventos != NULL) {
        Evento *temp = lista_eventos;
        lista_eventos = lista_eventos->prox;
        free(temp);
    }
    
    return 0;
}