#include "cpf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Lista dinâmica para armazenar CPFs
static char **listaCPF = NULL;
static int totalCPF = 0;

// Função para adicionar um CPF à lista
int adicionaCPF(const char *cpf) {                   // Créditos ao GPT (30/11/2024)
    // Verifica se o CPF já existe na lista
    for (int i = 0; i < totalCPF; i++) {
        if (strcmp(listaCPF[i], cpf) == 0) {
            printf("CPF válido, mas o CPF digitado já foi cadastrado\n");
            return 0;
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
    
    return 1;
}

int verificaCPFDuplicado(const char* cpf) {
    FILE* fp = fopen("clientes.txt", "r");
    if (fp == NULL) return 0; // Arquivo não existe, CPF não duplicado

    char linha[256];
    while (fgets(linha, sizeof(linha), fp)) {
        if (strncmp(linha, "| CPF:", 6) == 0) {
            char cpfExistente[15];
            sscanf(linha, "| CPF: %s", cpfExistente);
            if (strcmp(cpfExistente, cpf) == 0) {
                fclose(fp);
                return 1; // CPF duplicado
            }
        }
    }

    fclose(fp);
    return 0; // CPF não duplicado
}

// Função para liberar a memória alocada
void liberaMemoria() {
    for (int i = 0; i < totalCPF; i++) {
        free(listaCPF[i]);
    }
    free(listaCPF);
}
