#include <stdio.h>

int main() {
    int a[6] = {1, 2, 3, 4, 5, 6};
    int b[6] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++) {
        if(a[i] != b[i]) {
            printf("Arrays are not equal.\n");
            return 0;
        }
    }
    printf("Arrays are equal.\n");
    return 0;
}