#include "deck.h"

Deck* createDeck () {
  return NULL;
}

/*Função que retorna a coordenada armazenada na cabeça da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Point getFront (Deck *d) {
   return d->p;
}

/*Função que retorna a coordenada armazenada na cauda da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Point getRear (Deck *d) {
   Deck *aux = d;
   while(aux->next!=NULL)
   {
     aux = aux->next;
   }
   return aux->p;
}

/*Função para inserir na cabeça da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Deck* insertFront (Deck *d, Point p, char field[][SIZE]) {
   Deck *insert = (Deck*)malloc(sizeof(Deck));
   field[p.x][p.y] = '*'; 
   insert->next = NULL;
   insert->prev = NULL;
   insert->p = p;
   if(d!=NULL)
   {
     d->prev = insert;
     insert->next = d;
   }
   return insert;
}

/*Função para inserir na cauda da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Deck* insertRear (Deck *d, Point p, char field[][SIZE]) {
   Deck *insert = (Deck*)malloc(sizeof(Deck));
   field[p.x][p.y] = '*';  
   insert->next = NULL;
   insert->prev = NULL;
   insert->p = p;
   if(d!=NULL)
   {
     Deck* aux = d;
     while(d->next != NULL)
     {
       d = d->next;
     }

     insert->prev = d;
     d->next = insert;

     return aux;
   } 

   return insert;
}

/*Função para remover a cabeça da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Deck* deleteFront (Deck *d, char field[][SIZE]) {
   Deck *remove = d;
   field[remove->p.x][remove->p.y] = ' '; 
   d = d->next;
   d->prev = NULL;
   free(remove);
   return d;
}

/*Função para remover a cauda da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Deck* deleteRear (Deck *d, char field[][SIZE]) {
   Deck *remove = d;
   while(remove->next != NULL)
   {
     remove = remove->next;
   }
   field[remove->p.x][remove->p.y] = ' '; 
   (remove->prev)->next = NULL;
   free(remove);
   return d;
}


