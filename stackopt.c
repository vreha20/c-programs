#include <stdio.h>

#define MAX 15

struct stack {
    int size;
    int top;
    int s[MAX];
};

void push(struct stack *st, int x) {
    if (st->top == st->size - 1)
        printf("Stack overflow!!\n");
    else {
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(struct stack *st) {
    int x = -1;
    if (st->top == -1)
        printf("Stack underflow!!\n");
    else {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

int peek(struct stack *st, int pos) {
    int x = -1;
    if ((st->top - pos + 1) < 0)
        printf("Invalid position!!!\n");
    else
        x = st->s[st->top - pos + 1];
    return x;
}

int stacktop(struct stack *st) {
    if (st->top == -1)
        return -1;
    else
        return st->s[st->top];
}

void display(struct stack *st) {
    if (st->top == -1) {
        printf("Stack underflow!!\n");
        return;
    }
    printf("Stack is as follows:\n");
    for (int i = st->top; i >= 0; i--) {
        printf("%d\n", st->s[i]);
    }
}

int main() {
    struct stack st;
    st.size = MAX;
    st.top = -1;

    push(&st, 12);
    push(&st, 32);
    push(&st, 42);
    push(&st, 72);

    printf("Popped value: %d\n", pop(&st));
    display(&st);
    printf("Value at position 2 is: %d\n", peek(&st, 2));

    return 0;
}
