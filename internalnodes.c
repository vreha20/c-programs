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

struct node *insertNode(struct node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    char d;
    printf("Enter 'L' to insert as left child or 'R' for right: ");
    scanf(" %c", &d);

    if (d == 'L' || d == 'l') {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }

    return root;
}

void inorderTraversal(struct node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int internalnode(struct node *root) {
    if (root == NULL) {
        return 0;
    }
    
    if (root->left != NULL || root->right != NULL) {
        return 1 + internalnode(root->left) + internalnode(root->right);
    }

    return 0;  
}

int main() {
    int n, data;
    struct node *root = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        if (root == NULL) {
            root = createNode(data);
        } else {
            root = insertNode(root, data);
        }
    }

    printf("\nIn-order Traversal of the Tree: ");
    inorderTraversal(root);
    printf("\n");

    int c= internalnode(root); 
    printf("Count of internal nodes is %d\n", c);

    return 0;
}