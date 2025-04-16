#include <stdio.h>
#include <stdlib.h>
#define n 10

int queue[n];
int front = -1;
int rear = -1;

void insert(){
    int num;
    printf("enter the element to insert:");
    scanf("%d",&num);
    if (rear == n-1){
        printf("overflow");
    }
    else if (front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = num;
    }
    else{
        rear++;
        queue[rear] = num;

    }

}

void delete(){
    if (front == -1 && rear == -1){
        printf("underflow");
    }
    else if (front == rear){
        printf("deleted element is %d",queue[front]);
        front = rear = -1;
    }
    else{
        printf("deleted element is %d",queue[front]);
        front++;
    }
}
void display(){
    if (front == -1 && rear == -1){
        printf("queue is empty");
    }
    else{
        for (int i = front; i <= rear; i++){
            printf("%d ",queue[i]);
        }
    }
}
void main(){
    int c;
    while(1){
        printf("\n");
        printf("1.insert\n2.delete\n3.display\n4.exit\n");
        printf("enter your choice:");
        scanf("%d",&c);
        if (c == 1) {
            insert();
        } if (c == 2) {
            delete();
        } if (c == 3) {
            display();
        }
         if (c == 4) {
            printf("Exiting\n");
            exit(0); 
        } if (c < 1 || c > 4) {
            printf("Invalid choice\n");
        }
    }
}