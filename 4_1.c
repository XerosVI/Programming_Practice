#include <stdio.h>

int main() {
    int n;
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter %d positive integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int search_value;
    printf("Enter the value to search for: ");
    scanf("%d", &search_value);
    for(int i = 0; i < n; i++) {
        if(arr[i] == search_value) {
            printf("Value found at index: %d\n", i);
            return 0;
        }
    }
    printf("Value not found in the array.\n");
    return 0;
}