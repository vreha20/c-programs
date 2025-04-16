#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*ntptr;
}stnode; //pointer variable to starting node

void addnode();
void display();

void main(){
    int n;
    printf("enter number of nodes:");
    scanf("%d",&n);

    addnode(n);

    printf("data entered in the list:\n");
    display(); 
    
    void addnode(int n){
        struct node *stnode, *tmp;
        int data,i;
        stnode = (struct node*)(malloc(size of(struct node)));

        if (stnode == NULL){
            printf("memory not allocated");}
        else {
            printf("input data for node 1:");
            scanf("%d",&data);
            stnode -> data=data;
            stnode -> ntptr=NULL;
            tmp=stnode;
            for(i=2;i<=n;i++){
                fnode=(struct node*)(malloc(size of(struct node)));
                if(fnode==NULL){
                    printf("memory not allocated");
                }
                else {
                    printf("input data for node %d:",i);
                    scanf("%d",&data);
                }
                fnode -> data=data;
                fnode -> ntptr = NULL;

                tmp-> ntptr = fnode;
                tmp=tmp->ntptr;
            }
        }
    }
    void display() {
        struct node*tmp;
        if (stnode == NULL){
            printf("memory not allocated");}
        else {
            tmp = stnode;
            while(tmp!=NULL){
                printf("data=%d\n",tmp->data);
                tmp = tmp -> ntptr;
            }
        }
    }
}