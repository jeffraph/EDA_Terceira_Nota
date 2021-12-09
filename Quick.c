#include <stdio.h>

void troca(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int part(int array[], int l, int h) {
  
  int pivo = array[h];

  int i = (l - 1);

  for (int j = l; j < h; j++) {
    if (array[j] <= pivo) {
        
      i++;

      troca(&array[i], &array[j]);
    }
  }

  troca(&array[i + 1], &array[h]);

  return (i + 1);
}

void quickSort(int array[], int l, int h) {
  if (l < h) {

    int pi = part(array, l, h);

    quickSort(array, l, pi - 1);

    quickSort(array, pi + 1, h);
  }
}

void imprimir(int array[], int tam) {
  for (int i = 0; i < tam; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
  int x[] = {10, 3, 2, 12, 11};
  
  int n = sizeof(x) / sizeof(x[0]);
  
  printf("Antes da ordenacao: \n");
  imprimir(x, n);

  quickSort(x, 0, n - 1);
  
  printf("Depois da ordenacao: \n");
  imprimir(x, n);
}