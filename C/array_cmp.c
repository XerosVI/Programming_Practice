#include <stdio.h>
#define SIZE 3
int main() {
    int arr1[SIZE], arr2[SIZE];
    int arr_min[SIZE], arr_max[SIZE];
    double arr_mean[SIZE];
    printf("Enter 3 elements for array 1:\n");
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr1[i]);
    }
    
    printf("Enter 3 elements for array 2:\n");
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr2[i]);
    }
    
    for(int i = 0; i < SIZE; i++) {
        if(arr1[i] > arr2[i]) {
            arr_max[i] = arr1[i];
            arr_min[i] = arr2[i];
        } else {
            arr_max[i] = arr2[i];
            arr_min[i] = arr1[i];
        }
        arr_mean[i] = (arr1[i] + arr2[i]) / 2.0;
        printf("For index %d: Min = %d, Max = %d, Mean = %.2f\n", i, arr_min[i], arr_max[i], arr_mean[i]);
    }

    return 0;
}