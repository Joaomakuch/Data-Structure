#include <stdio.h>
#include <stdlib.h>

typedef struct _fila {
   int ini;
   int fim;
   int tam;
   int *vetor;
} Fila;

Fila* criar_fila (int tamanho)
{
  Fila*fila = (Fila*)malloc(sizeof(Fila));
  fila->ini = 0;
  fila->fim = 0;
  fila->tam = tamanho;
  fila->vetor = (int*)malloc(tamanho*sizeof(int));
}

void destruir_fila (Fila *f)
{
  free(f->vetor);
  free(f);
}

void enqueue (Fila *f, int elemento)
{
  f->vetor[f->fim] = elemento;
  (f->fim)++;
}

int dequeue (Fila *f)
{
  int elemento;
  elemento = f->vetor[f->ini];
  (f->ini)++;
  return elemento;
}

int main () {

   Fila *fila = criar_fila (10);

   int elem = 1;
   enqueue (fila, elem);

   elem = 2;
   enqueue (fila, elem);

   elem = 3;
   enqueue (fila, elem);

   elem = 4;
   enqueue (fila, elem);

   printf("%d\n", dequeue (fila));

   printf("%d\n", dequeue (fila));

   destruir_fila (fila);

   return 0;
}
