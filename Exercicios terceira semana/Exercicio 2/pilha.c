#include "pilha.h"

/*Função para criar uma pilha!*/
Pilha* create_stack (int tam) {
  Pilha *p = (Pilha *)malloc(sizeof(Pilha));
  p->topo = 0;
  p->tam = tam;
  p->vetor = (int *)malloc(tam * sizeof(int));
  return p;
}

/*Função para empilhar um elemento!*/
void push (Pilha *p, int elem) {
  if (full_stack(p)) {
    printf ("Pilha cheia\n");
    exit(1);
  }
  p->vetor[p->topo] = elem;
  p->topo++;
}

/*Função para desempilhar um elemento!*/
int pop (Pilha *p) {
  if (empty_stack(p)) {
    printf ("Pilha vazia\n");
    exit(1);
  }
  p->topo--;
  return p->vetor[p->topo];
}

void shuffle (Pilha*p, int number)
{
    int i, hand;
    for (i=0; i<number; i++)
    {
        hand = (rand()%9) + 1;
        push (p, hand);
    }
}

void printHands (Pilha *p, Pilha *p1, int number)
{
    int i;
    printf("jogador 1 = ");
    for (i = 0; i<p->topo; i++)
    {
        printf(" %d", p->vetor[i]);

    }
    printf("\n");
    printf("jogador 2 = ");
    for (i=0; i<p1->topo; i++)
    {
        printf(" %d", p1->vetor[i]);

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
  free(p);
}

