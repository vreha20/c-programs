#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* ntptr;
};

void addnode(int n) {
    struct node *stnode, *tmp, *fnode;
    int data, i;
    stnode = (struct node*)malloc(sizeof(struct node));

    if (stnode == NULL) {
        printf("Memory not allocated");
        return;
    } else {
        printf("Input data for node 1: ");
        scanf("%d", &data);
        stnode->data = data;
        stnode->ntptr = NULL;
        tmp = stnode;
        for (i = 2; i <= n; i++) {
            fnode = (struct node*)malloc(sizeof(struct node));
            if (fnode == NULL) {
                printf("Memory not allocated");
                return;
            } else {
                printf("Input data for node %d: ", i);
                scanf("%d", &fnode->data);
                fnode->ntptr = NULL;
                tmp->ntptr = fnode;
                tmp = fnode;
            }
        }
    }
}

void display(struct node* stnode) {
    struct node* tmp;
    tmp = stnode;
    while (tmp != NULL) {
        printf("Data = %d\n", tmp->data);
        tmp = tmp->ntptr;
    }
}

int main() {
    int n;
    struct node *stnode;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    addnode(n);
    display(struct node * stnode);
}
