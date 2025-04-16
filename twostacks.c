#include <stdio.h>

#define MAX1 10
#define MAX2 10
int stack1[MAX1];
int stack2[MAX2];
int top1 = -1, top2 = -1;

void push(int *arr, int *top, int x, int max_size) {
    if (*top == max_size - 1) {
        printf("Stack overflow..\n");
    } else {
        (*top)++;
        arr[*top] = x;
    }
}

int pop(int *arr, int *top) {
    if (*top == -1) {
        printf("Stack underflow..\n");
        return -1;
    }
    int x = arr[*top];
    (*top)--;
    return x;
}

void display(int *arr, int top) {
    if (top == -1) {
        printf("Stack is empty..\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    push(stack1, &top1, 10, MAX1);
    push(stack1, &top1, 12, MAX1);
    push(stack1, &top1, 14, MAX1);
    
    display(stack1, top1);

    int x = pop(stack1, &top1);
    printf("Popped element: %d\n", x);
    display(stack1, top1);

    return 0;
}