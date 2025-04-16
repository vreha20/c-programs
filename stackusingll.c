#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *top = NULL;

void push(int x) {
    struct node *st = (struct node *)malloc(sizeof(struct node));
    if (st == NULL) {
        printf("Stack memory couldn't be allocated..\n");
        return;
    }
    st->data = x;
    st->next = top;
    top = st;
}

int pop() {
    if (top == NULL) {
        printf("Stack is empty..\n");
        return -1;
    }
    struct node *p = top;
    int x = p->data;
    top = top->next;
    free(p);
    return x;
}

int peek(int pos) {
    struct node *p = top;
    for (int i = 0; i < pos - 1; i++) {
        if (p == NULL) {
            printf("Invalid position.\n");
            return -1;
        }
        p = p->next;
    }
    return (p != NULL) ? p->data : -1;
}

void display() {
    if (top == NULL) {
        printf("Stack is empty..\n");
        return;
    }
    struct node *p = top;
    printf("Stack elements:\n");
    while (p != NULL) {
        printf("%d\n", p->data);
        p = p->next;
    }
}

int main() {
    push(11);
    push(12);
    push(13);
    push(14);
    push(15);

    printf("Popped value: %d\n", pop());
    display();

    printf("Peeked value at position 2: %d\n", peek(2));

    return 0;
}