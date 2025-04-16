#include <stdio.h>
#include <stdlib.h>
#define m 5

int stack[m];
int top = -1; 

void push(int n) {
    if (top == m - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = n;
        printf("Element %d pushed into the stack.\n", n);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
    } else {
        printf("Element %d popped from the stack.\n", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack is: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

void peek(){
    if (top == -1) {
        printf("stack is empty\n");
    } else{
        printf("the top element of stak is : %d",stack[top]);
    }
}

void main() {
    int c, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. peek\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
    
        if (c == 1) {
            printf("Enter the value to push: ");
            scanf("%d", &value);
            push(value);
        } if (c == 2) {
            pop();
        } if (c == 3) {
            display();
        }
        if (c == 4) {
            peek();
        }
         if (c == 5) {
            printf("Exiting\n");
            exit(0); 
        } if (c < 1 || c > 4) {
            printf("Invalid choice\n");
        }
    }
}