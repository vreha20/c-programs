#include <stdio.h>
int main ()
{
    int n,i;
    printf("Enter the number of element which you want to store in array..\n");
    scanf("%d",&n);

    if(n==0)
    {
        printf("Invalid array!!");
        return -1;
    }

    int A[n];
    for(i=0;i<n;i++)
    {
        printf("Enter the  value of %d element:- ",i);
        scanf("%d",&A[i]);
    }

    for(i=0;i<n;i++)
    {
        printf("%d element of array are:- %d\n",i,A[i]);
    }
    return 0;
}
