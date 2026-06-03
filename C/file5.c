#include<stdio.h>
typedef struct Libro{
    char titolo[30];
    char autore_nome[16];
    char autore_cognome[16];
    unsigned int num_pagine;
    unsigned int num_capitoli;
}Libro;
Libro *get_book_with_longest_chapters(Libro libri[],size_t num_libri);
int main(void){
    FILE *fp;
    if((fp=fopen("libri.txt","r"))==NULL){
        printf("NULL");
        return -1;
    }
    size_t num_libri;
    fscanf(fp,"%zu\n",&num_libri);
    Libro libri[num_libri];
    for(size_t i=0; i<num_libri; i++){
        fscanf(fp,"%[^,],%[^,],%[^,],%u,%u\n",libri[i].titolo,libri[i].autore_nome,libri[i].autore_cognome,&libri[i].num_pagine,&libri[i].num_capitoli);
    }
    Libro pippo=*(get_book_with_longest_chapters(libri,num_libri));
    printf("il libro coi capitoli piu' lunghi e' %s", pippo.titolo);
    fclose(fp);
    return 0;
}
Libro *get_book_with_longest_chapters(Libro libri[],size_t num_libri){ //restituisce pointer al libro cercato
    float max=0;
    size_t j=0;
    for(size_t i=0; i<num_libri; i++){
        if(max<(float)(libri[i].num_pagine)/libri[i].num_capitoli){
            max=(float)(libri[i].num_pagine)/libri[i].num_capitoli;
            j=i;
        }
    }
    return libri+j;
}