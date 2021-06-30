#include <stdio.h>
#include <stdlib.h>


void enqueue (int vetor[], int elemento, int *fim, int tamanho)
{
  vetor[*fim] = elemento;
  (*fim)++;
}


int dequeue (int vetor[], int *inic, int tamanho)
{
  int elemento;
  elemento = vetor[*inic];
  (*inic)++;
  return elemento;
}

int main () {

   int elem;
   int inic = 0;
   int fim = 0;


   int fila_tamanho = 10;


   int *fila = (int *)malloc(fila_tamanho * sizeof(int));


   elem = 1;
   enqueue (fila, elem, &fim, fila_tamanho);


   elem = 2;
   enqueue (fila, elem, &fim, fila_tamanho);


   elem = 3;
   enqueue (fila, elem, &fim, fila_tamanho);


   elem = 4;
   enqueue (fila, elem, &fim, fila_tamanho);


   printf("%d\n", dequeue (fila, &inic, fila_tamanho));


   printf("%d\n", dequeue (fila, &inic, fila_tamanho));

   free(fila);

   return 0;
}
