#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *left;
    int value;
    struct node *right;
};

struct node *insert(struct node *t, int x) {
    if (t == NULL) {
        t = (struct node *)malloc(sizeof(struct node));
        t->value = x;
        t->left = NULL;
        t->right = NULL;
        return t;
    }
    if (x < t->value)
        t->left = insert(t->left, x);
    else if (x > t->value)
        t->right = insert(t->right, x);
    return t;
}

void display(struct node *t) {
    if (t != NULL) {
        display(t->left);
        printf("%d ", t->value);
        display(t->right);
    }
}

struct node *search(struct node *t, int x) {
    while (t != NULL) {
        if (t->value == x)
            return t;
        else if (x < t->value)
            t = t->left;
        else
            t = t->right;
    }
    return NULL;
}

int main() {
    struct node *tree = NULL;
    int values[] = {12, 3, 2, 31, 15, 17, 11, 1, 19, 5, 54, 40, 0, 77};
    int size = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < size; i++)
        tree = insert(tree, values[i]);

    printf("Tree elements (in-order):\n");
    display(tree);

    printf("\nSearch result: %p\n", search(tree, 40));

    return 0;
}