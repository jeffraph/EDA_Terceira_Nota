#include <stdio.h>
#include <stdlib.h>
  

void merge(int array[], int x, int y, int z)
{
    int i, j, k;
    int n1 = y - x + 1;
    int n2 = z - y;
  
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = array[x + i];
    for (j = 0; j < n2; j++)
        R[j] = array[y + 1 + j];

    i = 0;
    j = 0;
    k = x;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        }
        else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }
  
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}
  
void mergeSort(int array[], int x, int z)
{
    if (x < z) {

        int y = x + (z - x) / 2;
  
        mergeSort(array, x, y);
        mergeSort(array, y + 1, z);
  
        merge(array, x, y, z);
    }
}

void imprimir(int A[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
        printf("%d ", A[i]);
    printf("\n");
}
  
/* Driver code */
int main()
{
    int array[] = { 5, 15, 11, 9, 2, 1 };
    int tamanhoArray = sizeof(array) / sizeof(array[0]);
  
    printf("Antes da ordenacao \n");
    imprimir(array, tamanhoArray);
  
    mergeSort(array, 0, tamanhoArray - 1);
  
    printf("\nDepois da ordenacao \n");
    imprimir(array, tamanhoArray);
    return 0;
}