/*************************************************************************
 * Ficheiro: lista_ganhadores.h
 * Descrição:
 *   Definição da estrutura de dados para a lista duplamente encadeada
 *   de ganhadores (alocação dinâmica) e protótipos das funções.
 *************************************************************************/

#ifndef LISTA_GANHADORES_H
#define LISTA_GANHADORES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do Nó da Lista de Ganhadores
typedef struct NoGanhador {
    char nome[100]; // Nome do ganhador
    struct NoGanhador *anterior;
    struct NoGanhador *proximo;
} NoGanhador;

// Estrutura da Lista de Ganhadores
typedef struct {
    NoGanhador *inicio;
    NoGanhador *fim;
    int tamanho;
} ListaGanhadores;

// Protótipos das Funções

/**
 * @brief Inicializa a lista de ganhadores.
 * 
 * @param lista Ponteiro para a lista de ganhadores.
 */
void inicializarListaGanhadores(ListaGanhadores *lista);

/**
 * @brief Insere um novo ganhador no final da lista.
 * 
 * @param lista Ponteiro para a lista de ganhadores.
 * @param nome Nome do ganhador a ser inserido.
 * @return int 1 se a inserção foi bem-sucedida, 0 caso contrário (erro de alocação).
 */
int inserirGanhador(ListaGanhadores *lista, const char *nome);

/**
 * @brief Imprime todos os nomes na lista de ganhadores.
 * 
 * @param lista Ponteiro para a lista de ganhadores.
 */
void imprimirListaGanhadores(ListaGanhadores *lista);

/**
 * @brief Libera toda a memória alocada para a lista de ganhadores.
 * 
 * @param lista Ponteiro para a lista de ganhadores.
 */
void liberarListaGanhadores(ListaGanhadores *lista);

#endif // LISTA_GANHADORES_H

