#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Atividade 1:
    Aluno: Matheus Henrique Rodrigues Magalhaes
    Matricula: 202103760
    Na opção Create verificar se o registro a ser inserido já existe
    Mostrar os dados em tela com a media final calculada que e o resultado da media aritmetica de Nota1 e Nota2
    Na opção Delete, pedir confirmação para a exclusão
    No Create ou Update, os campos devem ser validados
*/

typedef struct Aluno {
    char nome[30];
    char curso[30];
    int matricula;
    float nota1;
    float nota2;
} Aluno;


void create(Aluno *alunos, int *qtdAlunos) {
    if (*qtdAlunos == 50) {
        printf("Não e possivel adicionar mais alunos\n");
        return;
    }

    printf("Digite o nome do aluno: ");
    scanf("\n");
    scanf("%[^\n]%c", alunos[*qtdAlunos].nome);

    printf("Digite o curso do aluno: ");
    scanf("\n");
    scanf("%[^\n]%c", alunos[*qtdAlunos].curso);

    printf("Digite a matricula do aluno: ");
    scanf("%d", &alunos[*qtdAlunos].matricula);

    printf("Digite a nota 1 do aluno: ");
    scanf("%f", &alunos[*qtdAlunos].nota1);

    printf("Digite a nota 2 do aluno: ");
    scanf("%f", &alunos[*qtdAlunos].nota2);

    (*qtdAlunos)++;
    printf("Aluno cadastrado\n");
}

void read(Aluno *alunos, int qtdAlunos) {
    if (qtdAlunos == 0) {
        printf("Nenhum aluno cadastrado\n");
        return;
    }
    for (int i = 0; i < qtdAlunos; i++) {
        printf("\nAluno %d\n", i + 1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Curso: %s\n", alunos[i].curso);
        printf("Matricula: %d\n", alunos[i].matricula);
        printf("Nota 1: %.2f\n", alunos[i].nota1);
        printf("Nota 2: %.2f\n", alunos[i].nota2);
        printf("Media: %.2f\n", (alunos[i].nota1 + alunos[i].nota2) / 2);
        printf("\n");
    }
}

void update(Aluno *alunos, int qtdAlunos) {
    int matricula;
    printf("Digite a matricula do aluno que deseja atualizar: ");
    scanf("%d", &matricula);

    for (int i = 0; i < qtdAlunos; i++) {
        if (alunos[i].matricula == matricula){
            printf("Digite o nome do aluno: ");
            scanf("\n");
            scanf("%[^\n]%c", alunos[i].nome);

            printf("Digite o curso do aluno: ");
            scanf("\n");
            scanf("%[^\n]%c", alunos[i].curso);

            printf("Digite a matricula do aluno: ");
            scanf("%d", &alunos[i].matricula);

            printf("Digite a nota 1 do aluno: ");
            scanf("%f", &alunos[i].nota1);

            printf("Digite a nota 2 do aluno: ");
            scanf("%f", &alunos[i].nota2);

            printf("Aluno atualizado\n");
            return;
    }
        printf("Aluno nao encontrado\n");
    }
}

void delete(Aluno *alunos, int *qtdAlunos) {
    int matricula;
    printf("Digite a matricula do aluno que deseja excluir: ");
    scanf("%d", &matricula);

    for (int i = 0; i < *qtdAlunos; i++) {
        if (alunos[i].matricula == matricula){
            for (int j = i; j < *qtdAlunos - 1; j++) {
                alunos[j] = alunos[j + 1];
            }
            (*qtdAlunos)--;
            printf("Aluno de matricula %d excluido\n\n", matricula);
            return;
        }
    }

    printf("Aluno nao encontrado\n");
}

Aluno *alunos;
int qtdAlunos = 0;

int main() {
    alunos = (Aluno *)malloc(50 * sizeof(Aluno));

    int opcao;
    do {
        printf("1 - Cadastrar\n");
        printf("2 - Listar\n");
        printf("3 - Atualizar\n");
        printf("4 - Excluir\n");
        printf("5 - Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                create(alunos, &qtdAlunos);
                break;
            case 2:
                read(alunos, qtdAlunos);
                break;
            case 3:
                update(alunos, qtdAlunos);
                break;
            case 4:
                delete(alunos, &qtdAlunos);
                break;
        }
    } while (opcao != 5);

    free(alunos);
    printf("Saindo...\n");
    return 0;
}