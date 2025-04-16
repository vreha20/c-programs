#include<stdio.h>
    #include<stdlib.h>
   struct node{
    int data;
    struct node*left;
    struct node*right;
   };

   struct node *createNode(int data) {
    struct node *n = (struct node*)malloc(sizeof(struct node)); // creating a node pointer then allocating memory 
    n->data = data;// assigning data 
    n->left = NULL;// assigning left child to NULL
    n->right = NULL;   // assigning right child to NULL
    return n; // returning the node
}

   void main() {
    struct node *root = createNode(1); 
    struct node *ptr1 = createNode(2);
    struct node *ptr2 = createNode(3); 
    root->left=ptr1;
    root->right=ptr2;
}

