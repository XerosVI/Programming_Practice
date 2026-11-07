#include<stdio.h>

int binary_search(int, int [], int, int);
int main(void){
    int array[6]={1,2,3,5,6,7};
    printf("%d",binary_search(3,array,0,5));
}

int binary_search(int key, int array[], int low, int high){
    int i=(high+low)/2;
    if(array[i]==key){
        return i;
    }
    
    if(high==low){
        return -1;
    }

    if(array[i]>key){
        return binary_search(key, array, low, i-1);
    }
    else if(array[i]<key){
        return binary_search(key, array, i+1, high);
    }
}