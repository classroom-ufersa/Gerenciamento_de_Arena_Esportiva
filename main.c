#include "./Eventos/evento.c"


int main() {
    Evento *lista_eventos = NULL; // Inicialmente, a lista está vazia
    
    int opcao;
    
    do {
        printf("\nMenu:\n");
        printf("1. Adicionar evento\n");
        printf("2. Remover evento\n");
        printf("3. Adicionar time a um evento\n");
        printf("4. Remover time de um evento\n");
        printf("5. Imprimir eventos\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado
        
        switch (opcao) {
            case 1:
                adicionar_evento(&lista_eventos);
                break;
            case 2: {
                char nome_evento_remover[50];
                printf("Digite o nome do evento que deseja remover: ");
                fgets(nome_evento_remover, 50, stdin);
                nome_evento_remover[strcspn(nome_evento_remover, "\n")] = '\0'; // Remover o '\n' do final da string
                remover_evento(&lista_eventos, nome_evento_remover);
                break;
            }
            case 3: {
                char nome_evento_adicionar_time[50];
                printf("Digite o nome do evento ao qual deseja adicionar um time: ");
                fgets(nome_evento_adicionar_time, 50, stdin);
                nome_evento_adicionar_time[strcspn(nome_evento_adicionar_time, "\n")] = '\0'; // Remover o '\n' do final da string
                
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
                break;
            }
            case 4: {
                char nome_evento_remover_time[50];
                printf("Digite o nome do evento do qual deseja remover um time: ");
                fgets(nome_evento_remover_time, 50, stdin);
                nome_evento_remover_time[strcspn(nome_evento_remover_time, "\n")] = '\0'; // Remover o '\n' do final da string
                
                Evento *evento_atual = lista_eventos;
                while (evento_atual != NULL) {
                    if (strcmp(evento_atual->nome, nome_evento_remover_time) == 0) {
                        char nome_time_remover[50];
                        printf("Digite o nome do time que deseja remover do evento \"%s\": ", nome_evento_remover_time);
                        fgets(nome_time_remover, 50, stdin);
                        nome_time_remover[strcspn(nome_time_remover, "\n")] = '\0'; // Remover o '\n' do final da string
                        remover_time_de_evento(evento_atual, nome_time_remover);
                        break;
                    }
                    evento_atual = evento_atual->prox;
                }
                
                if (evento_atual == NULL) {
                    printf("Evento \"%s\" não encontrado na lista.\n", nome_evento_remover_time);
                }
                break;
            }
            case 5:
                imprimir_eventos(lista_eventos);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);
    
    // Liberar memória alocada para os eventos antes de sair
    while (lista_eventos != NULL) {
        Evento *temp = lista_eventos;
        lista_eventos = lista_eventos->prox;
        free(temp);
    }
    
    return 0;
}