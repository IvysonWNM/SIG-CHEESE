#include "cpf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Lista dinâmica para armazenar CPFs
static char **listaCPF = NULL;
static int totalCPF = 0;

// Função para adicionar um CPF à lista
void adicionaCPF(const char *cpf) {                   // Créditos ao GPT (30/11/2024)
    // Verifica se o CPF já existe na lista
    for (int i = 0; i < totalCPF; i++) {
        if (strcmp(listaCPF[i], cpf) == 0) {
            printf("CPF digitado já foi cadastrado\n");
            return;
        }
    }

// Realoca a memória para adicionar um novo CPF na lista
   char **temp = realloc(listaCPF, (totalCPF + 1) * sizeof(char *));
    if (temp == NULL) {
        perror("Erro ao alocar memória");
        exit(1);
    }
    listaCPF = temp;  // Atualiza a listaCPF com o novo bloco de memória
  
// Aloca memória suficiente para armazenar o CPF
    listaCPF[totalCPF] = malloc((strlen(cpf) + 1) * sizeof(char));
    if (listaCPF[totalCPF] == NULL) {
        perror("Erro ao alocar memória para CPF");
        exit(1);
    }
  
// Copia o CPF para a posição correspondente e incrementa o contador
    strcpy(listaCPF[totalCPF], cpf);
    totalCPF++;
}

// Função para liberar a memória alocada
void liberaMemoria() {
    for (int i = 0; i < totalCPF; i++) {
        free(listaCPF[i]);
    }
    free(listaCPF);
}
