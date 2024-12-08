#ifndef CLIENTE_H  // Prevenção de múltiplas inclusões: garante que o arquivo só será incluído uma vez
#define CLIENTE_H  // Marca CLIENTE_H como definido

// Declaração das funções relacionadas ao cliente
void menu_cliente(void);
void cadastra_cliente(void);
void pesquisa_cliente(void);
void atualiza_cliente(void);
void exclui_cliente(void);

// Estrutura para armazenar os dados do cliente
typedef struct {
    char status;      // Status do cliente (ativo, inativo, etc.)
    char *nome;       // Nome dinâmico
    char cpf[12];     // CPF com tamanho fixo
    char *email;      // E-mail dinâmico
    char *data;       // Data de nascimento ou cadastro dinâmico
    char *fone;       // Telefone dinâmico
} Cliente;

#endif // Finaliza a proteção
