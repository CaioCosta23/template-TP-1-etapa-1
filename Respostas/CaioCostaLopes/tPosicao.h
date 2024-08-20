#ifndef TPOSICAO_H_
#define TPOSICAO_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tPosicao {
    int linha; // Linha da posição;
    int coluna; // Coluna da posição;
}tPosicao;

/**
 * @brief Cria (aloca a memória dinamicamente de) uma posição;
 * 
 * @param linha Número da linha da posição;
 * @param coluna Número da coluna da posição
 * @return tPosicao* Ponteiro para a estrutura do tipo "tPosicao" que contém os campos de dados da posição inicializados
 */
tPosicao *CriaPosicao(int linha, int coluna);

/**
 * @brief Clona uma posição;
 * 
 * @param posicao Ponteiro para a estrutura do tipo "tPosicao" com seus dados atualizados;
 * @return tPosicao* Ponteiro para a estrutura do tipo "tPosicao" copiado da posição original (passada como parÂmetro para a função); 
 */
tPosicao *ClonaPosicao(tPosicao *posicao);

/**
 * @brief Obtém o número da linha da posição;
 * 
 * @param posicao Ponteiro para a estrutura do tipo "tPosicao" com seus dados atualizados;
 * @return int Linha da posição;
 */
int ObtemLinhaPosicao(tPosicao *posicao);

/**
 * @brief Obtém o número da coluna da posição;
 * 
 * @param posicao Ponteiro para a estrutura do tipo "tPosicao" com seus dados atualizados;
 * @return int Coluna da posição;
 */
int ObtemColunaPosicao(tPosicao *posicao);

/**
 * @brief Atualiza (os dados de) uma posição;
 * 
 * @param posicao Ponteiro para a estrutura do tipo "tPosicao" com seus dados atualizados;
 */
void AtualizaPosicao(tPosicao *posicao);

/**
 * @brief Verifica seduas posições são iguais;
 * 
 * @param posicao1 Ponteiro para a estrutura do tipo "tPosicao" da posição 1, com seus dados atualizados;
 * @param posicao2 Ponteiro para a estrutura do tipo "tPosicao" da posição 2, com seus dados atualizados; 
 * @return true Caso as duas posições sejam iguais;
 * @return false Caso as duas posições não sejam iguais;
 */
bool SaoIguaisPosicao(tPosicao *posicao1, tPosicao *posicao2);

/**
 * @brief Destrói (desaloca a memória dinamicamente de) uma posição;
 * 
 * @param posicao Ponteiro para a estrutura do tipo "tPosicao" que será destruída com seus dados atualizados;
 */
void DesalocaPosicao(tPosicao *posicao);

#endif