#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;
void inQ(int x)
{
    struct node *A;
    A = (struct node *)malloc(sizeof(struct node));
    if (A==NULL)
        printf("queue overflow..");
    else
    {
        A->data = x;
        A->next = NULL;
        if(front == NULL)
            front = rear = A;
        else
        {
            rear->next = A;
            rear = A;
        }
    }
}

int deQ()
{
    int x;
    struct node *A;
    if(front == NULL)
        printf("Queue is empty..");
    else
    {
        A=front;
        front = front->next;
        x = A->data;
        free(A);
    }
    return x;
}
void display(struct node *A,struct node *B)
{
    if(A == NULL)
    {
        printf("Queue is empty..\n");
    }
    else
    {
        printf("%d \n",A->data);
        display(A->next,A);
    }
}
int main()
{
    inQ(12);
    inQ(1);
    inQ(11);
    inQ(6);
    inQ(2);
    display(front,NULL);
    printf("deleted item is: %d",deQ());

    return 0;
}
