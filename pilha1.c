#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha {
    int top;
    int size;
    char *buffer;
} Pilha;

Pilha *cria_pilha () {
    Pilha *p = (Pilha *) malloc(sizeof (Pilha));
    p->top = -1;
    p->size = 1;
    p->buffer = (char *) malloc(p->size * sizeof (char));
    return p;
}

void empilha (Pilha *p, char c) {
    if (p->top == p->size - 1) {
        p->size *= 2;
        p->buffer = (char *) realloc(p->buffer, p->size * sizeof (char));
    }
    p->top++;
    p->buffer[p->top] = c;
}

void desempilha (Pilha *p) {
    if (p->top == -1) {
        printf("Pilha vazia\n");
        return;
    }
    p->top--;
}

void calcula(Pilha *p) {
    char c = p->buffer[p->top];
    desempilha(p);
    int b = p->buffer[p->top] - '0';
    desempilha(p);
    int a = p->buffer[p->top] - '0';
    desempilha(p);  
    int r;
    switch (c) {
        case '+':
            r = a + b;
            break;
        case '-':
            r = a - b;
            break;
        case '*':
            r = a * b;
            break;
        case '/':
            r = a / b;
            break;
    }
    empilha(p, r + '0');
}

int main () {
    Pilha *p = cria_pilha();
    char exp[20];
    printf("Digite a expressão: ");
    scanf("[^\n]", exp);
    for(int i = 0; i < strlen(exp); i++) {
        if(exp[i] >= '0' && exp[i] <= '9') {
            empilha(p, exp[i]);
        } else {
            empilha(p, exp[i]);
            calcula(p);
        }
    }
    printf("Resultado: %d\n", p->buffer[p->top]);
    free(p->buffer);
    free(p);
    return 0;
}