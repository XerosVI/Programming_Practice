#include<stdio.h>

int main(void) {
    double celsius, fahrenheit, kelvin;
    printf("Inserire temperatura in gradi celsius\t");
    scanf("%lf",&celsius);
    fahrenheit=celsius*9/5+32;
    kelvin=celsius+273.15;
    printf("La temperatura in kelvin e': %.2lf, mentre la temperatura in fahrenheit e': %.2lf\n",kelvin,fahrenheit);
    return 0;
}