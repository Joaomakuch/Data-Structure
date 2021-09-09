#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

/*Função para contar o número de linhas de um arquivo.*/
int conta_linhas (FILE *arq) {
  int linhas = 0;
  if (arq == NULL) {
    return linhas; 
  }
  while (!feof(arq)) {
    char c;
    fscanf(arq, "%c", &c);
    if (c == '\n') {
      linhas++;
    }
  }
  rewind(arq);
  return (linhas-1);
}

//Busca sequêncial (linear).
int busca_linear (char **dicionario, int linhas, char palavra[]) {
   int i, pos = 0;
   for (i=0; i<linhas; i++)
   {
     if(strcmp(palavra, dicionario[i]) == 0)
     {
       pos = i;
     }
   }
   if (pos == 0)
   {
     return -1;
   }
   else
   return pos+1;
}

//Busca binária iterativa.
int busca_binaria_itr (char **dicionario, int linhas, char palavra[]) {
   int pos = busca_linear(dicionario, linhas, palavra);
   int mid = 0;
   int left = 0;
   int right = linhas;  
    while (mid != pos)
    {
      mid = left + (right-left)/2;
      
     if (mid == pos)
     {
       return mid;
     }

      if (mid > pos)
      {
        right = mid-1;
      }
      else
      {
        left = mid+1;
      }
    }
   return -1;
}

//Busca binária recursiva.
int busca_binaria_rec (char **dicionario, int esq, int dir, char palavra[]) {

  int pos = busca_linear(dicionario, dir, palavra);
   if (dir >= 1)
   {
     int mid = esq + (dir-esq)/2;

     if (mid == pos)
     {
       return mid;
     }

     if (mid > pos)
     {
       return busca_binaria_rec (dicionario, esq, mid-1, palavra);
     }

     else
     {
       return busca_binaria_rec (dicionario, mid+1, dir, palavra);
     }
   }
   return -1;
}

/*Função principal.*/
int main (int argc, char *argv[]) {

   int nbuscas = 1;

   int p;

   clock_t start, end;
  
   double elapsed_time;

   /*Abrindo o arquivo:*/
   FILE *arq = fopen("palavras.txt","r");

   /*Contando o número de linhas do arquivo:*/
   int linhas = conta_linhas(arq);
   
   /*Alocando memória para armazenar as palavras:*/
   char **dicionario = (char **)malloc(linhas * sizeof(char *));
   int i;
   for (i = 0; i < linhas; i++) {
      dicionario[i] = (char *)malloc(256 * sizeof(char));
   }
  
   /*Lendo as dicionario do arquivo:*/
   i = 0;
   while (!feof(arq)) {
      fscanf(arq, "%s", dicionario[i]);     
      i++;
   }

   /*Lendo a palavra a ser pesquisada:*/
   printf("Pesquise a palavra: ");
   char palavra[256]; 
   scanf("%s", palavra);

   /*Executando os algoritmos busca sequêncial:*/
   for (i = 0; i < nbuscas; i++){
      p = busca_linear (dicionario, linhas, palavra);
      if (p != -1){
         printf("Achei a palavra %s no dicionário na posição %d!\n", palavra, p);
      }
      else {
         printf("Não achei a palavra %s no dicionário!\n", palavra);
      }
   }   

   /*------------------------------------------------*/
   /*Executando os algoritmo busca binária iterativo:*/
   for (i = 0; i < nbuscas; i++){
      p = busca_binaria_itr (dicionario, linhas, palavra);
      if (p != -1){
         printf("Achei a palavra %s no dicionário na posição %d!\n", palavra, p);
      }
      else {
         printf("Não achei a palavra %s no dicionário!\n", palavra);
      }
   }  

   /*------------------------------------------------*/
   /*Executando o algoritmo de busca binária recursivo:*/
   for (i = 0; i < nbuscas; i++){
      p = busca_binaria_rec (dicionario, 0, linhas-1, palavra);
      if (p != -1){
         printf("Achei a palavra %s no dicionário na posição %d!\n", palavra, p);
      }
      else {
         printf("Não achei a palavra %s no dicionário!\n", palavra);
      }
   }  

   /*------------------------------------------------*/
   /*Liberando a memória:*/
   for (i = 0; i < linhas; i++) {
      free(dicionario[i]);
   }
   free(dicionario);
   fclose(arq);
   return 0;
}

