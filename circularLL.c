#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void createList(int n) {
    if (n <= 0) {
        printf("Invalid number of nodes.\n");
        return;
    }

    struct Node *p, *q;
    for (int i = 0; i < n; i++) {
        q = (struct Node*)malloc(sizeof(struct Node));
        if (!q) {
            printf("Memory allocation failed.\n");
            return;
        }

        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &q->data);
        q->next = NULL;

        if (!head) { 
            head = q;
            head->next = head; 
        } else {  
            p = head;
            while (p->next != head)
                p = p->next;
            p->next = q;
            q->next = head;
        }
    }
}

void displayList() {
    if (!head) {
        printf("List is empty.\n");
        return;
    }

    struct Node* p = head;
    do {
        printf("%d  ", p->data);
        p = p->next;
    } while (p != head);
}

void insertAtBeginning(int data) {
    struct Node* m = (struct Node*)malloc(sizeof(struct Node));
    if (!m) {
        printf("Memory allocation failed.\n");
        return;
    }
    m->data = data;

    if (!head) {
        head = m;
        m->next = head;
        return;
    }

    struct Node* p = head;
    while (p->next != head)
        p = p->next;
    m->next = head;
    p->next = m;
    head = m;
}

void insertAtEnd(int data) {
    struct Node* m = (struct Node*)malloc(sizeof(struct Node));
    if (!m) {
        printf("Memory allocation failed.\n");
        return;
    }
    m->data = data;

    if (!head) { 
        head = m;
        m->next = m; 
        return;
    }

    struct Node* p = head;
    while (p->next != head)
        p = p->next;

    p->next = m;
    m->next = head; 
}

void deleteNode(int key) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }

    struct Node *curr = head, *prev = NULL;
    if (head->data == key) {
        struct Node* temp = head;
        while (curr->next != head)
            curr = curr->next;

        if (head->next == head) { 
            head = NULL;
        } else {
            curr->next = head->next;
            head = head->next;
        }
        free(temp);
        return;
    }
    while (curr->next != head && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr->data == key) {
        prev->next = curr->next;
        free(curr);
    } else {
        printf("Node with data %d not found.\n", key);
    }
}

int main() {
    int choice, n, data;

    printf("Enter the number of nodes you want to create: ");
    scanf("%d", &n);
    createList(n);

    while (1) {
        printf("\n1: Display list\n");
        printf("2: Insert at beginning\n");
        printf("3: Insert at end\n");
        printf("4: Delete a node\n");
        printf("5: Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            displayList();
        } else if (choice == 2) {
            printf("Enter data to insert at beginning: ");
            scanf("%d", &data);
            insertAtBeginning(data);
        } else if (choice == 3) {
            printf("Enter data to insert at end: ");
            scanf("%d", &data);
            insertAtEnd(data);
        } else if (choice == 4) {
            printf("Enter data to delete: ");
            scanf("%d", &data);
            deleteNode(data);
        }
        else if (choice == 5) {
            printf("Exiting\n");
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}