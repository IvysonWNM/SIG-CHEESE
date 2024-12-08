#include <stdio.h> 
#include <stdlib.h>
#include <string.h>           // Para usar o strcpy
#include "cliente.h"
#include "entradas.h"
#include "validacao.h"

void menu_cliente(void) {
    char op;
    do {
        system("clear||cls");
        printf("\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("|                        * * * Módulo Cliente * * *                         |\n");
        printf("|                                                                           |\n");
        printf("|-> 1. Cadastrar um novo cliente                                            |\n");
        printf("|-> 2. Pesquisar os dados de um cliente                                     |\n");
        printf("|-> 3. Atualizar os dados de um cliente                                     |\n");
        printf("|-> 4. Excluir um cliente do sistema                                        |\n");
        printf("|-> 0. Voltar ao menu anterior                                              |\n");
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("\n");
        printf("               Escolha a opção desejada: ");
        scanf(" %c", &op);
        getchar();
        printf("\n");                                                                        
        printf("+---------------------------------------------------------------------------+\n");
        switch (op) {
            case '1':
                cadastra_cliente();
                break;
            case '2':
                pesquisa_cliente();
                break;
            case '3':
                atualiza_cliente();
                break;
            case '4':
                exclui_cliente();
                break;
            case '0':
                printf("Voltando ao menu principal\n");
                printf("\n");
                printf("\t\t\t>>> Tecle ENTER para continuar...\n");
                getchar();
                break;
            default:
                printf("Opção inválida, digite um dígito entre os disponíveis\n");
                printf("\n");
                printf("\t\t\t>>> Tecle ENTER para continuar...\n");
                getchar(); 
                break;	
        }
    } while (op != '0');
}

void cadastra_cliente(void) {
    char situacao[20];
    
    Cliente *cliente = (Cliente*) malloc(sizeof(Cliente));      // Aloca dinamicamente memória para a estrutura Cliente
    if (cliente == NULL) {
        perror("Erro ao alocar memória em cliente");
        exit(1);
    }

    FILE* fp;  // Ponteiro para o arquivo
    
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                         >>  Cadastrar Cliente  <<                         |\n");
    printf("|                                                                           |\n");
    /// Ainda será implementado >>> printf("|-> Endereço: ");
    /// + opções de entradas de dados


    
    printf("|-> Nome do cliente: ");
    do {
        leNomeCliente(cliente); // Atualizado para usar o campo da estrutura
        if (validaNome(cliente->nome)) {
            printf("Nome válido\n");
            break;
        } else {
            printf("Nome inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Nome do cliente: ");
        }
    } while (!validaNome(cliente->nome));

    
    printf("|-> CPF (somente números): ");
    do {
        leCpfCliente(cliente);
        if (validaCPF(cliente->cpf)) {
            printf("CPF válido\n");
            break;
        } else {
            printf("CPF inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> CPF (somente números): ");
        }
    } while (!validaCPF(cliente->cpf)); // Continua até o CPF ser válido

    
    printf("|-> Email: ");
    do {
        leEmailCliente(cliente);    // Lê o email dinamicamente através do ponteiro
        if (validaEmail(cliente->email)) {
            printf("Email válido\n");
            break;
        } else {
            printf("Email inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Email: ");
        }
    } while(!validaEmail(cliente->email));

    
    printf("|-> Data de nascimento (DD/MM/AAAA): ");
        do {
        leDataCliente(cliente);   // Lê a data dinamicamente através do ponteiro
        if (validaData(cliente->data)) {
            printf("Data válida\n");
            break;
        } else {
            printf("Data inválida, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Data de nascimento (DD/MM/AAAA): ");
        }
    } while(!validaData(cliente->data));
    
    printf("|-> Telefone (somente números): ");
     do {
        leFoneCliente(cliente);    // Lê o número de telefone dinamicamente através do ponteiro
        if (validaFone(cliente->fone)) {
            printf("Número de telefone válido\n");
            break;
        } else {
            printf("Número de telefone inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Telefone (somente números): ");
        }
    } while(!validaFone(cliente->fone));

    cliente->status = 'a';  // Atualiza o status do cliente para 'ativo'
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");

    // Exibe as informações para o usuário
    if ((cliente == NULL) || (cliente->status == 'x')) {
        printf("Cliente Inexistente");
    } else {
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("| Cliente cadastrado com sucesso\n");
        printf("|\n");
        printf("| Nome: %s\n", cliente->nome);
        printf("| CPF: %s\n", cliente->cpf);
        printf("| Email: %s\n", cliente->email);
        printf("| Data de nascimento: %s\n", cliente->data);
        printf("| Número de telefone: %s\n", cliente->fone);
    
        // Verifica o status do cliente (ativo/inativo)
        if (cliente->status == 'a') {
            strcpy(situacao, "Ativo");
            
        } else if (cliente->status == 'i') {
            strcpy(situacao, "Inativo");
            
        } else {
            strcpy(situacao, "Não informado");
        }
        
        printf("| Situação do cliente: %s\n", situacao);
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }

    fp = fopen ("clientes.dat", "ab");
    if(fp == NULL) {
        perror("Erro ao abrir o arquivo clientes.dat");
        exit(1);  // Mantém a saída do programa caso haja um erro ao abrir o arquivo
    }
    
    grava_cliente(fp, cliente);
    fclose (fp);  //Fecha o arquivo
    
    // Informações em arquivo texto chamada a partir de clientes.txt
    //fprintf(fp, "+---------------------------------------------------------------------------+\n");
    //fprintf(fp, "| Nome: %s\n", cliente->nome);
    //fprintf(fp, "| CPF: %s\n", cliente->cpf);
    //fprintf(fp, "| Email: %s\n", cliente->email);
    //fprintf(fp, "| Data de nascimento: %s\n", cliente->data);
    //fprintf(fp, "| Número de telefone: %s\n", cliente->fone);                                                              
    //fprintf(fp, "+---------------------------------------------------------------------------+\n");

    // Liberação da memória alocada dinamicamente
    free (cliente->nome);
    free (cliente->email);
    free (cliente->data);
    free (cliente->fone);      
    free (cliente);                        //libera memória da estrutura Cliente
}

void grava_cliente(FILE *fp, Cliente *cliente) {
    // Verifica se o arquivo está aberto corretamente
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo para salvar o cliente");
        return;
    }

    // Grava a estrutura básica (exceto os campos dinâmicos)
    fwrite(&cliente->status, sizeof(int), 1, fp);
    fwrite(cliente->cpf, sizeof(char), 12, fp);

    // Grava os campos dinâmicos

    // Escreve o nome
    int nome_len = strlen(cliente->nome) + 1;
    fwrite(&nome_len, sizeof(int), 1, fp);
    fwrite(cliente->nome, sizeof(char), nome_len, fp);

    // Escreve o email
    int email_len = strlen(cliente->email) + 1;
    fwrite(&email_len, sizeof(int), 1, fp);
    fwrite(cliente->email, sizeof(char), email_len, fp);

    // Escreve a data de nascimento
    int data_len = strlen(cliente->data) + 1;
    fwrite(&data_len, sizeof(int), 1, fp);
    fwrite(cliente->data, sizeof(char), data_len, fp);

    // Escreve o telefone
    int fone_len = strlen(cliente->fone) + 1;
    fwrite(&fone_len, sizeof(int), 1, fp);
    fwrite(cliente->fone, sizeof(char), fone_len, fp);

    // Fecha o arquivo
    fclose(fp);
}


