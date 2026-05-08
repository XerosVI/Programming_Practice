#include<stdio.h>

int main(void){
    int flag=0;
    int dim;
    scanf("%d",&dim);
    int search[dim];
    for(int i=0;i<dim;i++){
        scanf("%d",&search[i]);
    }

    scanf("%d",&dim);
    int arr[dim];
    for(int i=0;i<dim;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<dim-sizeof(search)/sizeof(search[0]);i++){
        if(arr[i]==search[0]){
            for(int j=1;j<sizeof(search)/sizeof(search[0]);j++){
                if(arr[i+j]==search[j])
                    flag=1;
                else
                    flag=0;
            }
        }
        if(flag==1){
            printf("indice=%d",i);
            return 0;
        }
    }
}