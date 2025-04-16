#include<stdio.h>
void main(){
    int i;
    printf("enter the size of array:");
    scanf("%d",&i);
    int arr[i];

    for (int j=0;j<i;j++){
        printf("enter elements:");
        scanf("%d",&arr[j]);
    }
    printf("\n");
    printf("the mean of elements is:");
    float mean=0;
    float sum=0;
    for (int j=0;j<i;j++) {
        sum=sum+arr[j];
        mean=sum/i;
    }
    printf("%f\n",mean);
}