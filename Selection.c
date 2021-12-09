#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
void troca(int *posicaox, int *posicaoy)
{
    int temp = *posicaox;
    *posicaox = *posicaoy;
    *posicaoy = temp;
}
 
void selectionSort(int array[], int n)
{
    int i, j, min;
 
    for (i = 0; i < n-1; i++) {
        min = i;
        for (j = i+1; j < n; j++)
          if (array[j] < array[min])
            min = j;
        troca(&array[min], & array[i]);
    }
}
 
void imprimir(int array[], int t) {
    int i;
    for (i=0; i < t; i++)
        printf("%d ", array[i]);
    printf("\n\n\n");
}

int main() {

    int i;
    int array[1000];
    int n = sizeof(array)/sizeof(array[0]);

    srand(time(NULL));

    for (i = 0; i < 1000; i++)
        array[i] = rand() % 1000;

    printf("ANTES DA ORDENACAO: \n\n");
    imprimir(array, n);
    selectionSort(array, n);
    printf("DEPOIS DA ORDENACAO: \n\n");
    imprimir(array, n);

    return 0;
}