#ifndef CPF_H
#define CPF_H

// Função para adicionar um CPF à lista
int adicionaCPF(const char *cpf);

int verificaCPFDuplicado(const char* cpf);

// Função para liberar a memória alocada para os CPFs
void liberaMemoria();

#endif // CPF_H
