/*************************************************************************
 * Ficheiro: fila_clientes.h
 * Descrição:
 *   Definição da estrutura de dados para a fila de clientes
 *   (alocação estática) e protótipos das funções.
 *************************************************************************/

#ifndef FILA_CLIENTES_H
#define FILA_CLIENTES_H

#include <stdio.h>
#include <string.h>

// Define o tamanho máximo da fila estática
#define TAMANHO_MAX_FILA 50

// Estrutura da Fila de Clientes (Estática)
typedef struct {
    char nomes[TAMANHO_MAX_FILA][100]; // Array estático para nomes
    int inicio;
    int fim;
    int quantidade;
} FilaClientes;

// Protótipos das Funções

/**
 * @brief Inicializa a fila de clientes.
 * 
 * @param fila Ponteiro para a fila de clientes.
 */
void inicializarFilaClientes(FilaClientes *fila);

/**
 * @brief Verifica se a fila de clientes está vazia.
 * 
 * @param fila Ponteiro para a fila de clientes.
 * @return int 1 se vazia, 0 caso contrário.
 */
int filaClientesVazia(FilaClientes *fila);

/**
 * @brief Verifica se a fila de clientes está cheia.
 * 
 * @param fila Ponteiro para a fila de clientes.
 * @return int 1 se cheia, 0 caso contrário.
 */
int filaClientesCheia(FilaClientes *fila);

/**
 * @brief Insere um cliente no final da fila (enqueue).
 * 
 * @param fila Ponteiro para a fila de clientes.
 * @param nome Nome do cliente a ser inserido.
 * @return int 1 se a inserção foi bem-sucedida, 0 se a fila está cheia.
 */
int enfileirarCliente(FilaClientes *fila, const char *nome);

/**
 * @brief Remove e retorna o cliente do início da fila (dequeue).
 * 
 * @param fila Ponteiro para a fila de clientes.
 * @param nome_removido Buffer para armazenar o nome do cliente removido.
 * @param tamanho_buffer Tamanho do buffer nome_removido.
 * @return int 1 se a remoção foi bem-sucedida, 0 se a fila está vazia.
 */
int desenfileirarCliente(FilaClientes *fila, char *nome_removido, size_t tamanho_buffer);

/**
 * @brief Imprime os clientes na fila.
 * 
 * @param fila Ponteiro para a fila de clientes.
 * @param nome_fila Nome descritivo da fila (ex: "Fila 1").
 */
void imprimirFilaClientes(FilaClientes *fila, const char *nome_fila);

#endif // FILA_CLIENTES_H

