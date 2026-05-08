#include<stdio.h>

int main(void){
    const int n=1000;
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=1;
    }
    for(int i=2; i<n;i++){
        if(arr[i]==1){
            printf("%d ",i);
            for(int j=i*2;j<n;j+=i){
                    arr[j]=0;
            }
        }
    }
    
    return 0;
}