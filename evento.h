#include<stdio.h>
#include<stdlib.h>

#ifndef EVENTO_C
#define EVENTO_C

typedef struct evento Evento;

void Criar_Evento(Evento *evento);
void Cancelar_Evento(Evento *evento);


#endif