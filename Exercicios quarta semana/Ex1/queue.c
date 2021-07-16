#include "queue.h"

/*Função para criar uma fila vazia (não criar nenhum nó, só devolver NULL)!*/
Queue* create_queue () {
   return NULL;
}

/*Função para liberar uma fila nó por nó!*/
void free_queue (Queue *q) {
   while (q!=NULL)
   {
     Queue *aux = q->next;
     free(q);
     q = aux;
   }
}

/*Função para enfileirar um elemento (inserir na cauda da lista encadeada)!*/
Queue* enqueue (Queue *q, int elem) {
   Queue *novo = (Queue*)malloc(sizeof(Queue));
   Queue* aux = q;
   novo->info = elem;
   novo->next = NULL;
   if (empty_queue(q))
   {
     return novo;
   }
   while (aux->next != NULL)
   {
     aux = aux->next;
   }
   aux->next = novo;
   return q;
}

/*Função para desenfileirar um elemento (remover da cabeça da lista encadeada)!*/
Queue* dequeue (Queue *q) {
  if (empty_queue(q))
  {
   printf("Fila vazia");
   exit(1);
  }
   Queue* v = q;
   q = q->next;
   free(v);
   return q;
}

/*Função para retornar o primeiro elemento da fila (cabeça da lista encadeada) sem desenfileirar!*/
int front (Queue *q) {
   if (empty_queue(q)!=1){
   return q->info;
   }
   exit(1);
}

/*Função para testar se uma fila está vazia!*/
int empty_queue (Queue *q) {
   return (q == NULL);
}

