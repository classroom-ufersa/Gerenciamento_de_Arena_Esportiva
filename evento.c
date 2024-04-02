#include "evento.h"

struct evento
{
   char Nome[20];
   char Tipo[20];
   char Times_Participantes[200];
};

void Criar_Evento(Evento *evento)
{
    printf("Insira o nome do novo evento\n");
    scanf(" %[\n]", evento->Nome);

    printf("Insira o tipo do evento");
    scanf(" %[\n]", evento->Tipo);
}

void Cancelar_Evento(Evento *evento)
{
    printf("Evento \"%s\" do tipo \"%s\" foi cancelado.\n", evento->Nome, evento->Tipo);
}