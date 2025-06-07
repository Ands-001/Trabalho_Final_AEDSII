#include <stdio.h>
#include <stdlib.h>
#include "input_validation.h"

int lerInteiroPositivo(const char *mensagem) {
    int valor;
    int result;
    char linha[100]; 

    do {
        printf("%s", mensagem);
        if (fgets(linha, sizeof(linha), stdin) != NULL) { // Lê a linha inteira
            result = sscanf(linha, "%d", &valor); 

            // Verifica se a leitura foi bem-sucedida e se há caracteres extras na linha
            if (result == 1 && valor >= 0) { 
                char *ptr = linha;
                while (*ptr != ' ' && *ptr != '\t' && *ptr != '\n' && *ptr != '\0') { // Ignora espaços e tabs iniciais
                    ptr++;
                }
                // Avança o ponteiro para o final do número lido
                while (*ptr != '\0' && *ptr >= '0' && *ptr <= '9') {
                    ptr++;
                }
                // Se houver caracteres não numéricos após o número, é uma entrada inválida
                while (*ptr != '\0' && (*ptr == ' ' || *ptr == '\t' || *ptr == '\n')) { // Ignora espaços e tabs finais
                    ptr++;
                }
                if (*ptr != '\0') { // Se ainda houver algo, é inválido
                    result = 0; // Marca como falha na leitura
                }
            } else {
                result = 0; // Marca como falha na leitura se sscanf não leu 1 item ou valor < 0
            }
        }

        if (result != 1 || valor < 0) { // Alterado de valor < 1 para valor < 0
            printf("Por favor, insira um número inteiro positivo ou zero válido.\n");
        }
    } while (result != 1 || valor < 0); // Alterado de valor < 1 para valor < 0

    return valor;
}

