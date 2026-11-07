#include<stdio.h>

float max(float [], int n);
int main(void){
    float arr[5]={7,2.1,1,4.3,0.2};
    printf("%f",max(arr, 5));
}

float max(float v[], int n){
    if(n==1)
        return v[0];
    if(v[0]>v[1])
        v[1]=v[0];
    return max(v+1, n-1); 
}