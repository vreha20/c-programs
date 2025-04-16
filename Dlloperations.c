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

void insertAtBeginning() {
    int data;
    printf("Enter data to insert at the beginning: ");
    scanf("%d", &data);
    struct Node* newNode = createNode(data);
    if (!newNode) return;
    if (!head) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtEnd() {
    int data;
    printf("Enter data to insert at the end: ");
    scanf("%d", &data);
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

void insertBefore() {
    int key, data;
    printf("Enter the data of the node before which to insert: ");
    scanf("%d", &key);
    printf("Enter data to insert: ");
    scanf("%d", &data);
    struct Node* p = head;
    while (p && p->data != key)
        p = p->next;
    if (!p) {
        printf("Node not found.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    if (!newNode) return;
    newNode->next = p;
    newNode->prev = p->prev;
    if (p->prev)
        p->prev->next = newNode;
    else
        head = newNode;
    p->prev = newNode;
}

void insertAfter() {
    int key, data;
    printf("Enter the data of the node after which to insert: ");
    scanf("%d", &key);
    printf("Enter data to insert: ");
    scanf("%d", &data);
    struct Node* p = head;
    while (p && p->data != key)
        p = p->next;
    if (!p) {
        printf("Node not found.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    if (!newNode) return;
    newNode->next = p->next;
    newNode->prev = p;
    if (p->next)
        p->next->prev = newNode;
    p->next = newNode;
}

void deleteFromBeginning() {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    struct Node* p = head;
    head = head->next;
    if (head)
        head->prev = NULL;
    free(p);
}

void deleteFromEnd() {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    struct Node* p = head;
    while (p->next)
        p = p->next;
    if (p->prev)
        p->prev->next = NULL;
    else
        head = NULL;
    free(p);
}

void deleteNode() {
    int key;
    printf("Enter the data of the node to delete: ");
    scanf("%d", &key);
    struct Node* p = head;
    while (p && p->data != key)
        p = p->next;
    if (!p) {
        printf("Node not found.\n");
        return;
    }
    if (p->prev)
        p->prev->next = p->next;
    else
        head = p->next;
    if (p->next)
        p->next->prev = p->prev;
    free(p);
}

void deleteAfter() {
    int key;
    printf("Enter the data of the node after which to delete: ");
    scanf("%d", &key);
    struct Node* p = head;
    while (p && p->data != key)
        p = p->next;
    if (!p || !p->next) {
        printf("No node found \n");
        return;
    }
    struct Node* delNode = p->next;
    p->next = delNode->next;
    if (delNode->next)
        delNode->next->prev = p;
    free(delNode);
}

void deleteList() {
    struct Node* p = head;
    while (p) {
        struct Node* temp = p;
        p = p->next;
        free(temp);
    }
    head = NULL;
    printf("List deleted.\n");
}

int main() {
    int choice = 0;

    while (choice != 11) {
        printf("1: Insert at beginning\n");
        printf("2: Insert at end\n");
        printf("3: Insert before a node\n");
        printf("4: Insert after a node\n");
        printf("5: Delete from beginning\n");
        printf("6: Delete from end\n");
        printf("7: Delete a node\n");
        printf("8: Delete a node after\n");
        printf("9: Delete entire list\n");
        printf("10: Display list\n");
        printf("11: Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) insertAtBeginning();
        else if (choice == 2) insertAtEnd();
        else if (choice == 3) insertBefore();
        else if (choice == 4) insertAfter();
        else if (choice == 5) deleteFromBeginning();
        else if (choice == 6) deleteFromEnd();
        else if (choice == 7) deleteNode();
        else if (choice == 8) deleteAfter();
        else if (choice == 9) deleteList();
        else if (choice == 10) displayList();
        else if (choice == 11) printf("Exiting\n");
        else printf("Invalid choice.\n");
    }

    return 0;
}  