#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *front = NULL, *rear = NULL;

void inQ(int x)
{
    struct node *A = (struct node *)malloc(sizeof(struct node));
    if (A == NULL)
        printf("Queue overflow..\n");
    else
    {
        A->data = x;
        A->next = NULL;
        if (front == NULL)
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
    if (front == NULL)
    {
        printf("Queue is empty..\n");
        return -1;
    }
    struct node *A = front;
    int x = A->data;
    front = front->next;
    free(A);
    return x;
}

void rvs()
{
    if (front != NULL)
    {
        int i = deQ();
        rvs();
        inQ(i);
    }
}

void display(struct node *A)
{
    if (A == NULL)
        printf("Queue is empty..\n");
    else
    {
        while (A != NULL)
        {
            printf("%d \n", A->data);
            A = A->next;
        }
    }
}

int main()
{
    inQ(12);
    inQ(1);
    inQ(11);
    inQ(6);
    inQ(2);
    display(front);
    printf("Deleted item is: %d\n", deQ());
    rvs();
    display(front);
    printf("Deleted item is: %d\n", deQ());

    return 0;
}