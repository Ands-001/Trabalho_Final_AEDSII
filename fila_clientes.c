#include "fila_clientes.h"
#include <stdio.h>
#include <string.h>

void inicializarFilaClientes(FilaClientes *fila) {
    fila->inicio = 0;
    fila->fim = 0;
    fila->quantidade = 0;
}


int filaClientesVazia(FilaClientes *fila) {
    return (fila->quantidade == 0);
}


int filaClientesCheia(FilaClientes *fila) {
    return (fila->quantidade == TAMANHO_MAX_FILA);
}


int enfileirarCliente(FilaClientes *fila, const char *nome) {
    if (filaClientesCheia(fila)) {
        printf("ERRO: Fila cheia! Impossível inserir '%s'.\n\n", nome);
        return 0; // Fila cheia
    }

    // Copia o nome para a posição 'fim' da fila
    strncpy(fila->nomes[fila->fim], nome, sizeof(fila->nomes[0]) - 1);
    fila->nomes[fila->fim][sizeof(fila->nomes[0]) - 1] = '\0'; // garante o fim da string
    
    // Atualiza o índice 'fim' (circular)
    fila->fim = (fila->fim + 1) % TAMANHO_MAX_FILA;
    fila->quantidade++;
    
    return 1; // Sucesso
}


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

