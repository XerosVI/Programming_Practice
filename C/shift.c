#include<stdio.h>

int main(void){
    int n; //arr size
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int s; //shift amount
    scanf("%d", &s);
    s=s%n;
    int arr2[s];
    for(int i=0;i<s;i++){
        arr2[i]=arr[i];
    }
    for(int i=0; i<n-s; i++){
        arr[i] = arr[i+s];
    }
    for(int i=n-s;i<n;i++){
        arr[i]=arr2[i+s-n];
    }
    

    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}