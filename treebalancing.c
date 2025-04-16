#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *rchild;
    struct node *lchild;
};

struct node *insert(struct node *root, int data) {
    if (root == NULL) {
        root = (struct node *)malloc(sizeof(struct node));
        root->data = data;
        root->rchild = NULL;
        root->lchild = NULL;
        return root;
    }
    if (data < root->data)
        root->lchild = insert(root->lchild, data);
    else
        root->rchild = insert(root->rchild, data);

    return root;
}

int height(struct node *A) {
    if (A == NULL)
        return 0;
    int left_height = height(A->lchild);
    int right_height = height(A->rchild);
    return (left_height > right_height ? left_height : right_height) + 1;
}

void check_balance(struct node *A) {
    if (A == NULL) {
        printf("\nTree is empty.\n");
        return;
    }
    int left_height = height(A->lchild);
    int right_height = height(A->rchild);
    
    if (abs(left_height - right_height) <= 1)
        printf("\nTree is balanced.\n");
    else
        printf("\nTree is not balanced.\n");
}

void inorder_traversal(struct node *A) {
    if (A != NULL) {
        inorder_traversal(A->lchild);
        printf("%d ", A->data);
        inorder_traversal(A->rchild);
    }
}

int main() {
    struct node *root = NULL;
    int n, value;
    
    printf("Enter how many nodes you want to store in the tree: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter node value: ");
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nTree elements (in-order traversal):\n");
    inorder_traversal(root);

    check_balance(root);

    return 0;
}