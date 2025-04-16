#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
}; 

struct Node* head = NULL;

void createList(int data) {
    head = (struct Node*)malloc(sizeof(struct Node));
    if (!head) {
        printf("Memory allocation failed.\n");
        return;
    }
    head->data = data;
    head->next = NULL;
}

void displayList() {
    struct Node* p = head;
    if (!p) {
        printf("List is empty.\n");
        return;
    }
    while (p) {
        printf(" %d ", p->data);
        p = p->next;
    }
}

void addAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void addAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (!head) {
        head = newNode;
        return;
    }

    struct Node* p = head;
    while (p->next) {
        p = p->next;
    }
    p->next = newNode;
}

void deleteFromBeginning() {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    struct Node* p = head;
    head = head->next;
    free(p);
}

void deleteFromEnd() {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    struct Node* p = head, *prev = NULL;
    while (p->next) {
        prev = p;
        p = p->next;
    }
    if (prev)
        prev->next = NULL;
    else
        head = NULL;
    free(p);
}

void reverseList() {
    struct Node* prev = NULL, *current = head, *next = NULL;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void sortList() {
    if (!head) return;
    struct Node *i, *j;
    int p;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                p = i->data;
                i->data = j->data;
                j->data = p;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the first element of the list:\n");
    scanf("%d", &n);
    createList(n);
    displayList();

    int vn;
    printf("\nEnter the element to add at the beginning:\n");
    scanf("%d", &vn);
    addAtBeginning(vn);
    displayList();

    int fn;
    printf("\nEnter the element to add at the end:\n");
    scanf("%d", &fn);
    addAtEnd(fn);
    displayList();

    printf("\nAfter deleting from the beginning:\n");
    deleteFromBeginning();
    displayList();

    printf("\nAfter deleting from the end:\n");
    deleteFromEnd();
    displayList();

    printf("\nReversing list:\n");
    reverseList();
    displayList();

    printf("\nSorting list:\n");
    sortList();
    displayList();

    return 0;
}