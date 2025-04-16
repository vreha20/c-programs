#include <stdio.h>

#define MAX 15
int rear = -1;
int front = -1;
int Qe[MAX];

void InQueue(int arr[], int x) {
    if (rear == MAX - 1) {
        printf("Queue overflow..\n");
    } else {
        if (front == -1)
            front = 0;
        rear++;
        arr[rear] = x;
    }
}

int DeQueue(int arr[]) {
    int x = -1;
    if (front > rear) { 
        printf("Queue underflow..\n");
    } else {
        x = arr[front];
        front++;
    }
    return x;
}

void display(int arr[]) {
    if (front > rear) { 
        printf("Queue is empty..\n");
        return;
    }
    
    printf("Queue:\n");
    for (int i = front; i <= rear; i++) {
        printf("%d \n", arr[i]);
    }
}

int main() {
    InQueue(Qe, 12);
    InQueue(Qe, 2);
    InQueue(Qe, 42);
    InQueue(Qe, 45);
    display(Qe);

    int a = DeQueue(Qe);
    printf("Deleted value in Queue is %d.\n", a);
    display(Qe);

    return 0;
}