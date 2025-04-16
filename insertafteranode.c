#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
void lltraversal(struct node *ptr){
    while(ptr != NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}

struct node * insertafteranode(struct node *head, struct node *prevnode,int data){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    ptr->next=prevnode->next;
    prevnode->next=ptr;
    ptr->data=data;
    return head;
}

int main() {
    struct node *head;
    struct node *second;
    struct node *third;
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    head->data=7;
    head->next=second;
    second->data=11;
    second->next=third;
    third->data=15;
    third->next = NULL;

    printf("Before insertion\n");
    lltraversal(head);
    head = insertafteranode(head,head, 17);
    printf("After insertion\n");
    lltraversal(head);
    
    return 0;
}