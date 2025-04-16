#include <stdio.h>
int main ()
{
    int i;
    int A[8]={24,35,46,25,11,78,56,97};
    int min = A[0];
    for(i = 0; i < 8; i++)
    {
        if(A[i] < min )
            min = i;
}
    printf("minimum value of array at position %d..",min);
    return 0;
}
