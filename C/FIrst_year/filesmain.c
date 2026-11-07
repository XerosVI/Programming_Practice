#include<stdio.h>
#include "files.h"

int main (){
    scrivo_su_file("lista_spesa.txt");
    leggo_da_file("lista_spesa.txt");
    return 0;
}