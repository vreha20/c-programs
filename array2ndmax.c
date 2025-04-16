#include <stdio.h>
int main ()
{
    int i;
    int A[8]={24,35,46,25,11,78,56,97};
    int max = -1;
    int smax = -1;
    for ( i=0; i<8; i++)
    {
        if(A[i]>max)
        {
            smax = max;
            max = A[i];
        }
        else if(A[i]>smax && A[i]!=max)
        {
            smax=A[i];
        }
    }
    printf("%d",smax);
    return 0;
}
