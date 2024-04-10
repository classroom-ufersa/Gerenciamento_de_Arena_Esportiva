#include "funcao.h"


void limpar_tela() {
    printf("Pressione ENTER para limpar a tela...");
    getchar();
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}