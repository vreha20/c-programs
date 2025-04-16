#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
}*first = NULL,*top = NULL;

void push(int x)
{
    struct node *st;
    st = (struct node *)malloc(sizeof(struct node));
    if ( st == NULL)
        printf("Stack memory does't allocated..");
    else
    {
        st->data = x;
        st->next = top;
        top = st;
    }
}

int pop()
{
    struct node *p;
    int x = -1;
    if(top == NULL)
        printf("stack is empty..");
    else
    {
        p = top;
        top = top->next;
        x = p->data;
        free(p);
    }
    return x;
}

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
    first->prev = NULL;
    first->data = value;
    first->next = NULL;

    struct node *B=first;
    for( i=2; i<=n; i++ )
    {
        printf("\nEnter value of %d node:- ",i);
        scanf("%d",&value);
        A = (struct node *)malloc(sizeof(struct node));
        A->prev = NULL;
        A->data = value;
        A->next = NULL;

        A->prev = B;
        B->next = A;
        B=A;
    }
    return first;
}

void rvs(struct node *head)
{
    struct node *A=head;
    while(A != NULL)
    {
        push(A->data);
        A=A->next;
    }
    A=head;
    while(A!=NULL)
    {
        A->data = pop();
        A=A->next;
    }
}

int rvs2(struct node *head)
{
    struct node *last=NULL,*current=head;
    while(current != NULL)
    {
        last = current->prev;
        current->prev = current->next;
        current->next = last;
        current = current->next;
    }
    return last->prev;
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
    rvs(first);
    display(first);
    return 0;
}
