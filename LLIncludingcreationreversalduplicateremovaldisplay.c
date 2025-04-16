#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *first = NULL;

struct node *create(int n)
{
    if (n <= 0)
    {
        printf("Increase node size...\n");
        return NULL;
    }

    int value;
    printf("\nEnter value of 1st node: ");
    scanf("%d", &value);
    first = (struct node *)malloc(sizeof(struct node));
    first->data = value;
    first->next = NULL;

    struct node *B = first;
    for (int i = 2; i <= n; i++)
    {
        printf("\nEnter value of %d node: ", i);
        scanf("%d", &value);
        struct node *A = (struct node *)malloc(sizeof(struct node));
        A->data = value;
        A->next = NULL;
        B->next = A;
        B = A;
    }
    return first;
}

void display(struct node *A)
{
    if (A == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("\nLinked list:\n");
    while (A != NULL)
    {
        printf("%d ", A->data);
        A = A->next;
    }
    printf("\n");
}

void reverse(struct node **head)
{
    struct node *prev = NULL, *current = *head, *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void remove_duplicates(struct node *A)
{
    struct node *B;
    while (A != NULL && A->next != NULL)
    {
        if (A->data == A->next->data)
        {
            B = A->next;
            A->next = A->next->next;
            free(B);
        }
        else
        {
            A = A->next;
        }
    }
}

int main()
{
    int n;
    printf("Enter how many nodes you want to create: ");
    scanf("%d", &n);

    first = create(n);
    display(first);
    
    reverse(&first);
    printf("\nReversed linked list:\n");
    display(first);

    remove_duplicates(first);
    printf("\nAfter removing duplicates:\n");
    display(first);

    return 0;
}