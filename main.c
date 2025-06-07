/*************************************************************************
 * Ficheiro: main.c
 * Descrição:
 *   Programa principal para simular a distribuição de prêmios
 *   em um shopping center, utilizando listas, filas e pilhas.
 *   Inclui testes exaustivos das estruturas de dados.
 *************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "lista_ganhadores.h"
#include "fila_clientes.h"
#include "pilha_premios.h"
#include "input_validation.h" // Inclui o novo arquivo de cabeçalho


// Função auxiliar para imprimir cabeçalho do log
void imprimirCabecalhoLog() {
    printf("=======================================================================\n\n");
    printf("Inicio da execução: Simulacao Shopping Center - Distribuicao de Premios\n\n");
    printf("Implementacao: Listas, Filas e Pilhas em C\n\n");
    printf("=======================================================================\n\n");
}

// Função auxiliar para imprimir rodapé do log
void imprimirRodapeLog() {
    printf("\n\n=======================================================================\n\n");
    printf("Fim da execução.\n\n");
    printf("=======================================================================\n\n");
}

int main() {

    // Configurações iniciais
    SetConsoleOutputCP(CP_UTF8);


    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    imprimirCabecalhoLog();

    // --- Inicialização das Estruturas ---
    printf("*** Inicializando Estruturas ***\n\n");
    FilaClientes fila1, fila2;
    PilhaPremios pilhaGibis, pilhaIngressos;
    ListaGanhadores listaGanhadores;

    inicializarFilaClientes(&fila1);
    inicializarFilaClientes(&fila2);
    printf("Filas de clientes inicializadas (Estaticas, max: %d).\n\n", TAMANHO_MAX_FILA);
    imprimirFilaClientes(&fila1, "Fila 1");
    imprimirFilaClientes(&fila2, "Fila 2");

    inicializarPilhaPremios(&pilhaGibis);
    inicializarPilhaPremios(&pilhaIngressos);
    printf("Pilhas de prêmios inicializadas (Dinamicas).\n\n");
    imprimirPilhaPremios(&pilhaGibis, "Pilha de Gibis");
    imprimirPilhaPremios(&pilhaIngressos, "Pilha de Ingressos");

    inicializarListaGanhadores(&listaGanhadores);
    printf("Lista de ganhadores inicializada (Duplamente Encadeada, Dinamica).\n\n");
    imprimirListaGanhadores(&listaGanhadores);
    printf("\n\n*** Fim da Inicialização ***\n\n");

    // --- Populando Estruturas para Teste ---
    printf("*** Populando Estruturas para Teste ***\n\n");
    // Populando Filas
    printf("Populando Filas de Clientes...\n\n");

    // implemetar inclusão de usuários
    int qntUser;
    // int result; // Removido, pois a função lerInteiroPositivo já faz a validação

    // Substituído o do-while pela chamada da função de validação
    qntUser = lerInteiroPositivo("Indique a quantidade de usuários: ");

    
    while(qntUser>0){

        char nome[50];
        
        if(qntUser %2 == 0){
            scanf("%s", nome);
            enfileirarCliente(&fila2, nome);
        }else{
            scanf("%s", nome);
            enfileirarCliente(&fila1, nome);
        }
        qntUser--;
    }
    //

    imprimirFilaClientes(&fila1, "Fila 1");
    imprimirFilaClientes(&fila2, "Fila 2");

    // Populando Pilhas
    printf("\n\nPopulando Pilhas de Prêmios...\n\n");
    
    // implemetar inclusão de gibis e ingressos nas pilhas
    int qntGibis, qntIngressos;
    char nomeGibis[100], nomeIngressos[100];

    // Entrada da quantidade de gibis
    // Substituído o do-while pela chamada da função de validação
    qntGibis = lerInteiroPositivo("Indique a quantidade de Gibis: ");

    for(int i = 0; i < qntGibis; i++) {
        printf("Indique o nome do gibi: ");
        fgets(nomeGibis, sizeof(nomeGibis), stdin);
        nomeGibis[strcspn(nomeGibis, "\n\n")] = '\0'; // remove o '\n\n'
        empilharPremio(&pilhaGibis, nomeGibis);
    }

    // Substituído o do-while pela chamada da função de validação
    qntIngressos = lerInteiroPositivo("Indique a quantidade de Ingressos: ");

    for(int i = 0; i < qntIngressos; i++) {
        printf("Indique o nome do ingresso: ");
        fgets(nomeIngressos, sizeof(nomeIngressos), stdin);
        nomeIngressos[strcspn(nomeIngressos, "\n\n")] = '\0'; // remove o '\n\n'
        empilharPremio(&pilhaIngressos, nomeIngressos);
    }

    imprimirPilhaPremios(&pilhaGibis, "Pilha de Gibis");
    imprimirPilhaPremios(&pilhaIngressos, "Pilha de Ingressos");

    // --- Simulação da Distribuição de Prêmios ---
    printf("*** Iniciando Simulação da Distribuição ***\n\n");
    int contador_passos = 0;
    // Continua enquanto houver clientes nas filas e prêmios nas pilhas
    while ((!filaClientesVazia(&fila1) || !filaClientesVazia(&fila2)) && 
           (!pilhaPremiosVazia(&pilhaGibis) || !pilhaPremiosVazia(&pilhaIngressos))) {
        
        contador_passos++;
        printf("\n\n--- Passo %d da Simulacao ---\n\n", contador_passos);

        // Escolhe aleatoriamente uma fila (0 para fila1, 1 para fila2)
        int fila_escolhida = rand() % 2;
        FilaClientes *fila_atual = (fila_escolhida == 0) ? &fila1 : &fila2;
        const char *nome_fila_atual = (fila_escolhida == 0) ? "Fila 1" : "Fila 2";

        printf("Tentando atender cliente da %s...\n\n", nome_fila_atual);

        char nome_cliente[100];
        if (desenfileirarCliente(fila_atual, nome_cliente, sizeof(nome_cliente))) {
            printf("Cliente '%s' removido da %s.\n\n", nome_cliente, nome_fila_atual);

            // Escolhe aleatoriamente um tipo de prêmio (0 para gibi, 1 para ingresso)
            int tipo_premio = rand() % 2;
            PilhaPremios *pilha_premio_atual = (tipo_premio == 0) ? &pilhaGibis : &pilhaIngressos;
            const char *nome_pilha_premio = (tipo_premio == 0) ? "Pilha de Gibis" : "Pilha de Ingressos";
            const char *tipo_premio_str = (tipo_premio == 0) ? "gibi" : "ingresso";

            printf("Cliente '%s' escolheu %s. Verificando %s...\n\n", nome_cliente, tipo_premio_str, nome_pilha_premio);

            char descricao_premio[100];
            if (desempilharPremio(pilha_premio_atual, descricao_premio, sizeof(descricao_premio))) {
                printf("Prêmio '%s' removido da %s.\n\n", descricao_premio, nome_pilha_premio);
                printf("Cliente '%s' ganhou '%s'!\n\n", nome_cliente, descricao_premio);
                
                // Insere na lista de ganhadores
                if (inserirGanhador(&listaGanhadores, nome_cliente)) {
                    printf("Cliente '%s' adicionado à lista de ganhadores.\n\n", nome_cliente);
                } else {
                    printf("ERRO: Falha ao adicionar '%s' à lista de ganhadores!\n\n", nome_cliente);
                }
            } else {
                printf("ERRO: %s vazia! Cliente '%s' não ganhou o prêmio desejado (%s).\n\n", 
                       nome_pilha_premio, nome_cliente, tipo_premio_str);
            }
        } else {
            printf("ERRO: %s vazia! Nenhum cliente para atender.\n\n", nome_fila_atual);
            // Tenta a outra fila se esta estiver vazia
            fila_atual = (fila_escolhida == 0) ? &fila2 : &fila1;
            nome_fila_atual = (fila_escolhida == 0) ? "Fila 2" : "Fila 1";
            if (!filaClientesVazia(fila_atual)) {
                 printf("Tentando atender cliente da %s...\n\n", nome_fila_atual);
                 // Repete a lógica de atendimento para a outra fila...
            }
        }

        // Imprime estado atual das estruturas periodicamente ou a cada passo
        imprimirFilaClientes(&fila1, "Fila 1");
        imprimirFilaClientes(&fila2, "Fila 2");
        imprimirPilhaPremios(&pilhaGibis, "Pilha de Gibis");
        imprimirPilhaPremios(&pilhaIngressos, "Pilha de Ingressos");
        imprimirListaGanhadores(&listaGanhadores); // Imprime lista de ganhadores a cada passo


        // Condição de parada adicional (evitar loop infinito em casos não previstos)
        if (contador_passos > (TAMANHO_MAX_FILA * 2)) { // Limite arbitrário
             printf("\n\nAVISO: Limite de passos da simulação atingido. Interrompendo.\n\n");
             break;
        }
    }
    printf("*** Fim da Simulação ***\n\n");
    printf("Motivo: Filas ou Pilhas esgotadas.\n\n");

    // // --- Testes Adicionais ---
    // printf("\n\n*** Iniciando Testes  Adicionais ***\n\n");

    // // Teste: Tentar remover de filas vazias
    // printf("\n\nTeste: Remover de Fila 1 (Vazia? %s)...\n\n", filaClientesVazia(&fila1) ? "Sim" : "Nao");
    // char temp_nome[100];
    // if (!desenfileirarCliente(&fila1, temp_nome, sizeof(temp_nome))) {
    //     printf("SUCESSO NO TESTE: Impossível remover da Fila 1 (vazia).\n\n");
    // }
    // printf("Teste: Remover de Fila 2 (Vazia? %s)...\n\n", filaClientesVazia(&fila2) ? "Sim" : "Nao");
    // if (!desenfileirarCliente(&fila2, temp_nome, sizeof(temp_nome))) {
    //     printf("SUCESSO NO TESTE: Impossível remover da Fila 2 (vazia).\n\n");
    // }

    // // Teste: Tentar remover de pilhas vazias
    // printf("\n\nTeste: Desempilhar Gibi (Vazia? %s)...\n\n", pilhaPremiosVazia(&pilhaGibis) ? "Sim" : "Nao");
    // char temp_premio[100];
    // if (!desempilharPremio(&pilhaGibis, temp_premio, sizeof(temp_premio))) {
    //     printf("SUCESSO NO TESTE: Impossível desempilhar da Pilha de Gibis (vazia).\n\n");
    // }
    //  printf("Teste: Desempilhar Ingresso (Vazia? %s)...\n\n", pilhaPremiosVazia(&pilhaIngressos) ? "Sim" : "Nao");
    // if (!desempilharPremio(&pilhaIngressos, temp_premio, sizeof(temp_premio))) {
    //     printf("SUCESSO NO TESTE: Impossível desempilhar da Pilha de Ingressos (vazia).\n\n");
    // }

    // // Teste: Encher uma fila e tentar inserir mais
    // printf("\n\nTeste: Encher Fila 1 e tentar inserir extra...\n\n");
    // inicializarFilaClientes(&fila1); // Limpa a fila para o teste
    // int i;
    // for (i = 0; i < TAMANHO_MAX_FILA; i++) {
    //     char nome_teste[20];
    //     sprintf(nome_teste, "Cliente_%d", i + 1);
    //     if (!enfileirarCliente(&fila1, nome_teste)) {
    //          printf("ERRO INESPERADO: Falha ao enfileirar na fila ainda não cheia!\n\n");
    //          break;
    //     }
    // }
    // printf("Fila 1 após enchimento:\n\n");
    // imprimirFilaClientes(&fila1, "Fila 1");
    // printf("Tentando inserir 'Cliente Extra' na Fila 1 cheia...\n\n");
    // if (!enfileirarCliente(&fila1, "Cliente Extra")) {
    //     printf("SUCESSO NO TESTE: Impossível inserir 'Cliente Extra', Fila 1 cheia!\n\n");
    // }

    // // Imprimir lista final de ganhadores
    // printf("\n\n*** Lista Final de Ganhadores ***\n\n");
    // imprimirListaGanhadores(&listaGanhadores);

    // printf("*** Fim dos Testes Exaustivos ***\n\n");

    // // --- Liberação de Memória ---
    // printf("\n\n*** Liberando Memória Alocada ***\n\n");
    // liberarListaGanhadores(&listaGanhadores);
    // printf("Memória da Lista de Ganhadores liberada.\n\n");
    // liberarPilhaPremios(&pilhaGibis);
    // printf("Memória da Pilha de Gibis liberada.\n\n");
    // liberarPilhaPremios(&pilhaIngressos);
    // printf("Memória da Pilha de Ingressos liberada.\n\n");
    // printf("*** Fim da Liberação de Memória ***\n\n");

    imprimirRodapeLog();

    return 0;
}

