//Positive integer square root
#include<stdio.h>
#include<stdlib.h>
int integer_sqrt(int x, int left, int right){
    if(left>right){
        return -1;
    }
    //Since there has to be a square root for any positive number, this safety check is useless
    //but it's good practice for general binary searches
    if(x==0||x==1){
        return x;
    }
    int mid=left+(right-left)/2;
    if(mid<=x/mid&&(mid+1)>x/(mid+1))
        return mid;
    if(mid>x/mid)
        return integer_sqrt(x,left, mid-1);
    return integer_sqrt(x,mid+1, right);
}

int main(int argc, char *argv[]){
    if (argc < 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }
    int const left=1;
    int const x=atoi(argv[1]);
    printf("RESULT: %d",integer_sqrt(x,left,x/2));
}