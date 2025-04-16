#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* ntptr;
};

void addnode(int n) {
    struct node *stnode, *tmp, *fnode;
    int data, i;
    
    stnode = (struct node*)malloc(sizeof(struct node));
    if (stnode == NULL) {
        printf("memory not allocated");
        return;
    }

    printf("input data for node 1: ");
    scanf("%d", &data);
    stnode->data = data;
    stnode->ntptr = NULL;
    tmp = stnode;

    for(i = 2; i <= n; i++) {
        fnode = (struct node*)malloc(sizeof(struct node));
        if (fnode == NULL) {
            printf("memory not allocated");
            return;
        }

        printf("input data for node %d: ", i);
        scanf("%d", &fnode->data);
        fnode->ntptr = NULL;
        tmp->ntptr = fnode;
        tmp = fnode;
    }
}

void display(struct node* stnode) {
    struct node *tmp = stnode;
    if (tmp == NULL) {
        printf("List is empty.\n");
    } else {
        while (tmp != NULL) {
            printf("data = %d\n", tmp->data);
            tmp = tmp->ntptr;
        }
    }
}

int main() {
    int n;
    struct node* stnode = NULL;
    
    printf("enter number of nodes: ");
    scanf("%d", &n);
    
    addnode(n);
    display(stnode);
    
    return 0;
}
