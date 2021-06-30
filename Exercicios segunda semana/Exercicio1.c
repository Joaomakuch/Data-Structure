#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int ini;
  int fim;
  int tam;
  int *vetor;
}Fila;

Fila* create_queue (int tam)
{
   Fila *f = (Fila *)malloc(sizeof(Fila));
   f->ini = 0;
   f->fim = 0;
   f->tam = tam;
   f->vetor = (int*)malloc(tam*sizeof(int));
   return f;
}

int empty (Fila *f)
{
   return (f->ini == f->fim);
}

int full (Fila *f)
{
   return (f->ini == ((f->fim + 1) % f->tam));
}

void enqueue (Fila *f, int e)
{
   if (full(f)) {
      printf("fila cheia: capacidade esgotada!");
      exit(1);
   }
   f->vetor[f->fim] = e;
   f->fim = (f->fim +1) % f->tam;
}

int dequeue (Fila *f)
{
  int e;
   if (empty(f))
   {
      printf("fila vazia!");
      exit(1);
   }
   e = f->vetor[f->ini];
   f->ini = (f->ini + 1) % f->tam;
   return e;
}

void free_queue (Fila *f)
{
   free(f->vetor);
   free(f);
}

