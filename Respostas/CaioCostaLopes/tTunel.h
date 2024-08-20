#ifndef TTUNEL_H_
#define TTUNEL_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "tPosicao.h"

typedef struct tTunel {
    tPosicao *acesso1; // Posição do primeiro acesso ao túnel
    tPosicao *acesso2; // Posição do segundo acesso do túnel;
}tTunel;


/**
 * @brief Cria (aloca a memória dinamicamente de) um túnel;
 * 
 * @param linhaAcesso1 Linha da posição do acesso 1;
 * @param colunaAcesso1 Colunaa da posição do acesso 1;
 * @param linhaAcesso2 Linha da posição do acesso 2;
 * @param colunaAcesso2 Colunaa da posição do acesso 2;
 * @return tTunel* Ponteiro para a estrutura do tipo "tTunel" que contém os campos de dados inicializados;
 */
tTunel *CriaTunel(int linhaAcesso1, int colunaAcesso1, int linhaAcesso2, int colunaAcesso2);

/**
 * @brief Verifica se o túnel doi acessado;
 * 
 * @param tunel Ponteiro para a estrutura do tipo "tTunel" que contém os dados atualiazados do túnel;
 * @param posicao Ponteiro para a estrutura do tipo "tPosicao" que contém os dados atualiazados de uma posição;
 * @return true Se o túnel foi acessado;
 * @return false Se o túnel não foi acessado;
 */
bool EntrouTunel(tTunel *tunel, tPosicao *posicao);

/**
 * @brief Atualiza a posição referente a um aceeso do túnel para o outro;
 * 
 * @param tunel Ponteiro para a estrutura do tipo "tTunel" que contém os dados atualiazados do túnel;
 * @param posicao Ponteiro para a estrutura do tipo "tPosicao" que contém os dados atualiazados de uma posição;
 */
void LevaFinalTunel(tTunel *tunel, tPosicao *posicao);

/**
 * @brief Destrói (desaloca a memória dinamicamente de) um túnel;
 * 
 * @param tunel Ponteiro para a estrutura do tipo "tTunel" que contém os dados atualiazados do túnel que será destruído;
 */
void DesalocaTunel(tTunel *tunel);

#endif