#ifndef TMAPA_H_
#define TMAPA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "tPosicao.h"
#include "tTunel.h"


typedef struct tMapa{
    // Número de linhas e número de colunas do mapa, numero de frutas (bônus) do jogo e número máximo de movimentos que podem ser realizados no mapa;
    int nlinhas, nColunas, nFrutasAtual, nMaximoMovimentos; 
    char **grid; // MAtriz que formará o mapa (na tela) do jogo;
    tTunel *tunel; // Túnel do jogo;
}tMapa;


/**
 * @brief Cria (aloca amemória dinamicamente de) um mapa, com seus campos inicializados;
 * 
 * @param camainhoConfig "Caminho" (sequência de diretórios da pasta) onde está localizado o arquivo de entrada;
 * @return tMapa* Ponteiro para a estrutura do tipo "tMapa" que contém os campos de dados do mapa inicializados;
 */
tMapa *CriaMapa(const char* camainhoConfig);

/**
 * @brief Obtém a posição de um item no mapa;
 * 
 * @param mapa Ponteiro pata a estrutura do tipo "tMapa" onde seu mapa será varrido à procura do item solicitado;
 * @param item Item procurado no mapa
 * @return tPosicao* Ponteiro para a estrutura do tipo "tPosicao" que contém os dados da posição do item no mapa;
 * OBS: Caso o item seja encontrado no mapa, cria um ponteiro para uma estrutura do tipo "tPosicao" com os dados da posição do item. Caso o item não seja achado, retorna um ponteiro para NULL;
 */
tPosicao *ObtemPosicaoItemMapa(tMapa *mapa, char item);

/**
 * @brief Obtém o túnel do mapa;
 * 
 * @param mapa Ponteiro para a estrutura do tipo "tMapa" onde seu mapa será procurado o túnel;
 * @return tTunel* Ponteiro para a estrutura do tipo "tTunel" que contém os dados da(s) posição(ões) (entrada e saída) do túnel;
 */
tTunel *ObtemTunelMapa(tMapa *mapa);

/**
 * @brief Obtém um item dentro do mapa;
 * 
 * @param mapa Ponteiro para a estrutura do tipo "tMapa" onde seu mapa será varrido à procura do item solicitado;
 * @param posicao Ponteiro pata a estrutura do tipo "tPosicao" que contém os dados da posição em que o item  será obtido;
 * @return char Item da posição;
 * OBS: Caso a posição esteja fora dos limites de dimensões do mapa, ou o mapa não exista, retorna o caractere de nulo ('\0');
 */
char ObtemItemMapa(tMapa *mapa, tPosicao *posicao);

/**
 * @brief Obtém o número de linhas do mapa;
 * 
 * @param mapa Ponteiro para a estrutura do tipo "tMapa" que contém o número de linhas do mapa e com os dados atualizados do mapa;
 * @return int Número de linhas que o mapa contém;
 */
int ObtemNumeroLinhasMapa(tMapa *mapa);

/**
 * @brief Obtém o número de colunas do mapa;
 * 
 * @param mapa Ponteiro para a estrutura do tipo "tMapa" que contém o número de colunas do mapa e com os dados atualizados do mapa;
 * @return int Número de colunas que o mapa contém;
 */
int ObtemNumeroColunasMapa(tMapa *mapa);

/**
 * @brief Obtém o número inicial de frutas do mapa;
 * 
 * @param mapa Ponteiro para a estrutura do tipo "tMapa" que contém a quantidade inicial de frutas do mapa e com os dados atualizados do mapa;
 * @return int Número inicial de frutas que o mapa contém;
 */
int ObtemQuantidadeFrutasMapa(tMapa *mapa);

/**
 * @brief Obtém o número máximo de movimentos no mapa;
 * 
 * @param mapa Ponteiro para a estrutura do tipo "tMapa" que contém o número máximo de movimentos no mapa e com os dados atualizados do mapa;
 * @return int Número máximo de movimentos que o mapa contém;
 */
int ObtemNumeroMaximoMovimentosMapa(tMapa *mapa);

