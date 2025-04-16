#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data;
    struct node *next;
} *top = NULL;

void push(char x) {
    struct node *st = (struct node *)malloc(sizeof(struct node));
    if (st == NULL) {
        printf("Stack memory couldn't be allocated..\n");
        return;
    }
    st->data = x;
    st->next = top;
    top = st;
}

char pop() {
    if (top == NULL) {
        printf("Stack is empty..\n");
        return '\0';
    }
    struct node *p = top;
    char x = p->data;
    top = top->next;
    free(p);
    return x;
}

char stacktop() {
    return (top != NULL) ? top->data : '\0';
}

int operand(char x) {
    return (x == '+' || x == '-' || x == '*' || x == '/') ? 0 : 1;
}

int precedence(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

char *convert(char *infix) {
    int i = 0, j = 0;
    int x = strlen(infix);
    char *postfix = (char *)malloc((x + 1) * sizeof(char));

    if (postfix == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    while (infix[i] != '\0') {
        if (operand(infix[i])) {
            postfix[j++] = infix[i++];
        } else {
            while (top != NULL && precedence(infix[i]) <= precedence(stacktop())) {
                postfix[j++] = pop();
            }
            push(infix[i++]);
        }
    }

    while (top != NULL) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
    return postfix;
}

void display() {
    struct node *p = top;
    printf("Stack:\n");
    while (p != NULL) {
        printf("%c\n", p->data);
        p = p->next;
    }
}

int main() {
    char infix[] = "A+B*C";
    char *postfix = convert(infix);
    
    if (postfix != NULL) {
        printf("Postfix Expression: %s\n", postfix);
        free(postfix);
    }

    return 0;
}