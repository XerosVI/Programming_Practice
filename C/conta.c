#include<stdio.h>

int conta_positivi(int *array, size_t num_elements);

int main(){
    int arr[10]={1,2,3,4,-1,-1,-1,-1,-1,1};
    printf("%d",conta_positivi(arr, 10));
}


int conta_positivi(int *array, size_t num_elements){
    int c=0;
    for(size_t i=0; i<num_elements; i++){
        if(*(array+i)>=0){
            c++;
        }
    }
    return c;
}
