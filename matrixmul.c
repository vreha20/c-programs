#include<stdio.h>
void main(){
    int m,n;
    printf("enter number of rows:");
    scanf("%d",&m);
    printf("enter number of columns:");
    scanf("%d",&n);
    int a1[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("the elements are:");
            scanf("%d",&a1[i][j]);
        }
    }
    printf(" 1st matrix is:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("  %d", a1[i][j]);
        }
        printf("\n");
    }
    printf("enter number of rows:");
    scanf("%d",&m);
    printf("enter number of columns:");
    scanf("%d",&n);
    int a2[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("the elements are:");
            scanf("%d",&a2[i][j]);
        }
    }
    printf(" 2nd matrix is:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("  %d", a2[i][j]);
        }
        printf("\n");
    }
    if (n!=m){
        printf("matrix multiplication is not possible");
    }
    else{
    int mul[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            mul[i][j] = 0;
            for (int k = 0; k < n; k++) {
                mul[i][j] += a1[i][k] * a2[k][j];
            }
        }
    }
    printf("Product of matrices:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mul[i][j]);
        }
        printf("\n");}

    }
}