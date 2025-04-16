#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*first = NULL;

struct node *create(int n)
{
    int i,value;
    struct node *A;

    if(n<=0)
    {
        printf("Increase node size...");
        return -1;
    }

    printf("\nEnter value of 1 node:- ");
    scanf("%d",&value);
    first = (struct node *)malloc(sizeof(struct node));
    first->data = value;
    first->next = NULL;

    struct node *B=first;
    for( i=2; i<=n; i++ )
    {
        printf("\nEnter value of %d node:- ",i);
        scanf("%d",&value);
        A = (struct node *)malloc(sizeof(struct node));
        A->data = value;
        A->next = NULL;

        B->next = A;
        B=A;
    }

    return first;
}

struct node *even(struct node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct node *odd = head;
    struct node *even = head->next;
    struct node *evenH = even;
    while (even != NULL && even->next != NULL)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenH;
    return head;
}

void display(struct node *A)
{
    if(A==NULL)
        printf("\nLinked list are empty..");
    printf("\nLinked list is:\n");
    while(A!=NULL)
    {
        printf("%d ",A->data);
        A=A->next;
    }
}
int main()
{

    int n;
    printf("Enter how many node you want to create..\n");
    scanf("%d",&n);

    first = create(n);
    display(first);
    first = even(first);
    display(first);
    return 0;
}
