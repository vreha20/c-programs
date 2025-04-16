   #include<stdio.h>
    #include<stdlib.h>
   struct node{
    int data;
    struct node*left;
    struct node*right;
   };


   void main() {
    struct node *ptr;
    ptr=(struct node*) malloc(sizeof(struct node));
    ptr->left=NULL;
    ptr->right=NULL;
    ptr->data=10;
    printf("%d",ptr->data);


    struct node *ptr1;
    ptr1=(struct node*) malloc(sizeof(struct node));
    ptr1->left=NULL;
    ptr1->right=NULL;
    ptr1->data=5;
    printf("%d",ptr1->data);

    struct node *ptr2;
    ptr2=(struct node*) malloc(sizeof(struct node));
    ptr2->left=NULL;
    ptr2->right=NULL;
    ptr2->data=15;
    printf("%d",ptr2->data);

    ptr->left=ptr1;
    ptr->right=ptr2;
}

