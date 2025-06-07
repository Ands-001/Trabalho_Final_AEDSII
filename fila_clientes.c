/*************************************************************************
 * Ficheiro: fila_clientes.c
 * Descrição:
 *   Implementação das funções para a fila de clientes
 *   (alocação estática).
 *************************************************************************/

#include "fila_clientes.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief Inicializa a fila de clientes.
 * 
 * @param fila Ponteiro para a fila de clientes.
 */
void inicializarFilaClientes(FilaClientes *fila) {
    fila->inicio = 0;
    fila->fim = 0;
    fila->quantidade = 0;
}

/**
 * @brief Verifica se a fila de clientes está vazia.
 * 
 * @param fila Ponteiro para a fila de clientes.
 * @return int 1 se vazia, 0 caso contrário.
 */
int filaClientesVazia(FilaClientes *fila) {
    return (fila->quantidade == 0);
}

/**
 * @brief Verifica se a fila de clientes está cheia.
 * 
 * @param fila Ponteiro para a fila de clientes.
 * @return int 1 se cheia, 0 caso contrário.
 */
int filaClientesCheia(FilaClientes *fila) {
    return (fila->quantidade == TAMANHO_MAX_FILA);
}

/**
 * @brief Insere um cliente no final da fila (enqueue).
 * 
 * @param fila Ponteiro para a fila de clientes.
 * @param nome Nome do cliente a ser inserido.
 * @return int 1 se a inserção foi bem-sucedida, 0 se a fila está cheia.
 */
int enfileirarCliente(FilaClientes *fila, const char *nome) {
    if (filaClientesCheia(fila)) {
        printf("ERRO: Fila cheia! Impossível inserir '%s'.\n\n", nome);
        return 0; // Fila cheia
    }

    // Copia o nome para a posição 'fim' da fila
    strncpy(fila->nomes[fila->fim], nome, sizeof(fila->nomes[0]) - 1);
    fila->nomes[fila->fim][sizeof(fila->nomes[0]) - 1] = '\0'; // Garante terminação nula
    
    // Atualiza o índice 'fim' (circular)
    fila->fim = (fila->fim + 1) % TAMANHO_MAX_FILA;
    fila->quantidade++;
    
    return 1; // Sucesso
}

/**
 * @brief Remove e retorna o cliente do início da fila (dequeue).
 * 
 * @param fila Ponteiro para a fila de clientes.
 * @param nome_removido Buffer para armazenar o nome do cliente removido.
 * @param tamanho_buffer Tamanho do buffer nome_removido.
 * @return int 1 se a remoção foi bem-sucedida, 0 se a fila está vazia.
 */
int desenfileirarCliente(FilaClientes *fila, char *nome_removido, size_t tamanho_buffer) {
    if (filaClientesVazia(fila)) {
        printf("ERRO: Fila vazia! Impossível remover.\n\n");
        return 0; // Fila vazia
    }

    // Copia o nome do cliente do início da fila para o buffer
    strncpy(nome_removido, fila->nomes[fila->inicio], tamanho_buffer - 1);
    nome_removido[tamanho_buffer - 1] = '\0'; // Garante terminação nula

    // Atualiza o índice 'inicio' (circular)
    fila->inicio = (fila->inicio + 1) % TAMANHO_MAX_FILA;
    fila->quantidade--;

    return 1; // Sucesso
}

/**
 * @brief Imprime os clientes na fila.
 * 
 * @param fila Ponteiro para a fila de clientes.
 * @param nome_fila Nome descritivo da fila (ex: "Fila 1").
 */
void imprimirFilaClientes(FilaClientes *fila, const char *nome_fila) {
    printf("\n--- %s (%d/%d) ---\n\n", nome_fila, fila->quantidade, TAMANHO_MAX_FILA);
    if (filaClientesVazia(fila)) {
        printf("A fila está vazia.\n\n");
    } else {
        int i = fila->inicio;
        int count = 0;
        printf("Inicio -> [ ");
        while(count < fila->quantidade) {
            printf("%s ", fila->nomes[i]);
            i = (i + 1) % TAMANHO_MAX_FILA;
            count++;
            if (count < fila->quantidade) {
                printf("| ");
            }
        }
        printf("] <- Fim\n\n");
    }
    printf("------------------------\n\n");
}

