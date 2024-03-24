#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno {
    char nome[30];
    char curso[30];
    int matricula;
    float nota1;
    float nota2;
    struct Aluno *next;
    struct Aluno *prev;
} Aluno;

typedef struct List {
    struct Aluno *head;
    struct Aluno *tail;
    int qtdAlunos;
} List;

void create(List *list) {
    if (list->qtdAlunos == 50) {
        printf("Não e possivel adicionar mais alunos\n");
        return;
    }

    Aluno *newAluno = (Aluno *) malloc(sizeof(Aluno));

    printf("Digite o nome do aluno: ");
    scanf("\n");
    scanf("%[^\n]%*c", newAluno->nome);

    printf("Digite o curso do aluno: ");
    scanf("\n");
    scanf("%[^\n]%*c", newAluno->curso);

    printf("Digite a matricula do aluno: ");
    scanf("%d", &newAluno->matricula);

    printf("Digite a nota 1 do aluno: ");
    scanf("%f", &newAluno->nota1);

    printf("Digite a nota 2 do aluno: ");
    scanf("%f", &newAluno->nota2);

    newAluno->next = NULL;
    newAluno->prev = list->tail;

    if (list->qtdAlunos == 0) {
        list->head = newAluno;
    } else {
        list->tail->next = newAluno;
    }

    list->tail = newAluno;
    list->qtdAlunos++;
    printf("Aluno cadastrado\n");
}

void read(List *list) {
    if (list->qtdAlunos == 0) {
        printf("Nenhum aluno cadastrado\n");
        return;
    }

    Aluno *current = list->head;
    for (int i = 0; i < list->qtdAlunos; i++) {
        printf("\nAluno %d\n", i + 1);
        printf("Nome: %s\n", current->nome);
        printf("Curso: %s\n", current->curso);
        printf("Matricula: %d\n", current->matricula);
        printf("Nota 1: %.2f\n", current->nota1);
        printf("Nota 2: %.2f\n", current->nota2);
        printf("Media: %.2f\n", (current->nota1 + current->nota2) / 2);
        printf("\n");
        current = current->next;
    }
}

void update(List *list) {
    int matricula;
    printf("Digite a matricula do aluno que deseja atualizar: ");
    scanf("%d", &matricula);

    Aluno *current = list->head;
    for (int i = 0; i < list->qtdAlunos; i++) {
        if (current->matricula == matricula) {
            printf("Digite o nome do aluno: ");
            scanf("\n");
            scanf("%[^\n]%*c", current->nome);

            printf("Digite o curso do aluno: ");
            scanf("\n");
            scanf("%[^\n]%*c", current->curso);

            printf("Digite a matricula do aluno: ");
            scanf("%d", &current->matricula);

            printf("Digite a nota 1 do aluno: ");
            scanf("%f", &current->nota1);

            printf("Digite a nota 2 do aluno: ");
            scanf("%f", &current->nota2);
            printf("Aluno atualizado\n");
            return;
        }
        current = current->next;
    }
    printf("Aluno não encontrado\n");
}

void delete(List *list) {
    int matricula;
    printf("Digite a matricula do aluno que deseja excluir: ");
    scanf("%d", &matricula);
    

    Aluno *current = list->head;
    for (int i = 0; i < list->qtdAlunos; i++) {
        if (current->matricula == matricula) {
            if (current->prev == NULL) {
                list->head = current->next;
            } else {
                current->prev->next = current->next;
            }

            if (current->next == NULL) {
                list->tail = current->prev;
            } else {
                current->next->prev = current->prev;
            }

            free(current);
            list->qtdAlunos--;
            printf("Aluno excluido\n");
            return;
        }
        current = current->next;
    }
    printf("Aluno não encontrado\n");
}

int main() {
    List list;
    list.head = NULL;
    list.tail = NULL;
    list.qtdAlunos = 0;

    int option;
    do {
        printf("1 - Cadastrar\n");
        printf("2 - Listar\n");
        printf("3 - Atualizar\n");
        printf("4 - Excluir\n");
        printf("5 - Sair\n");
        printf("Digite uma opcao: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                create(&list);
                break;
            case 2:
                read(&list);
                break;
            case 3:
                update(&list);
                break;
            case 4:
                delete(&list);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida\n");
        }
    } while (option != 5);

    return 0;
}