void pesquisa_cliente() {
    char cpf_busca[12];
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                         >>  Pesquisar Cliente  <<                         |\n");
    printf("|                                                                           |\n");
    do {
      printf("Informe o CPF para pesquisa: ");
      scanf("%11s", cpf_busca);  // Limita a leitura a 11 caracteres
      
      if (validaCPF(cpf_busca)) {
          printf("CPF válido\n");
          break;
      } else {
          printf("CPF inválido, tente novamente apertando a tecla ENTER");
          getchar();
      }
    } while (!validaCPF(cpf_busca)); // Continua até o CPF ser válido
    printf("Procurando pelo CPF: %s\n", cpf_busca);  // Verifique se o CPF está correto

    busca_cliente(cpf_busca);
    getchar();
    printf("\n");
    printf("Pressione a tecla <ENTER> para continuar...\n");
    getchar();

}

void busca_cliente (const char *cpf_busca) {
    
    FILE *fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo!\n");
        exit(1);
    }
        
    Cliente cliente;
        
    int tamanho;
    int encontrado = 0;
        
    // Lê cada cliente do arquivo
    while (fread(&cliente.status, sizeof(int), 1, fp) == 1) {   // Lê o status
        fread(cliente.cpf, sizeof(char), 12, fp);    // Lê o CPF (11 dígitos + '\0')

        // Lê o nome
        fread(&tamanho, sizeof(int), 1, fp);
        cliente.nome = (char *) malloc(tamanho);
        fread(cliente.nome, sizeof(char), tamanho,fp);

        // Lê o email
        fread(&tamanho, sizeof(int), 1, fp);
        cliente.email = (char *) malloc(tamanho);
        fread(cliente.email, sizeof(char), tamanho,fp);

        // Lê o data
        fread(&tamanho, sizeof(int), 1, fp);
        cliente.data = (char *)malloc(tamanho);
        fread(cliente.data, sizeof(char), tamanho, fp);

        // Lê o telefone
        fread(&tamanho, sizeof(int), 1, fp);
        cliente.fone = (char *)malloc(tamanho);
        fread(cliente.fone, sizeof(char), tamanho, fp);
  
        // Verifica se o CPF corresponde ao que foi procurado
        if (strcmp(cliente.cpf, cpf_busca) == 0) {
            printf("+---------------------------------------------------------------------------+\n");
            printf("| Cliente encontrado\n");
            printf("| Nome: %s\n", cliente.nome);
            printf("| CPF: %s\n", cliente.cpf);
            printf("| Email: %s\n", cliente.email);
            printf("| Data de nascimento: %s\n", cliente.data);
            printf("| Telefone: %s\n", cliente.fone);
            printf("+---------------------------------------------------------------------------+\n");
            encontrado = 1;
        }
        if (encontrado) {
            break;  // Encerra o loop se o cliente foi encontrado
        }
    }
        
    if (!encontrado) {
        printf("Cliente não encontrado\n");
    }

    fclose(fp);  // Fecha o arquivo após o uso
}


