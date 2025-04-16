#include <stdio.h>

#define MAX 15
int stack[MAX];
int top = -1;

void push(int arr[], int val) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        top++;
        arr[top] = val;
    }
}

int pop(int arr[]) {
    if (top == -1) {
        printf("Stack underflow..\n");
        return -1;
    }
    return arr[top--];
}

void display(int arr[]) {
    if (top == -1) {
        printf("Stack is empty..\n");
    } else {
        printf("Stack contents:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    push(stack, 10);
    push(stack, 12);
    push(stack, 14);
    display(stack);

    int x = pop(stack);
    printf("Popped element: %d\n", x);
    display(stack);

    return 0;
}