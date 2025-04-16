#include<stdio.h>
int main(){
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
    printf("sum of matrices is:\n");
    int A[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
    A[i][j]=a1[i][j]+a2[i][j];
    printf(" %d",A[i][j]);}
    printf("\n");}
    return 0;
}