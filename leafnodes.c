#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data) {
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int LeafNode(struct node *root) {
    if (root == NULL){
        return 0;}

    if (root->left == NULL && root->right == NULL) {
        printf("%d ", root->data);
        return 1;
    }
    else {
        int xl= LeafNode(root->left);
        int xr= LeafNode(root->right);

        return (xl+xr);
    }
}

void main() {
    struct node *root = createNode(5);
    root->left = createNode(4);
    root->right = createNode(6);
    root->left->left = createNode(2);
    root->right->left = createNode(7);
    root->right->right = createNode(6);

    printf("Leaf Nodes: ");
    LeafNode(root);
}

