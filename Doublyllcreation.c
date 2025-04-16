#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void displayList() {
    struct Node* p = head;
    if (!p) {
        printf("List is empty.\n");
        return;
    }
    while (p) {
        printf("%d  ", p->data);
        p = p->next;
    }
    printf("\n");
}

void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);
    if (!newNode) return;
    if (!head) {
        head = newNode;
        return;
    }
    struct Node* p = head;
    while (p->next)
        p = p->next;
    p->next = newNode;
    newNode->prev = p;
}

void createDLL() {
    int n, data;
    printf("Enter the number of nodes you want to create: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(data);
    }
}

int main() {
    int choice = 0;
    
    while (choice != 3) {
        printf("1: Create doubly linked list\n");
        printf("2: Display list\n");
        printf("3: Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) createDLL();
        else if (choice == 2) displayList();
        else if (choice == 3) printf("Exiting\n");
        else printf("Invalid choice.\n");
    }

    return 0;
}