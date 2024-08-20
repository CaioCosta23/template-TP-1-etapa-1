#ifndef TPACMAN_H_
#define TPACMAN_H_

#include "tMapa.h"
#include "tPosicao.h"
#include "tMovimento.h"

typedef struct tPacman {
    tPosicao *posicaoAtual; // Posicão (linha, coluna) atual do Pacman;
    int estaVivo; // Estado de vida do Pacman (vivo ou morto);
    /*
     * nMovimentosBaixo: Número de movimentos do Pacman para baixo;
     * nFrutasComidasBaixo: Número de frutas que o pacman comeu em movimentos para baixo;
     * nColisoesParedeBaixo: Número de colisões do Pacman com a parede do mapa em movimentos para baixo;
     * 
     * nMovimentosCima: Número de movimentos do Pacman para cima;
     * nFrutasComidasCima: Número de frutas que o pacman comeu em movimentos para cima;
     * nColisoesParedeCima: Número de colisões do Pacman com a parede do mapa em movimentos para cima;
     * 
     * nMovimentosEsquerda: Número de movimentos do Pacman para esquerda;
     * nFrutasComidasEsquerda: Número de frutas que o pacman comeu em movimentos para esquerda;
     * nColisoesParedeEsquerda: Número de colisões do Pacman com a parede do mapa em movimentos para Esquerda;
     * 
     * nMovimentosDireita: Número de movimentos do Pacman para direita;
     * nFrutasComidasDireita: Número de frutas que o pacman comeu em movimentos para direita;
     * nColisoesParedeDireita: Número de colisões do Pacman com a parede do mapa em movimentos para direita;
     * 
     * nLinhasTrilha: Número de linhas que o Pacman percorreu no jogo (formando sua trilha);
     * nColunasTrilha: Número de colunas que o Pacman percorreu no jogo (formando sua trilha);
     * 
     * nMovimentosSignificativos: Número de movimentos significativos do Pacman;
    */
    int nMovimentosBaixo, nFrutasComidasBaixo, nColisoesBaixo,
        nMovimentosCima, nFrutasComidasCima, nColisoesParedeCima, 
        nMovimentosEsquerda, nFrutasComidasEsquerda, nColisoesParedeEsquerda,
        nMovimentosDireitaa, nFrutasComidasDireita, nColisoesParedeDireita,
        nMovimentosSignificativos,
        nLinhasTrilhas, nColunasTrilha;
    int **trilha; // Trilha (posições que o Pacman percorreu durante o jogo) formada pelo Pacman;
    tMovimento **historicoDeMovimentosSignificativos; // Histórico dos movimentos siginificativos do Pacman;
}tPacman;


/**
 * @brief Cria (aloca a meória dinâmicamente de) um pacman; 
 * 
 * @param posicao Ponteiro para a estrutura do tipo "tPacman" que contém as informações da posição em que o pacman iniciará o jogo;
 * @return tPacman* Ponteiro para a estrutura do tipo "tPacman" que contém os campos de dados do Pacman inicializados;
 */
tPacman *CriaPacman(tPosicao *posicao);

/**
 * @brief Clona o pacman (apenas em relação a sua posição);
 * 
 * @param pacman Ponteiro para a estrutura do tipo "tPacman" que contém os dados atualizados do pacman;
 * @return tPacman* Ponteiro para a estrutura do tipo "tPacman" que contém apenas os dados da posição do pacman;
 */
tPacman *ClonaPacman(tPacman *pacman);

/**
 * @brief Clona (lista do) histórico de movimentos significativos do Pacman;
 * 
 * @param pacma Ponteiro para a estrutura do tipo "tPacman" que contém os dados atualizados do pacman;
 * @return tMovimento** Ponteiro para a lista/vetor (outro ponteiro) de struturas do tipo "tMovimento" que contém os dados dos mobimentos (significativos) do pacman;
 * OBS: Copia (e aloca dinâmicamente) todas as estruturas (a lista e as estruturas individualmente - do tipo "tMovimento")
 *      do histórico de movimentos significativos do Pacman (original, passado como parâmetro);
 */
tMovimento **ClonaHistoricoDeMovimentosSignificativosPacman(tPacman *pacma);

/**
 * @brief Obtém a posição do Pacman;
 * 
 * @param pacman Ponteiro para a estrutura do tipo "tPacman" que contém os dados atualizados do pacman;
 * @return tPosicao* Ponteiro paraa estrutura do tipo "tPosicao" que contém os dados da posição atual do pacman;
 */
tPosicao *ObtemPosicao(tPacman *pacman);

