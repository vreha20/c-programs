#include<stdio.h>
int main(){
    int m,n;
    printf("enter number of rows:");
    scanf("%d",&m);
    printf("enter number of columns:");
    scanf("%d",&n);
    int a[m][n];
    if (m==n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("the elements are:");
            scanf("%d",&a[i][j]);
        }
    }
    printf("matrix is:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("  %d", a[i][j]);
        }
        printf("\n");
    }
    
        printf("transpose matrix is:\n");
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                 printf(" %d", a[j][i]);
                }
                 printf("\n");
            }
    }
        else {
        printf("matrix should be square matrix to be transpose");
    }
    
    return 0;
}
        