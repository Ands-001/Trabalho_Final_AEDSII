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


void inicializarPilhaPremios(PilhaPremios *pilha);


int pilhaPremiosVazia(PilhaPremios *pilha);


int empilharPremio(PilhaPremios *pilha, const char *descricao);


int desempilharPremio(PilhaPremios *pilha, char *descricao_removida, size_t tamanho_buffer);


void imprimirPilhaPremios(PilhaPremios *pilha, const char *nome_pilha);


void liberarPilhaPremios(PilhaPremios *pilha);

#endif // PILHA_PREMIOS_H