/**
 * @brief Verifica se o pacman ainda está vivo;
 * 
 * @param pacman Ponteiro para a estrutura do tipo "tPacman" que contém os dados atualizados do pacman;
 * @return int 1 se o pacman continua vivo, 0 caso contrário;
 */
int EstaVivoPacman(tPacman *pacman);

/**
 * @brief Função que realiza o movimento do pacman ao longo do jogo no mapa (caso sejá possível);
 * 
 * @param pacman Ponteiro para a estrutura do tipo "tPacman" que contém os dados atualizados do pacman;
 * @param Mapa Ponteiro para a estrutura do tipo "tMapa" que contém os dados atualizados do mapa;
 * @param comando Comando que detemina para qual direção o pacman irá se movimentar;
 */
void MovePacman(tPacman *pacman, tMapa *Mapa, COMANDO comando);

/**
 * @brief Cria (aloca a memória dinamicamente de) uma trilha do pacman no mapa; 
 * 
 * @param tPacman Ponteiro para a estrutura do tipo "tPacman" que contém os dados atualizados do pacman;
 * @param nLinhas Número de linhas da trilha;
 * @param nColunas Número de colunas da trilha
 */
void CriaTrilhaPacman(tPacman *pacman, int nLinhas, int nColunas);

/**
 * @brief Atualiza a trilha (posições por onde o pacman passou);
 * 
 * @param pacman Ponteiro para a estrutura do tipo "tPacman" que contém os dados atualizados do pacman;
 * OBS: Atualiza a trilha na posição em que o pacman realizou o movimento com o número do movimento do mesmo no jogo;
 */
void AtualizaTrilha(tPacman *pacman);

/**
 * @brief Salva a trilha em um arquivo;
 * 
 * @param pacman Ponteiro para a estrutura do tipo "tPacman" que contém os dados atualizados do pacman;
 */
void SalvaTrilhaPacman(tPacman *pacman);

/**
 * @brief Insere na lista de movinmentos siginificativos um novo movimento;
 * 
 * @param pacman Ponteiro para a estrutura do tipo "tPacman" que contém os dados atualizados do pacman;
 * @param comando Comando do movimento que o pacman irá realizar;
 * @param acao Ação que o movimento do pacman provocou;
 */
void InsereNovoMovimentoSignificativoPacman(tPacman *pacman, COMANDO comando, const char *acao);

/**
 * @brief Mata o Pacman (muda seu status de vivo para morto);
 * 
 * @param pacman Ponteiro para a estrutura do tipo "tPacman" que contém os dados atualizados do pacman;
 */
void MataPacman(tPacman *pacman);

/**
 * @brief Obtém o número atual de movimentos realizados pelo pacman no jogo;
 * 
 * @param pacman Ponteiro para a estrutura do tipo "tPacman" que contém os dados atualizados do pacman;
 * @return int Número de movimentos realizados pelo pacman (até o presente momento);
 */
int ObtemNumeroAtualMovimentosPacman(tPacman *pacman);

/**
 * @brief Obtém o número de movimentos que o pacman realizou sem pontuar;
 * 
 * @param pacman Ponteiro para a estrutura do tipo "tPacman" que contém os dados atualizados do pacman;
 * @return int Número de movimentos do pacman sem pontuar;
 */
int ObtemNumeroMovimentosSemPontuarPacman(tPacman *pacman);

/**
 * @brief Obtém o número de vezes que o pacman colidiu com uma parede;
 * 
 * @param pacman Ponteiro para a estrutura do tipo "tPacman" que contém os dados atualizados do pacman;
 * @return int Numero de colisões do pacman com a parede;
 */
int ObtemNumeroColisoesParedePacman(tPacman *pacman);

/**
 * @brief Obtém o número de movimentos que o pacman realizou para baixo;
 * 
 * @param pacman Ponteiro para a estrutura do tipo "tPacman" que contém os dados atualizados do pacman;
 * @return int Número de movimentos para baixo do pacman;
 */
int ObtemNumeroMovimentosBaixoPacman(tPacman *pacman);

/**
 * @brief Obtém o número de frutas que o pacman comeu em movimentos realizados para baixo;
 * 
 * @param pacman Ponteiro para a estrutura do tipo "tPacman" que contém os dados atualizados do pacman;
 * @return int Número de frutas comidas em movimentos direcionados para baixo; 
 */
int ObtemNumeroFrutasComidasBaixoPacman(tPacman *pacman);

/**
 * @brief Obtém o número de colisões do pacman com a parede em movimentos realizado para baixo;
 * 
 * @param pacman Ponteiro para a estrutura do tipo "tPacman" que contém os dados atualizados do pacman;
 * @return int Núemro de colisões em movimentos direcionados para baixo;
 */
