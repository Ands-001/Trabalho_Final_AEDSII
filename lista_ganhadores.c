/*************************************************************************
 * Ficheiro: lista_ganhadores.c
 * Descrição:
 *   Implementação das funções para a lista duplamente encadeada
 *   de ganhadores (alocação dinâmica).
 *************************************************************************/

#include "lista_ganhadores.h"

/**
 * @brief Inicializa a lista de ganhadores.
 * 
 * @param lista Ponteiro para a lista de ganhadores.
 */
void inicializarListaGanhadores(ListaGanhadores *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

/**
 * @brief Insere um novo ganhador no final da lista.
 * 
 * @param lista Ponteiro para a lista de ganhadores.
 * @param nome Nome do ganhador a ser inserido.
 * @return int 1 se a inserção foi bem-sucedida, 0 caso contrário (erro de alocação).
 */
int inserirGanhador(ListaGanhadores *lista, const char *nome) {
    // Aloca memória para o novo nó
    NoGanhador *novoNo = (NoGanhador*) malloc(sizeof(NoGanhador));
    if (novoNo == NULL) {
        perror("Erro ao alocar memória para novo ganhador");
        return 0; // Falha na alocação
    }
    
    // Copia o nome para o novo nó
    strncpy(novoNo->nome, nome, sizeof(novoNo->nome) - 1);
    novoNo->nome[sizeof(novoNo->nome) - 1] = '\0'; // Garante terminação nula
    novoNo->proximo = NULL;

    // Se a lista estiver vazia, o novo nó é o início e o fim
    if (lista->inicio == NULL) {
        novoNo->anterior = NULL;
        lista->inicio = novoNo;
        lista->fim = novoNo;
    } else {
        // Insere no final da lista
        novoNo->anterior = lista->fim;
        lista->fim->proximo = novoNo;
        lista->fim = novoNo;
    }

    lista->tamanho++;
    return 1; // Sucesso
}

/**
 * @brief Imprime todos os nomes na lista de ganhadores.
 * 
 * @param lista Ponteiro para a lista de ganhadores.
 */
void imprimirListaGanhadores(ListaGanhadores *lista) {
    printf("--- Lista de Ganhadores (%d) ---\n\n", lista->tamanho);
    if (lista->inicio == NULL) {
        printf("A lista de ganhadores está vazia.\n\n");
        return;
    }

    NoGanhador *atual = lista->inicio;
    int i = 1;
    while (atual != NULL) {
        printf("%d. %s\n\n", i++, atual->nome);
        atual = atual->proximo;
    }
    printf("---------------------------------\n\n");
}

/**
 * @brief Libera toda a memória alocada para a lista de ganhadores.
 * 
 * @param lista Ponteiro para a lista de ganhadores.
 */
void liberarListaGanhadores(ListaGanhadores *lista) {
    NoGanhador *atual = lista->inicio;
    NoGanhador *proximoNo;

    while (atual != NULL) {
        proximoNo = atual->proximo;
        free(atual);
        atual = proximoNo;
    }

    // Reseta a lista para o estado inicial
    inicializarListaGanhadores(lista);
}

