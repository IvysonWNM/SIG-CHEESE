#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entradas.h"

// Função geral para leitura de entradas
void leEntrada(char **entrada, size_t tamanho) {
    char buffer[tamanho];
    fgets(buffer, tamanho, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';  // Remove o \n no final da string

    if (*entrada != NULL) {
        free(*entrada);  // Libera memória previamente alocada
    }

    *entrada = (char*) malloc(strlen(buffer) + 1);
    if (*entrada == NULL) {
        perror("Erro ao alocar memória");
        exit(1);  // Sai caso a alocação falhe
    }

    strcpy(*entrada, buffer);  // Copia o buffer para o ponteiro
}


// Funções específicas para Cliente, agora sem a necessidade de funções MAX/MIN               (Ainda é necessário evitar esta redundância com cliente, funcionário e queijo)
void leNomeCliente(Cliente *cliente) {
    leEntrada(cliente->nome, 52);  // Passa o ponteiro para o nome
    printf("Nome lido: '%s'\n", cliente->nome);
}

void leCpfCliente(Cliente *cliente) {
    leEntrada(&(cliente->cpf), TAM_CPF);
}

void leEmailCliente(Cliente *cliente) {
    leEntrada(cliente->email, 258);  // Passa o ponteiro para o email
}

void leDataCliente(Cliente *cliente) {
    leEntrada(cliente->data, 15);  // Passa o ponteiro para a data
}


void leFoneCliente(Cliente *cliente) {
    leEntrada(cliente->fone, 15);  // Passa o ponteiro para o telefone
}

// Funções para Funcionario

// Funções específicas para diferentes tamanhos
void leEntradaMax(char **entrada) {
    leEntrada(entrada, 256);
}

void leEntradaMin(char **entrada) {
    leEntrada(entrada, 16);
}


void leNomeFuncionario(Funcionario *funcionario) {
  leEntradaMax(&funcionario->nome);  // Passa o ponteiro para o nome
}

void leCpfFuncionario(Funcionario *funcionario) {
    scanf("%11s", funcionario->cpf);  // Acessa diretamente funcionario->cpf
    getchar();
}

void leEmailFuncionario(Funcionario *funcionario) {
    leEntradaMax(&funcionario->email);  // Passa o ponteiro para o email
}

void leDataFuncionario(Funcionario *funcionario) {
    leEntradaMin(&funcionario->data);  // Passa o ponteiro para a data
}

void leFoneFuncionario(Funcionario *funcionario) {
    leEntradaMin(&funcionario->fone);  // Passa o ponteiro para o telefone
}

// Funções para Queijo
void leNomeQueijo(Queijo *queijo) {
  leEntradaMax(&queijo->nome);  // Passa o ponteiro para o nome
}

void leDataFabricacao(Queijo *queijo) {
    leEntradaMin(&queijo->data_fabricacao);  // Passa o ponteiro para a data
}

void leDataValidade(Queijo *queijo) {
    leEntradaMin(&queijo->data_validade);  // Passa o ponteiro para a data
}


void leCodigo(Queijo *queijo) {
    scanf("%6s", queijo->codigo); //Acessa diretamente queijo->codigo
    getchar();
}

void leComposicao(Queijo *queijo) {
    leEntradaMax(&queijo->comp); // Passa o ponteiro para a composição/ingrediente
}

void leTipoLeite(Queijo *queijo) {
    leEntradaMin(&queijo->tipo); // Passa o ponteiro para a tipo
}
