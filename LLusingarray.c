#include <stdio.h>

void create(int arr[],int n)
{
    if(n==0)
    {
        printf("Increase element size..");
        return -1;
    }
    int i;
    for(i = 1; i <= n; i++)
    {
        printf("\nEnter the %d element of array. ",i);
        scanf("%d",&arr[i]);
    }
}

void display(int arr[],int n)
{
    int i;
    if(n==0)
    {
        printf("Array is empty..");
        return -1;
    }
    for(i = 1; i <= n; i++)
    {
        printf("%d element of array:- %d\n",i,arr[i]);
    }
}

void insert(int arr[],int *n,int x)
{
    int i,value;
    printf("\nEnter the number which you want to insert. \n");
    scanf("%d",&value);

    for(i = n; i > x; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[x] = value;
    (*n)++;
}
int main ()
{
   int n,size;
   printf("Enter the size of array \n");
   scanf("%d",&size);

   if(size == 0)
   {
       printf("Array is invalid!!");
       return -1;
   }

   int A[size];

   printf("\nEnter number of element you want to store in an array..\n");
   scanf("%d",&n);

   if (n > size)
   {
       printf("Increase the size of array!!!");
       return -1;
   }

   create(A,n);
   insert(A,&n,3);
   display(A,n);
   return 0;
}
