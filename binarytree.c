#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertNode() {
    int data;
    printf("Enter node value (-1 for NULL): ");
    scanf("%d", &data);
    
    if (data == -1) {
        return NULL;
    }

    struct Node* n = createNode(data);
    printf("Enter left child of %d:\n", data);
    n->left = insertNode();
    printf("Enter right child of %d:\n", data);
    n->right = insertNode();
    
    return n;
}
void inorderTraversal(struct Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    printf(" Binary Tree:\n");
    struct Node* root = insertNode();

    printf("\ninorder Traversal of Created Tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}