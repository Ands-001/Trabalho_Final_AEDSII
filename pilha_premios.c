/*************************************************************************
 * Ficheiro: pilha_premios.c
 * Descrição:
 *   Implementação das funções para a pilha de prêmios
 *   (gibis ou ingressos) usando alocação dinâmica.
 *************************************************************************/

#include "pilha_premios.h"


void inicializarPilhaPremios(PilhaPremios *pilha) {
    pilha->topo = NULL;
    pilha->tamanho = 0;
}


int pilhaPremiosVazia(PilhaPremios *pilha) {
    return (pilha->topo == NULL);
}


int empilharPremio(PilhaPremios *pilha, const char *descricao) {
    // Aloca memória para o novo nó
    NoPremio *novoNo = (NoPremio*) malloc(sizeof(NoPremio));
    if (novoNo == NULL) {
        perror("Erro ao alocar memória para novo prêmio");
        return 0; // Falha na alocação
    }

    // Copia a descrição para o novo nó
    strncpy(novoNo->descricao, descricao, sizeof(novoNo->descricao) - 1);
    novoNo->descricao[sizeof(novoNo->descricao) - 1] = '\0'; // Garante terminação nula
    
    // O próximo do novo nó aponta para o antigo topo
    novoNo->proximo = pilha->topo;
    // O novo nó se torna o novo topo
    pilha->topo = novoNo;
    pilha->tamanho++;

    return 1; // Sucesso
}


int desempilharPremio(PilhaPremios *pilha, char *descricao_removida, size_t tamanho_buffer) {
    if (pilhaPremiosVazia(pilha)) {
        // printf("ERRO: Pilha vazia! Impossível desempilhar.\n\n");
        return 0; // Pilha vazia
    }

    // Nó a ser removido é o topo atual
    NoPremio *noRemovido = pilha->topo;

    // Copia a descrição do prêmio para o buffer
    strncpy(descricao_removida, noRemovido->descricao, tamanho_buffer - 1);
    descricao_removida[tamanho_buffer - 1] = '\0'; // Garante terminação nula

    // Atualiza o topo da pilha para o próximo nó
    pilha->topo = noRemovido->proximo;
    
    // Libera a memória do nó removido
    free(noRemovido);
    pilha->tamanho--;

    return 1; // Sucesso
}


void imprimirPilhaPremios(PilhaPremios *pilha, const char *nome_pilha) {
    printf("--- %s (%d) ---\n\n", nome_pilha, pilha->tamanho);
    if (pilhaPremiosVazia(pilha)) {
        printf("A pilha está vazia.\n\n");
    } else {
        NoPremio *atual = pilha->topo;
        printf("Topo -> [ ");
        while (atual != NULL) {
            printf("%s ", atual->descricao);
            atual = atual->proximo;
            if (atual != NULL) {
                printf("| ");
            }
        }
        printf("] <- Base\n\n");
    }
    printf("--------------------\n\n");
}


void liberarPilhaPremios(PilhaPremios *pilha) {
    NoPremio *atual = pilha->topo;
    NoPremio *proximoNo;

    while (atual != NULL) {
        proximoNo = atual->proximo;
        free(atual);
        atual = proximoNo;
    }

    // Reseta a pilha para o estado inicial
    inicializarPilhaPremios(pilha);
}