int ObtemNumeroColisoesParedeBaixoPacman(tPacman *pacman);

/**
 * @brief Obtém o número de movimentos que o pacman realizou para cima;
 * 
 * @param pacman Ponteiro para a estrutura do tipo "tPacman" que contém os dados atualizados do pacman;
 * @return int Número de movimentos para cima do pacman;
 */
int ObtemNumeroMovimentosCimaPacman(tPacman *pacman);

/**
 * @brief Obtém o número de frutas que o pacman comeu em movimentos realizados para cima;
 * 
 * @param pacman Ponteiro para a estrutura do tipo "tPacman" que contém os dados atualizados do pacman;
 * @return int Número de frutas comidas em movimentos direcionados para cima;
 */
int ObtemNumeroFrutasComidasCimaPacman(tPacman *pacman);

/**
 * @brief Obtém o número de colisões do pacman com a parede em movimentos realizado para cima;
 * 
 * @param pacman Ponteiro para a estrutura do tipo "tPacman" que contém os dados atualizados do pacman;
 * @return int Núemro de colisões em movimentos direcionados para cima;
 */
int ObtemNumeroColisoesParedeCimaPacman(tPacman *pacman);

/**
 * @brief Obtém o número de movimentos que o pacman realizou para esquerda;
 * 
 * @param pacman Ponteiro para a estrutura do tipo "tPacman" que contém os dados atualizados do pacman;
 * @return int Número de movimentos para esquerda do pacman;
 */
int ObtemNumeroMovimentosEsquerdaPacman(tPacman *pacman);

/**
 * @brief Obtém o número de frutas que o pacman comeu em movimentos realizados para esquerda;
 * 
 * @param pacman Ponteiro para a estrutura do tipo "tPacman" que contém os dados atualizados do pacman;
 * @return int Número de frutas comidas em movimentos direcionados para esquerda;
 */
int ObtemNumeroFrutasComidasEsquerdaPacman(tPacman *pacman);

/**
 * @brief Obtém o número de colisões do pacman com a parede em movimentos realizado para esquerda;
 * 
 * @param pacman Ponteiro para a estrutura do tipo "tPacman" que contém os dados atualizados do pacman;
 * @return int Núemro de colisões em movimentos direcionados para esquerda;
 */
int ObtemNumeroColisoesParedeEsquerdaPacman(tPacman *pacman);

/**
 * @brief Obtém o número de movimentos que o pacman realizou para direita;
 * 
 * @param pacman Ponteiro para a estrutura do tipo "tPacman" que contém os dados atualizados do pacman;
 * @return int Número de movimentos para direita do pacman;
 */
int ObtemNumeroMovimentosDireitaPacman(tPacman *pacman);

/**
 * @brief Obtém o número de frutas que o pacman comeu em movimentos realizados para direita;
 * 
 * @param pacman Ponteiro para a estrutura do tipo "tPacman" que contém os dados atualizados do pacman;
 * @return int Número de frutas comidas em movimentos direcionados para direita; 
 */
int ObtemNumeroFrutasComidasDireitaPacman(tPacman *pacman);

/**
 * @brief Obtém o número de colisões do pacman com a parede em movimentos realizado para direita;
 * 
 * @param pacman Ponteiro para a estrutura do tipo "tPacman" que contém os dados atualizados do pacman;
 * @return int Núemro de colisões em movimentos direcionados para direita;
 */
int ObtemNumeroColisoesParedeDireitaPacman(tPacman *pacman);

/**
 * @brief Obtém o número de movimentos siginificativos do pacman no jogo;
 * 
 * @param pacman Ponteiro para a estrutura do tipo "tPacman" que contém os dados atualizados do pacman;
 * @return int Número de movimentos siginificativos realizados pelo pacman (até o presente momento no jogo);
 */
int ObtemNumeroMovimentosSiginificativosPacman(tPacman *pacman);

/**
 * @brief Obtém a pontuação do pacman no jogo;
 * 
 * @param pacman Ponteiro para a estrutura do tipo "tPacman" que contém os dados atualizados do pacman;
 * @return int Pontuação atual do pacman no jogo;
 */
int ObtemPontuacaoAtualPacman(tPacman *pacman);

/**
 * @brief Destrói (desaloca a memória alocada dinâmicamente do) pacman;
 * 
 * @param pacman Ponteiro para a estrutura do tipo "tPacman" que contém os dados atualizados do pacman que será destruído;
 */
void DesalocaPacman(tPacman *pacman);

#endif