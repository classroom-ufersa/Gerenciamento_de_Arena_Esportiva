#include "gerenciamento.h"

struct times{
    char nome[20];
    char pais[20];
    char tecnico[20];
    int quant_jogador;
};

struct evento{
    char nome[20];
    char tipo[20];
    Times time;
};

void criar_evento(Evento *evento){

    printf("Qual o nome do evento?\n");
    scanf(" %[\n]", evento->nome);

    printf("Qual o tipo do evento?\n");
    scanf(" %[\n]", evento->tipo);
}