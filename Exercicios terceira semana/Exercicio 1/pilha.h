#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct pilha{
  int topo;
  int tam;
  int *vetor;
  char *vetorString;
} Pilha;


Pilha* create_stack (int tam);

void push (Pilha *p, int elem);

int pop (Pilha *p);

void checkStack (Pilha *p, int i);

int empty_stack (Pilha *p);

int full_stack (Pilha *p);

void destroy_stack (Pilha *p);
