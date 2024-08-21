#ifndef TMOVIMENTO_H_
#define TMOVIMENTO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum{
    MOV_ESQUERDA = 0, MOV_CIMA = 1, MOV_BAIXO = 2, MOV_DIREITA = 3
}COMANDO;


typedef struct tMovimento {
    int numeroDoMovimento; // Numero do movimento (em que ocorreu ação significativa);
    COMANDO comando; // Comando de direcionamento de movimento;
    char acao[50]; // Ação siginificativa durante o movimento (pegar comida, colidir com parede ou fim de jogo - encostar no fantasma);
}tMovimento;


/**
 * @brief Cria (aloca a memória dinamicamente de) um movimento;
 * 
 * @param numerodoMovimento Número do movimento;
 * @param comando Comando dado para realizar o movimento;
 * @param acao Ação gerada pelo movimento;
 * @return tMovimento* Ponteiro para a estrutura do tipo "tMovimento" que contém os campos de dados inicializados;
 */
tMovimento *CriaMovimento(int numerodoMovimento, COMANDO comando, const char *acao);

/**
 * @brief Obtém o número do movimento;
 * 
 * @param movimento Ponteiro para a estrutura do tipo "tMovimento" que contém os dados atualizados do movimento;
 * @return int Número do movimento atual;
 */
int ObtemNumeroMovimento(tMovimento *movimento);

/**
 * @brief Obtém o comando do movimento;
 * 
 * @param movimento Ponteiro para a estrutura do tipo "tMovimento" que contém os dados atualizados do movimento;
 * @return COMANDO Comando que realizado no movimento;
 */
COMANDO ObtemComandoMovimento(tMovimento *movimento);

/**
 * @brief Obtém a ação provocada pelo movimento;
 * 
 * @param movimento Ponteiro para a estrutura do tipo "tMovimento" que contém os dados atualizados do movimento;
 * @return char* Ação desencadeada pelo movimento;
 */
char *ObtemAcaoMovimento(tMovimento *movimento);

/**
 * @brief Destrói (desaloca a memória dinamicamente de) um movimento;
 * 
 * @param movimento Ponteiro para a estrutura do tipo "tMovimento" que contém os dados atualizados do movimento que será destruído;
 */
void DesalocaMovimento(tMovimento *movimento);

#endif