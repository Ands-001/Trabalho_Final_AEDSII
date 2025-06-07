/*************************************************************************
 * Ficheiro: pilha_premios.h
 * Descrição:
 *   Definição da estrutura de dados para a pilha de prêmios
 *   (gibis ou ingressos) usando alocação dinâmica e protótipos
 *   das funções.
 *************************************************************************/

#ifndef PILHA_PREMIOS_H
#define PILHA_PREMIOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do Nó da Pilha de Prêmios
typedef struct NoPremio {
    char descricao[100]; // Descrição do prêmio (ex: "Gibi do Batman #1", "Ingresso Vingadores")
    struct NoPremio *proximo;
} NoPremio;

// Estrutura da Pilha de Prêmios
typedef struct {
    NoPremio *topo;
    int tamanho;
} PilhaPremios;

// Protótipos das Funções

/**
 * @brief Inicializa a pilha de prêmios.
 * 
 * @param pilha Ponteiro para a pilha de prêmios.
 */
void inicializarPilhaPremios(PilhaPremios *pilha);

/**
 * @brief Verifica se a pilha de prêmios está vazia.
 * 
 * @param pilha Ponteiro para a pilha de prêmios.
 * @return int 1 se vazia, 0 caso contrário.
 */
int pilhaPremiosVazia(PilhaPremios *pilha);

/**
 * @brief Empilha um novo prêmio (push).
 * 
 * @param pilha Ponteiro para a pilha de prêmios.
 * @param descricao Descrição do prêmio a ser empilhado.
 * @return int 1 se o empilhamento foi bem-sucedido, 0 caso contrário (erro de alocação).
 */
int empilharPremio(PilhaPremios *pilha, const char *descricao);

/**
 * @brief Desempilha um prêmio (pop) e retorna sua descrição.
 * 
 * @param pilha Ponteiro para a pilha de prêmios.
 * @param descricao_removida Buffer para armazenar a descrição do prêmio removido.
 * @param tamanho_buffer Tamanho do buffer descricao_removida.
 * @return int 1 se o desempilhamento foi bem-sucedido, 0 se a pilha está vazia.
 */
int desempilharPremio(PilhaPremios *pilha, char *descricao_removida, size_t tamanho_buffer);

/**
 * @brief Imprime os prêmios na pilha.
 * 
 * @param pilha Ponteiro para a pilha de prêmios.
 * @param nome_pilha Nome descritivo da pilha (ex: "Pilha de Gibis").
 */
void imprimirPilhaPremios(PilhaPremios *pilha, const char *nome_pilha);

/**
 * @brief Libera toda a memória alocada para a pilha de prêmios.
 * 
 * @param pilha Ponteiro para a pilha de prêmios.
 */
void liberarPilhaPremios(PilhaPremios *pilha);

#endif // PILHA_PREMIOS_H

