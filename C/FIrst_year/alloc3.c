#include<stdio.h>
#include<stdlib.h>

int *unisci_array_ordinati(int *arr1, int *arr2, size_t dim1, size_t dim2);

int main(void){
    int arr1[3]={1,5,6};
    int arr2[4]={2,4,8,9};
    int *a=unisci_array_ordinati(arr1,arr2,3,4);
    for(size_t i=0; i<3+4; i++){
        printf("%d",*(a+i));
    }
    free(a);
    return 0;
}

int *unisci_array_ordinati(int *arr1, int *arr2, size_t dim1, size_t dim2){
    int *a=malloc((dim1+dim2)*sizeof(int));
    size_t k=0, i=0, j=0;
    while(i<dim1 && j<dim2){
        if(arr1[i]<arr2[j])
            a[k]=arr1[i++];
        else
            a[k]=arr2[j++];
        k++;
        }

    while(i==dim1 && j<dim2)
        a[k++]=arr2[j++];

    while(j==dim2 && i<dim1)
        a[k++]=arr1[i++];
    return a;
    
}