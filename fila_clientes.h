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

void inicializarFilaClientes(FilaClientes *fila);


int filaClientesVazia(FilaClientes *fila);


int filaClientesCheia(FilaClientes *fila);


int enfileirarCliente(FilaClientes *fila, const char *nome);


int desenfileirarCliente(FilaClientes *fila, char *nome_removido, size_t tamanho_buffer);


void imprimirFilaClientes(FilaClientes *fila, const char *nome_fila);

#endif // FILA_CLIENTES_H

