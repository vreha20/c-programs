#include <stdio.h>

int binarySearch(int arr[], int low, int high, int x) {
    if (low > high)
        return -1; 

    int mid = low + (high - low) / 2;

    if (arr[mid] == x)
        return mid;  

    if (x > arr[mid])  
        return binarySearch(arr, mid + 1, high, x);
    
    return binarySearch(arr, low, mid - 1, x); 
}

int main() {
    int n, key, result;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the element to search: ");
    scanf("%d", &key);

    result = binarySearch(arr, 0, n - 1, key);

    if (result != -1)
        printf("Element found at index %d.\n", result);
    else
        printf("Element not found\n");

    return 0;
}