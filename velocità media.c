#include<stdio.h>

double v_media(double dist,int o, int min){
    return dist/(o+(double)min/60); //casting esplicito perché la divisione min/60 altrimenti darebbe un intero
}

int main(void){
    double d;
    unsigned int h,m;
    printf("Inserire distanza in km:\t");
    scanf("%lf",&d);
    printf("Inserire ore, premere invio, successivamente inserire minuti:\n");
    scanf("%u%u",&h,&m);
    printf("La velocita' media e' %.2lf\n",v_media(d,h,m));
    return 0;
}