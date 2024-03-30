#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50

void push(char *stack, char el, int *top) {
    (*top)++;
    stack[*top] = el;
}

char pop(char *stack, int *top) {
    char el = stack[*top];
    (*top)--;
    return el;
}

int is_op(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int eval_expr(char *expr) {
    char stack[MAX_SIZE];
    int top = -1;

    for(int i = 0; i < strlen(expr); i++) {
        if (!is_op(expr[i])) {
            push(stack, expr[i] - '0', &top);
        } else {
            int a = pop(stack, &top);
            int b = pop(stack, &top);
            int res;
            switch(expr[i]) {
                case '+':
                    res = b + a;
                    break;
                case '-':
                    res = b - a;
                    break;
                case '*':
                    res = b * a;
                    break;
                case '/':
                    res = b / a;
                    break;
            }
            push(stack, res, &top);
        }
    }
    return pop(stack, &top);
}

int main(void) {
    char expr[MAX_SIZE];
    
    printf("Digite a expressao: ");
    scanf("%s", expr);
    
    int res = eval_expr(expr);
    printf("Resultado: %d\n", res);

    return 0;
}
