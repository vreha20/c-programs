#include <stdio.h>
int main ()
{
    int i,j;
    int A[10]={24,97,35,46,25,11,78,56,11,97};
    int count = 0;
    int x = A[0];
    for(i=0;i<10;i++)
    {
       for(j=i+1;j<10;j++)
       {
           if(A[i]==A[j])
           {
               printf("%d \n",A[i]);
               count++;
           }
       }
    }
    printf("%d",count);
    return 0;
}
