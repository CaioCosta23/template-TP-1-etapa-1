#include "tMovimento.h"

tMovimento *CriaMovimento(int numeroDoMovimento, COMANDO comando, const char acao[]) {
    tMovimento *movimento = NULL;

    movimento = (tMovimento*)malloc(sizeof(tMovimento));

    if (movimento == NULL) {
        printf("Erro na alocacao de memoria do movimento ");
        return movimento;
    }

    movimento->numeroDoMovimento = numeroDoMovimento;
    movimento->comando = comando;
    strcpy(movimento->acao, acao);

    return movimento;
}

int ObtemNumeroMovimento(tMovimento *movimento) {
    return (*movimento).numeroDoMovimento;
}

COMANDO ObtemComandoMovimento(tMovimento *movimento) {
    return (*movimento).comando;
}

char *ObtemAcaoMovimento(tMovimento *movimento) {
    return (*movimento).acao;
}

void DesalocaMovimento(tMovimento *movimento) {
    if (movimento != NULL) {
        free(movimento);
        movimento = NULL;
    }
}