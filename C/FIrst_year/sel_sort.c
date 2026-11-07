#include<stdio.h>
//selection sort
int main (){
    int arr[8]={7,1,4,5,2,0,6,3};
    size_t i=0, j=0, k=0;
    int t;
    for(i=0; i<7; i++){
        k=i;
        for(j=i+1; j<8; j++){
            if(arr[j]<arr[k]){
                k=j;
            }

        }
        t=arr[k];
        arr[k]=arr[i];
        arr[i]=t;
    }
    for(i=0; i<8; i++){
        printf("%d ", arr[i]);
    }
}