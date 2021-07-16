#include "pilha.h"

/*Função para criar uma pilha!*/
Pilha* create_stack (int tam)
{
  Pilha *p = (Pilha *)malloc(sizeof(Pilha));
  p->topo = 0;
  p->tam = tam;
  p->vetor = (int *)malloc(tam * sizeof(int));
  p->vetorString = (char *)malloc(tam*sizeof(char));
  return p;
}

/*Função para empilhar um elemento!*/
void push (Pilha *p, int elem) {
  if (full_stack(p)) {
    printf ("Pilha cheia\n");
    exit(1);
  }
  p->vetorString[p->topo] = elem;
  p->topo++;
}

/*Função para desempilhar um elemento!*/
int pop (Pilha *p) {
  if (empty_stack(p)) {
    printf ("Pilha vazia\n");
    exit(1);
  }
  p->topo--;
  return p->vetorString[p->topo];
}

void checkStack (Pilha *p, int i)
{
  int j, a=0, b=0, c=0, d=0;

  if (p->vetorString[0] == ')' || p->vetorString[0] == ']')
  {
      printf("Mal formada");
      exit(1);
  }
  if (p->vetorString[i-1] == '(' || p->vetorString[i-1] == '[')
  {
      printf("Mal formada");
      exit(1);
  }
  for (j = 0; j < i; j++)
  {
    if (p->vetorString[j] == '(' && p->vetorString[j+2] == ']')
    {
        printf("Mal formada");
        exit(1);
    }
    if (p->vetorString[j] == '[' && p->vetorString[j+2] == ')')
    {
        printf("Mal formada");
        exit(1);
    }
    if (p->vetorString[j] == '[')
    {
      a++;
    }
    if (p->vetorString[j] == ']')
    {
      b++;
    }
    if (p->vetorString[j] == '(')
    {
      c++;
    }
    if (p->vetorString[j] == ')')
    {
      d++;
    }
  }
  if (a == b && c == d)
  {
    printf("Bem formada");
  }
  else
  {
    printf("Mal formada");
  }
}

/*Função para liberar a memória alocada.*/
int empty_stack (Pilha *p) {
  return (p->topo ==  0);
}

/*Funão para testar se a pilha está cheia!*/
int full_stack (Pilha *p) {
  return (p->topo == p->tam);
}

/*Funão para testar se a pilha está vazia!*/
void destroy_stack (Pilha *p) {
  free(p->vetor);
  free(p->vetorString);
  free(p);
}

