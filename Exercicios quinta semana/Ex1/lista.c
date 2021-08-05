#include "lista.h"

int conta_nos_itr (Lista* lista) {
   Lista *tmp;
   int i = 0;
   for (tmp = lista; tmp != NULL; tmp=tmp->next)
   {
     i++;
   }
   return i;
}

int conta_nos_rec (Lista* lista) {
  
  if (lista==NULL){
    return 0;
  }
  else
  return conta_nos_rec (lista->next) + 1;
}

int procura_itr (Lista* lista, int elemento) {
   Lista *tmp;
   int i = 0;
   for (tmp = lista; tmp != NULL; tmp=tmp->next)
   {
     i++;
     if (tmp->info == elemento)
     {
       break;
     }
   }
   i = i-1;
   return i;
}

int procura_rec (Lista* lista, int elemento) {
  if(lista == NULL) { return -1; }
  if(lista->info == elemento) { return 0; }
  else if(procura_rec(lista->next, elemento) == -1) { return -1; }
  return procura_rec(lista->next, elemento) + 1;
}

int lista_max_itr (Lista* lista) {
   Lista *tmp;
   int maior = 0;
   
   for (tmp = lista; tmp != NULL; tmp=tmp->next)
   {
     if (tmp->info > maior)
     {
       maior = tmp->info;
     }
   }
   return maior;
}

//Você pode usar outras funções aqui se achar necessário!
int lista_max_rec (Lista* lista) {
  Lista *tmp;
   int maior = 0;
   
   for (tmp = lista; tmp != NULL; tmp=tmp->next)
   {
     if (tmp->info > maior)
     {
       maior = tmp->info;
     }
   }
   return maior;
}

int lista_soma_itr (Lista* lista) {
   Lista *tmp;
   int soma = 0;

   for (tmp = lista; tmp != NULL; tmp=tmp->next)
   {
     soma = soma + tmp->info;
   }
   return soma;
}

int lista_soma_rec (Lista* lista) {
  if (lista == NULL){
    return 0;
  }
  return lista->info + lista_soma_rec(lista->next);
}

//Você pode usar outras funções aqui se achar necessário!
void imprimir_invertida_itr (Lista* lista) {
   Lista *tmp;
   int nos = conta_nos_itr(lista);
   int vet[nos];
  
   int i = 1;
   int j;
   for (tmp = lista; tmp != NULL; tmp=tmp->next)
   {
     vet[i] = tmp->info;
     i++;
   }
   for(j = nos; j>0; j--)
   {
     printf("%d ", vet[j]);
   }
   
   
}

void imprimir_invertida_rec (Lista* lista) {
   if (lista != NULL) {
      imprimir_invertida_rec (lista->next);
      printf ("%d ", lista->info);      
   }	   
}

/*Função para criar uma lista encadeada vazia!*/
Lista* criar_lista (void) {
   return NULL;
}

/*Função para inserir um elemento na cabeça de uma lista encadeada!*/
Lista* inserir (Lista *lista, int elem) {
   Lista *novo =(Lista*)malloc(sizeof(Lista));
   novo->info = elem;
   novo->next = lista;
   return novo;
}

/*Função para imprimir uma lista encadeada!*/
void imprimir_lista (Lista *lista) {
   Lista *v; /*var. para percorrer a lista*/
   printf("Lista: ");
   for (v = lista; v != NULL; v = v->next) {
      printf("%d ", v->info);
   }
   printf("\n");
}

/*Função para desalocar uma lista encadeda!*/
void destruir_lista (Lista *l) {
  Lista *aux;
  while (l != NULL) {
    aux = l->next;
    free(l);
    l = aux;
  }
}

