#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_LIVROS 100

typedef struct {
    int codigo;
    char titulo[100];
    char autor[100];
    int status; // 0: Disponível, 1: Emprestado
} Livro;

Livro acervo[MAX_LIVROS];
int totalLivros = 0;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int buscarLivro(int cod) {
    for (int i = 0; i < totalLivros; i++) {
        if (acervo[i].codigo == cod) return i;
    }
    return -1;
}

void cadastrarLivro() {
    system("cls");
    if (totalLivros >= MAX_LIVROS) {
        printf("--- ERRO: ACERVO CHEIO ---\n");
        return;
    }
    printf("===== CADASTRO DE LIVRO =====\n");
    printf("Código: ");
    scanf("%d", &acervo[totalLivros].codigo);
    limparBuffer();

    printf("Título: ");
    fgets(acervo[totalLivros].titulo, 100, stdin);
    acervo[totalLivros].titulo[strcspn(acervo[totalLivros].titulo, "\n")] = 0;

    printf("Autor: ");
    fgets(acervo[totalLivros].autor, 100, stdin);
    acervo[totalLivros].autor[strcspn(acervo[totalLivros].autor, "\n")] = 0;

    acervo[totalLivros].status = 0;
    totalLivros++;
    printf("\n>>> LIVRO CADASTRADO COM SUCESSO! <<<\n");
}

void consultarLivro() {
    system("cls");
    int cod;
    printf("===== CONSULTA DE LIVROS =====\n");
    printf("Digite o código: ");
    scanf("%d", &cod);
    limparBuffer();

    int i = buscarLivro(cod);
    if (i != -1) {
        printf("\n-----------------------------\n");
        printf("Título: %s\n", acervo[i].titulo);
        printf("Autor:  %s\n", acervo[i].autor);
        printf("Status: %s\n", (acervo[i].status == 0) ? "DISPONÍVEL" : "EMPRESTADO");
        printf("-----------------------------\n");
    } else {
        printf("\n[!] Livro não encontrado.\n");
    }
}

void emprestarLivro() {
    system("cls");
    int cod;
    printf("===== EMPRÉSTIMO =====\n");
    printf("Código do livro: ");
    scanf("%d", &cod);
    limparBuffer();

    int i = buscarLivro(cod);
    if (i != -1) {
        if (acervo[i].status == 0) {
            acervo[i].status = 1;
            printf("\n>>> EMPRÉSTIMO CONCLUÍDO: %s <<<\n", acervo[i].titulo);
        } else {
            printf("\n[!] Este livro já está emprestado.\n");
        }
    } else {
        printf("\n[!] Código não localizado.\n");
    }
}

void devolverLivro() {
    system("cls");
    int cod;
    printf("===== DEVOLUÇÃO =====\n");
    printf("Código do livro: ");
    scanf("%d", &cod);
    limparBuffer();

    int i = buscarLivro(cod);
    if (i != -1) {
        if (acervo[i].status == 1) {
            acervo[i].status = 0;
            printf("\n>>> DEVOLUÇÃO CONCLUÍDA: %s <<<\n", acervo[i].titulo);
        } else {
            printf("\n[!] O livro já está no acervo.\n");
        }
    } else {
        printf("\n[!] Código não localizado.\n");
    }
}

void listarLivros() {
    system("cls");
    printf("===== LISTAGEM GERAL DO ACERVO =====\n\n");
    if (totalLivros == 0) {
        printf("O acervo está vazio no momento.\n");
    } else {
        printf("%-10s | %-20s | %-15s\n", "CÓDIGO", "TÍTULO", "STATUS");
        printf("----------------------------------------------------------\n");
        for (int i = 0; i < totalLivros; i++) {
            printf("%-10d | %-20s | %s\n", 
                   acervo[i].codigo, acervo[i].titulo, 
                   (acervo[i].status == 0) ? "Disponível" : "Emprestado");
        }
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao;

    do {
        system("cls");
        printf("==============================\n");
        printf("      SISTEMA BIBLIOTECA      \n");
        printf("==============================\n");
        printf("  1 - Cadastrar Livro\n");
        printf("  2 - Consultar Livro\n");
        printf("  3 - Emprestar Livro\n");
        printf("  4 - Devolver Livro\n");
        printf("  5 - Listar Acervo\n");
        printf("  0 - Sair\n");
        printf("==============================\n");
        printf("Escolha uma opção: ");
        
        if (scanf("%d", &opcao) != 1) {
            opcao = -1;
            limparBuffer();
        } else {
            limparBuffer();
        }

        switch (opcao) {
            case 1: cadastrarLivro(); break;
            case 2: consultarLivro(); break;
            case 3: emprestarLivro(); break;
            case 4: devolverLivro(); break;
            case 5: listarLivros(); break;
            case 0: system("cls"); printf("\nSistema encerrado.\n"); break;
            default: printf("\nOpção inválida!\n");
        }

        if (opcao != 0) {
            printf("\nPressione ENTER para voltar ao menu...");
            getchar();
        }

    } while (opcao != 0);

    return 0;
}

// PONTOS IMPORTANTES DO CÓDIGO:
// 1. Uso de STRUCT para organizar os dados do livro em um único bloco.
// 2. MODULARIZAÇÃO através de funções separadas para cada tarefa do menu.
// 3. REUSO DE CÓDIGO com a função buscarLivro usada em consulta, empréstimo e devolução.
// 4. LIMPEZA DE TELA (system "cls") para manter a interface visual organizada.
// 5. TRATAMENTO DE BUFFER (limparBuffer) para garantir a leitura correta de textos.
// 6. ESTRUTURAS DE REPETIÇÃO (do-while e for) para o menu e listagem do acervo.
