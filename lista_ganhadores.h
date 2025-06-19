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


void inicializarListaGanhadores(ListaGanhadores *lista);


int inserirGanhador(ListaGanhadores *lista, const char *nome);


void imprimirListaGanhadores(ListaGanhadores *lista);


void liberarListaGanhadores(ListaGanhadores *lista);

#endif // LISTA_GANHADORES_H

