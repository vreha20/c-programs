#include <stdio.h>
#include <stdlib.h>

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

void postOrderTraversal(struct node *root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct node *root = createNode(1);
    struct node *ptr1 = createNode(2);
    struct node *ptr2 = createNode(3);
    root->left = ptr1;
    root->right = ptr2;

    printf("post-order Traversal: ");
    postOrderTraversal(root);

    return 0;
}