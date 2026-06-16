#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SOGLIA 100
#define MAXDEVICE 100

typedef struct Device {
    char nome[20];
    int ore_uso;
    float consumo_h;
    float consumo_tot;
} Device;

int leggi_e_stampa(FILE *fp1, FILE *fp2, Device arr[]);
char *min(Device arr[], int n);
char *max(Device arr[], int n);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Argomenti inseriti incorrettamente\n");
        return 1;
    }

    FILE *fp1, *fp2;
    if ((fp1 = fopen(argv[1], "r")) == NULL) {
        printf("Errore apertura file di lettura\n");
        return 1;
    }
    if ((fp2 = fopen(argv[2], "w")) == NULL) {
        printf("Errore apertura file di scrittura\n");
        fclose(fp1); 
        return 1;
    }


    Device arr[MAXDEVICE]; 
    

    int n = leggi_e_stampa(fp1, fp2, arr);


    if (n > 0) {
        fprintf(fp2, "\n%s\n%s", min(arr, n), max(arr, n));
    } else {
        fprintf(fp2, "\nNessun dato presente nel file.");
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}

int leggi_e_stampa(FILE *fp1, FILE *fp2, Device arr[]) {
    int i = 0;
    while (i < MAXDEVICE && fscanf(fp1, "%19s %d %f", arr[i].nome, &arr[i].ore_uso, &arr[i].consumo_h) !=EOF) {
        arr[i].consumo_tot = arr[i].ore_uso * arr[i].consumo_h;
        if (arr[i].consumo_tot > SOGLIA) {
            fprintf(fp2, "%s\n", arr[i].nome);
        }
        i++;
    }
    return i; 
}


char *min(Device arr[], int n) {
    float minimo = arr[0].consumo_tot;
    int indice_min = 0;

    for (int i = 1; i < n; i++) { 
        if (arr[i].consumo_tot < minimo) {
            minimo = arr[i].consumo_tot;
            indice_min = i;
        }
    }
    return arr[indice_min].nome;
}

char *max(Device arr[], int n) {
    float massimo = arr[0].consumo_tot;
    int indice_max = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i].consumo_tot > massimo) {
            massimo = arr[i].consumo_tot;
            indice_max = i;
        }
    }
    return arr[indice_max].nome;
}