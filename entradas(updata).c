#include <stdio.h>
#include <stdlib.h>  // Inclusão da biblioteca para manipulação de memória dinâmica.
#include <string.h>  // Inclusão da biblioteca para manipulação de strings.
#include "entradas.h"

// Função para ler entradas longas (ex.: nome, e-mail) e alocar memória dinamicamente
void leEntradaMax(char **entrada) {
    char buffer[256];
    int tam;

    // Lê a entrada do usuário
    scanf("%255[^\n]", buffer);
    getchar();

    // Aloca memória para a entrada com base no tamanho lido
    tam = strlen(buffer);
    *entrada = (char*) malloc(tam + 1);

    // Copia a string para a memória alocada
    strcpy(*entrada, buffer);
}

// Função para ler entradas curtas (ex.: data, telefone) e alocar memória dinamicamente
void leEntradaMin(char **entrada) {
    char buffer[16];
    int tam;

    scanf("%15[^\n]", buffer);
    getchar();

    tam = strlen(buffer);
    *entrada = (char*) malloc(tam + 1);
    strcpy(*entrada, buffer);
}

// Funções para Cliente                                              (Ainda é necessário evitar esta redundância com cliente, funcionário e queijo)
void leNomeCliente(Cliente *cliente) {
  leEntradaMax(&cliente->nome);  // Passa o ponteiro para o nome
}

void leCpfCliente(Cliente *cliente) {
    scanf("%11s", cliente->cpf);  // Acessa diretamente cliente->cpf
    getchar();
}

void leEmailCliente(Cliente *cliente) {
    leEntradaMax(&cliente->email);  // Passa o ponteiro para o email
}

void leDataCliente(Cliente *cliente) {
    leEntradaMin(&cliente->data);  // Passa o ponteiro para a data
}


void leFoneCliente(Cliente *cliente) {
    leEntradaMin(&cliente->fone);  // Passa o ponteiro para o telefone
}

// Funções para Funcionario
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
