#include "tTunel.h"

tTunel *CriaTunel(int linhaAcesso1, int colunaAcesso1, int linhaAcesso2, int colunaAcesso2) {
    tTunel *tunel = NULL;
    
    tunel = (tTunel*)malloc(sizeof(tTunel));

    /* Verifica se a alocação do túnel em si funcionou. Caso isso não tenha ocorrido, retorna o ponteiro nulo como indicação de
     * que algo de errado ocorreu no programa e que as estruturas mais superiores sejam desalocadas corretamente para
     * que o programa seja encerrado com segurança (ou seja, mesmo sem funcionar, desalocque tudo e dê a mensagem de erro corretamente);
    */
    if (tunel == NULL) {
        printf("Erro na alocacao de memoria do tunel!\n");
        return tunel;
    }

    /* Possui a mesma ideia do código de verificação acima. Porém neste caso, verifica se a locação do acesso ocorreu de forma correta
     * na posição de acesso 1 do túnel. Se a alocação não ocorrer corretamente, desaloca o túnel (imaginando que a alocação do túnel
     * tenha dado certo) e retorna o o ponteiro já desalocado (na mesma idéia do código mais acima);
    */ 
    tunel->acesso1 = CriaPosicao(linhaAcesso1, colunaAcesso1);
    if ((*tunel).acesso1 == NULL) {
        printf("do acesso 1 do tunel!\n");
        DesalocaTunel(tunel);
        return tunel;
    }

    // Realiza a mesma verificação do código acima, mas dessa vez, na posição do acesso 2 do túnel;
    tunel->acesso2 = CriaPosicao(linhaAcesso2, colunaAcesso2);
    if ((*tunel).acesso2 == NULL) {
        printf("do acesso 2 do tunel!\n");
        DesalocaTunel(tunel);
        return tunel;
    }

    return tunel;
}

bool EntrouTunel(tTunel *tunel, tPosicao *posicao) {
    if (((ObtemLinhaPosicao(posicao) == (ObtemLinhaPosicao((*tunel).acesso1))) && (ObtemColunaPosicao(posicao) == (ObtemColunaPosicao((*tunel).acesso1)))) || 
        (((ObtemLinhaPosicao(posicao) == (ObtemLinhaPosicao((*tunel).acesso2)))) && (ObtemColunaPosicao(posicao) == (ObtemColunaPosicao((*tunel).acesso2))))) {
            return true;
    }
    return false;
}

void LevaFinalTunel(tTunel *tunel, tPosicao *posicao) {
    if (((ObtemLinhaPosicao(posicao) == (ObtemLinhaPosicao((*tunel).acesso1))) && (ObtemColunaPosicao(posicao) == (ObtemColunaPosicao((*tunel).acesso1))))) {
        AtualizaPosicao(posicao, (*tunel).acesso2);
    }else {
            if (((ObtemLinhaPosicao(posicao) == (ObtemLinhaPosicao((*tunel).acesso2))) && (ObtemColunaPosicao(posicao) == (ObtemColunaPosicao((*tunel).acesso2))))) {
                AtualizaPosicao(posicao, (*tunel).acesso1);
            }
    }
}

void DesalocaTunel(tTunel *tunel) {
    if (tunel != NULL) {
        if ((*tunel).acesso1 != NULL) {
            DesalocaPosicao((*tunel).acesso1);
        }
        if ((*tunel).acesso2 != NULL) {
            DesalocaPosicao((*tunel).acesso2);
        }
        free(tunel);
        tunel = NULL;
    }
}