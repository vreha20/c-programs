#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    struct node *next;
    int data;
} *first = NULL;

void insert(int pos, int x)
{
    struct node *t, *p;
    int i;
    
    t = (struct node *)malloc(sizeof(struct node));
    if (t == NULL)
        return;
    
    t->data = x;
    t->next = NULL;
    
    if (pos == 0)
    {
        if (first == NULL)
        {
            first = t;
            first->next = first;
        }
        else
        {
            p = first;
            while (p->next != first)
                p = p->next;
            
            p->next = t;
            t->next = first;
            first = t;
        }
    }
    else
    {
        p = first;
        for (i = 0; i < pos - 1 && p->next != first; i++)
            p = p->next;
        
        t->next = p->next;
        p->next = t;
    }
}

void display()
{
    struct node *p = first;
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != first);
    printf("\n");
}

int main()
{
    insert(0, 12);
    insert(1, 8);
    insert(2, 19);
    insert(1, 5);
    
    display();
    
    return 0;
}