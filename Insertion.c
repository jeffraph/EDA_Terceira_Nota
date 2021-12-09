#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordenacao(int x[], int y) {
    int i, valor, j;
    for (i = 1; i < y; i++)
    {
        valor = x[i];
        j = i - 1;
 
        while (j >= 0 && x[j] > valor)
        {
            x[j + 1] = x[j];
            j = j - 1;
        }
        x[j + 1] = valor;      
    }
}

void imprimir(int x[], int y) {
    int i;
    FILE *file;

    file = fopen("teste.txt", "w");
    file = fopen("teste.txt", "a");
    
    for (i = 0; i < y; i++){

        fprintf(file, "%d ", x[i]);
        printf("%d ", x[i]);
    }

    fprintf(file, "\n\n\n");
    printf("\n\n\n");
}
 
int main() {

    int i;
    int x[1000];
    int y = sizeof(x) / sizeof(x[0]);

    srand(time(NULL));

    for (i = 0; i < 1000; i++)
        x[i] = rand() % 1000;

    printf("ANTES DA ORDENAÇÃO :\n\n");
    imprimir(x, y);

    printf("DEPOIS DA ORDENAÇÃO :\n\n");
    ordenacao(x, y);
    imprimir(x, y);

    return 0;
}