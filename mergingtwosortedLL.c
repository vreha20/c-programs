#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*first = NULL,*second = NULL;

struct node *create(int n, int list_num)
{
    int i, value;
    struct node *head = NULL, *A, *B;

    if(n <= 0)
    {
        printf("Increase node size...");
        return NULL;
    }

    printf("\nEnter value of 1 node:- ");
    scanf("%d", &value);

    head = (struct node *)malloc(sizeof(struct node));
    head->data = value;
    head->next = NULL;

    B = head;
    for(i = 2; i <= n; i++)
    {
        printf("\nEnter value of %d node:- ", i);
        scanf("%d", &value);
        A = (struct node *)malloc(sizeof(struct node));
        A->data = value;
        A->next = NULL;
        B->next = A;
        B = A;
    }

    if(list_num == 1)
        first = head;
    else if(list_num == 2)
        second = head;

    return head;
}

struct node *mrg(struct node *A,struct node *B)
{
    struct node *frt=NULL,*last=NULL;

    if(A->data < B->data)
    {
        frt=last=A;
        A=A->next;
        last->next=NULL;
    }
    else
    {
        frt=last=B;
        B=B->next;
        last->next = NULL;
    }

    while(A!=NULL && B!=NULL)
    {
        if(A->data < B->data)
        {
            last->next=A;
            last=A;
            A=A->next;
            last->next=NULL;
        }
        else
        {
            last->next=B;
            last=B;
            B=B->next;
            last->next=NULL;
        }
    }
    if(A!=NULL)
    {
        last->next=A;
    }
    else
    {
        last->next=B;
    }
    return frt;
}


void display(struct node *A)
{
    if (A==NULL)
    {
        printf("list is empty..");
        return ;
    }
    printf("\nLinked list are..\n");
    while(A!=NULL)
    {
        printf("%d\n",A->data);
        A=A->next;
    }
}

int main()
{

    int m,n;
    printf("Enter how many node you want to create in first list..\n");
    scanf("%d",&n);

    printf("Enter how many node you want to create in second list..\n");
    scanf("%d",&m);

    first = create(n,1);
    second = create(m,2);

    display(first);
    display(second);
    first = mrg(first,second);
    display(first);
    return 0;
}
