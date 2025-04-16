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

struct node* insertbefore(struct node* head){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = head;
    struct node *preptr;
    int num,val;
    printf("\nenter the data:");
    scanf("%d",&num);
    printf("\nenter the value before which the data is to be inserted:");
    scanf("%d",&val);
    while(p->data!=val){
        preptr=p;
        p=p->next;
    }
    preptr->next=ptr;
    ptr->next=p;
    ptr->data=num;
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
    head = insertbefore(head);
    printf("After insertion\n");
    lltraversal(head);
    
    return 0;
}