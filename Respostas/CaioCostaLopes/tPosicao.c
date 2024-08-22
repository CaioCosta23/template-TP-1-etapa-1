#include "tPosicao.h"

tPosicao *CriaPosicao(int linha, int coluna) {
    tPosicao *posicao = NULL;

    posicao = (tPosicao*)malloc(sizeof(tPosicao));

    if (posicao == NULL) {
        printf("Erro na alocacao de memoria da posicao ");
        return posicao;
    }

    posicao->linha = linha;
    posicao->coluna = coluna;

    return posicao;
}

tPosicao *ClonaPosicao(tPosicao *posicao) {
    tPosicao *posicaoClonada = NULL;

    posicaoClonada = CriaPosicao(ObtemLinhaPosicao(posicao), ObtemColunaPosicao(posicao));
    
    return posicaoClonada;
}

int ObtemLinhaPosicao(tPosicao *posicao) {
    return (*posicao).linha;
}

int ObtemColunaPosicao(tPosicao *posicao) {
    return (*posicao).coluna;
}

void AtualizaPosicao(tPosicao *posicaoAtual, tPosicao *posicaoNova) {
    *posicaoAtual = *posicaoNova;
}

bool SaoIguaisPosicao(tPosicao *posicao1, tPosicao *posicao2) {
    if ((ObtemLinhaPosicao(posicao1) == ObtemLinhaPosicao(posicao2)) && (ObtemColunaPosicao(posicao1) == ObtemColunaPosicao(posicao2))) {
        return true;
    }
    return false;
}

void DesalocaPosicao(tPosicao *posicao) {
    if (posicao != NULL) {
        free(posicao);
        posicao = NULL;
    }
}