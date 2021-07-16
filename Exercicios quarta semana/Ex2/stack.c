#include "stack.h"

/*Função para criar uma pilha vazia (não criar nenhum nó, só devolver NULL)!*/
Stack* create_stack () {
   return NULL;
}

/*Função para liberar uma pilha nó por nó*/
void free_stack (Stack *s) {
   while (s!=NULL)
   {
     Stack *aux = s->next;
     free(s);
     s = aux;
   }
}

/*Função para empilhar um elemento (inserir na cabeça da lista encadeada)!*/
Stack* push (Stack *s, int elem) {
   Stack* novo = (Stack*)malloc(sizeof(Stack));
   novo->info = elem;
   novo->next = s;
   return novo;
}

/*Função para desempilhar um elemento (remover da cabeça da lista encadeada)!*/
Stack* pop (Stack *s) {
   if (empty_stack(s))
  {
   printf("Fila vazia");
   exit(1);
  }
   Stack* v = s;
   s = s->next;
   free(v);
   return s;
}

/*Função para retornar o elemento no topo da pilha (cabeça da lista encadeada) sem desempilhar!*/
int top (Stack *s) {
   if (empty_stack(s)!=1){
   return s->info;
   }
   exit(1);
}

/*Função para testar se uma pilha está vazia!*/
int empty_stack (Stack *s) {
   return (s == NULL);
}
