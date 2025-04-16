#include <stdio.h>
#define MAX 15

int queue[MAX];
int f=-1,r=-1;

void enQ(int x)
{
    if (f == (r + 1) % MAX)
    {
        printf("Queue is overflow..");
        return;
    }
    if (f== -1)
    {
        f = r= 0;
    }
    else
    {
        r= (r+ 1) % MAX;
    }
    queue[r] = x;
    printf("Inserted: %d\n", x);
}

int dequeue()
{
    if (f== -1)
    {
        printf("Queue is underflow..\n");
        return -1;
    }
    int x = queue[f];
    if (f== r)
    {
        f= r = -1;
    } else {
        f = (f+ 1) % MAX;
    }
    printf("Removed: %d\n", x);
    return x;
}

void display()
{
    if (f == -1)
    {
        printf("Queue is underflow..\n");
        return;
    }
    printf("Queue elements: ");
    int i = f;
    while (1)
    {
        printf("%d ", queue[i]);
        if (i == r) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    enQ(10);
    enQ(20);
    enQ(30);
    enQ(40);
    enQ(50);

    display();

    dequeue();
    enQ(60);

    display();

    return 0;
}
