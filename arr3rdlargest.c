#include <stdio.h>

int main() {
    int A[8] = {24, 35, 46, 25, 11, 78, 56, 97};
    int max = A[0], smax = A[0], tmax = A[0];

    for (int i = 1; i < 8; i++) {
        if (A[i] > max) {
            tmax = smax;
            smax = max;
            max = A[i];
        } else if (A[i] > smax && A[i] != max) {
            tmax = smax;
            smax = A[i];
        } else if (A[i] > tmax && A[i] != smax && A[i] != max) {
            tmax = A[i];
        }
    }

    if (max == smax || smax == tmax)
        printf("No third largest element exists.\n");
    else
        printf("Third largest element: %d\n", tmax);

    return 0;
}