/**
 * @brief Busca uma comida no mapa;
 * 
 * @param mapa Ponteiro para a estrutura do tipo "tMapa" que pode ou não conter a comida, com seus dados atualizados;
 * @param posicao Ponteiro para a estrutura do tipo "tPosicao" que contém os dados (atualizados) da posição solicitada;
 * @return true Caso haja comida na posição;
 * @return false Caso não haja comida na posição;
 * OBS: Caso a posição esteja fora dos limites de dimensões do mapa, ou o mapa não exista, retorna falso (false);
 */
bool EncontrouComidaMapa(tMapa *mapa, tPosicao *posicao);

/**
 * @brief Verifica se há uma parede na posição;
 * 
 * @param mapa Ponteiro para a estrutura do tipo "tMapa" que pode ou não conter uma parede, com seus dados atualizados;
 * @param posicao Ponteiro para a estrutura do tipo "tPosicao" que contém os dados (atualizados) da posição solicitada;
 * @return true Caso haja parede na posição;
 * @return false Caso não haja parede na posição;
 * OBS: Caso a posição esteja fora dos limites de dimensões do mapa, ou o mapa não exista, retorna falso (false);
 */
bool EncontrouParedeMapa(tMapa *mapa, tPosicao *posicao);

/**
 * @brief Verifica se é possível atualizar uma posição do item (e se possível, o atualiza);
 * 
 * @param mapa Ponteiro para a estrutura do tipo "tMapa" (com seus dados atualizados) que possui um item em uma determinada posição que pode ou não ser atualizada;
 * @param posicao Ponteiro para a estrutura do tipo "tPosicao" que contém os dados (atualizados) da posição solicitada;
 * @param item Item que será atualizado na posição do mapa;
 * @return true Caso seja possível atualizar a posição (com o item);
 * @return false Caso não seja possível atualizar a posição (com o item);
 * OBS: Caso a posição esteja fora dos limites de dimensões do mapa, ou o mapa não exista, retorna falso (false);
 */
bool AtualizaItemMapa(tMapa *mapa, tPosicao *posicao, char item);

/**
 * @brief Verifica se o mapa possui um túnel;
 * 
 * @param mapa Ponteiro para a estrutura do tipo "tMapa" (com seus dados atualizados) do mapa onde será verificado se existe um túnel ou não;
 * @return true Caso o mapa possua um túnel;
 * @return false Caso o mapa não possua um túnel;
 */
bool PossuiTunelMapa(tMapa *mapa);

/**
 * @brief Verifica se o túnel foi acessado;
 * 
 * @param mapa Ponteiro para a estrutura do tipo "tMapa" (com seus dados atualizados) do mapa onde será verificado se o túnel foi acessado ou não;
 * @param posicao Ponteiro para a estrutura do tipo "tPosicao" que contém os dados (atualizados) da posição onde será verificado se houve acesso ao túnel do mapa ou não;
 * @return true Caso o túnel tenha sido acessado;
 * @return false Caso o túnel não tenha sid acessado;
 * OBS: Caso a posição esteja fora dos limites de dimensões do mapa, ou o mapa não exista, retorna falso (false);
 */
bool AcessouTunelMapa(tMapa *mapa, tPosicao *posicao);

/**
 * @brief Permite que o túnel seja acessado;
 * 
 * @param mapa Ponteiro para a estrutura do tipo "tMapa" (com seus dados atualizados) do mapa onde o túnel será acessado;
 * @param posicao Ponteiro para a estrutura do tipo "tPosicao" que contém os dados (atualizados) da posição onde será acessado o túnel do mapa;
 */
void EntraTunelMapa(tMapa *mapa, tPosicao *posicao);

/**
 * @brief Destrói (desaloca a memória alocada dinâmicamente do) mapa;
 * 
 * @param mapa Ponteiro para a estrutura do tipo "tMapa" (com seus dados atualizados) que será destruída (desalocada);
 */
void DesalocaMapa(tMapa *mapa);

#endif