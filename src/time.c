#include "../include/time.h"

struct times {
    char nome[50];
    char origem[50];
    char tecnico[50];
    int qtd_jogadores;
    struct times *prox;
};

void adicionar_time(Times *novo_time) {
    char qtd_jogadores_str[20];
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
    
    do
    {
        printf("Quantidade de jogadores: ");
        fgets(qtd_jogadores_str, sizeof(qtd_jogadores_str), stdin);
        qtd_jogadores_str[strcspn(qtd_jogadores_str, "\n")] = '\0';

        // Verificar se a entrada contém apenas dígitos
        if (!contem_apenas_digitos(qtd_jogadores_str))
        {
            printf("Entrada inválida. Digite apenas números.\n");
        }
        else
        {
            novo_time->qtd_jogadores = atoi(qtd_jogadores_str);
            break;
        }
    } while (1);
}

Times *adicionar_time_a_lista(Times *atual, Times time)
{

    Times *novo_time = (Times *)malloc(sizeof(Times));

    if (novo_time == NULL)
    {
        printf("Erro ao alocar memória para o novo evento.\n");
        return NULL;
    }

    strcpy(novo_time->nome, time.nome);
    strcpy(novo_time->origem, time.origem);
    strcpy(novo_time->tecnico, time.tecnico);
    novo_time->qtd_jogadores = time.qtd_jogadores;

    novo_time->prox = atual;
    return novo_time;
}

void Exibi_Times(Times *time_atual){
        printf("Detalhes do time:\n");
        printf("- Nome do time: %s\n", time_atual->nome);     
        printf("  Origem: %s\n", time_atual->origem);
        printf("  Técnico: %s\n", time_atual->tecnico);
        printf("  Quantidade de jogadores: %d\n\n", time_atual->qtd_jogadores);
}