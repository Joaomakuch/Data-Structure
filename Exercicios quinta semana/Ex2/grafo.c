#include "grafo.h"

/*Função para criar um grafo representado como uma lista de adjacências com {V} vértices de tamanho.*/
Grafo* criar_grafo (int V) {
  Grafo* grafo = (Grafo*) malloc(sizeof(grafo));
  grafo->V = V;
  grafo->E = 0;
  grafo->list = (No**) malloc(V * sizeof(No*));

  int i;
  for(i = 0; i < V; i++){ 
    grafo->list[i] = NULL;
  }

  return grafo;
}

/*Função para destruir um grafo construído através de uma representação por lista de adjacências.*/
void destruir_grafo (Grafo *G) {
  int i;
  for(i = 0; i < G->V; i++){
    while(G->list[i] != NULL){
      No *no_temp = G->list[i];
      G->list[i] = G->list[i]->next;
      free(no_temp);
    }
  }
  free(G->list);
  free(G);
}

/*Função para imprimir um grafo construído através de uma representação por lista de adjacências.*/
void imprimir_grafo (Grafo *G) {
  int i;
  No *no_auxiliar;
  for(i = 0; i < G->V; i++){
    no_auxiliar = G->list[i];
    printf("\n%d -> ", i);
    while(no_auxiliar != NULL){
      printf("%d ", no_auxiliar->id);
      no_auxiliar = no_auxiliar->next;
    }
  }
}

/*Função para adicionar a aresta (ligação) entre os vértices {u,v} e {v,u} no grafo {G}.*/
/*Adicione um novo vértice sempre no início da lista encadeada do respectivo vértice.*/
/*Você pode dividir essa função em duas se achar necessário!*/
void adicionar_aresta (int u, int v, Grafo *G) {
  No *grafo_u = (No*) malloc(sizeof(No));
  grafo_u->id = v;
  grafo_u->next = NULL;

  if(G->list[u] == NULL) { G->list[u] = grafo_u;}
  else{
    grafo_u->next = G->list[u];
    G->list[u] = grafo_u;
  }

  No *grafo_v = (No*) malloc(sizeof(No));
  grafo_v->id = u;
  grafo_v->next = NULL;

  if(G->list[v] == NULL) { G->list[v] = grafo_v;}
  else{
    grafo_v->next = G->list[v];
    G->list[v] = grafo_v;
  }

  (G->E)++;
}