void atualiza_cliente(void) {
    Cliente cliente; // Declara uma variável do tipo Cliente
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                         >>  Atualizar Cliente  <<                         |\n");
    printf("|                                                                           |\n");
    printf("|-> Informe seu CPF: ");
    do {
        leCpfCliente(&cliente);
        if (validaCPF(cliente.cpf)) {
            break;
        } else {
            printf("CPF inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Informe seu CPF: ");
        }
    } while(!validaCPF(cliente.cpf));
    
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");
    printf("CPF inserido: %s\n", cliente.cpf);  // Acessa o campo cpf do struct

    //    Dados do cliente atualizados:
    //    printf("Nome: %s\n", nome);
    //    printf("CPF: %s\n", cpf);
    //    printf("Email: %s\n", email);
    //    printf("Data de nascimento: %s\n", data);
    //    printf("Número de telefone: %s\n", fone); 

    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void exclui_cliente(void) {
    Cliente cliente; // Declara uma variável do tipo Cliente
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                          >>  Excluir Cliente  <<                          |\n");
    printf("|                                                                           |\n");
    printf("|-> Informe seu CPF: ");
    do {
        leCpfCliente(&cliente);
        if (validaCPF(cliente.cpf)) {
            break;
        } else {
            printf("CPF inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Informe seu CPF: ");
        }
    } while(!validaCPF(cliente.cpf));
    
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");
    printf("CPF inserido: %s\n", cliente.cpf);  // Acessa o campo cpf do struct

    //    Cliente excluído:
    //    printf("Nome: %s\n", nome);
    //    printf("CPF: %s\n", cpf);
    //    printf("Email: %s\n", email);
    //    printf("Data de nascimento: %s\n", data);
    //    printf("Número de telefone: %s\n", fone); 

    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}
