#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap (int *vetor, int i, int j)
{
  int temp = vetor[i];
  vetor[i] = vetor[j];
  vetor[j] = temp;
}
/*Função que retorna 1 se a ordenação estiver correta e 0 caso contrário.*/
int Verifica_Ordenacao (int *vetor, int tamanho) {
  int i;
  for (i = 0; i < tamanho-1; i++) {
    if (vetor[i] > vetor[i+1]) {
       return 0;
    }
  }
  return 1;
}

void Imprimir (int *vetor, int tamanho) {
  int i;
  for (i = 0; i < tamanho; i++) {
    printf("%d ", vetor[i]);
  } 
  printf ("\n");
}

int particao(int *vetor, int esq, int dir)
{
  int p = vetor[dir];
  int i = esq-1;
  int j, aux = 0;
  for (j=esq; j<=dir-1; j++)
  {
    if (vetor[j] < p)
    {
      i++;
      swap(vetor, i, j);
    }
  }
  swap(vetor, i+1, j);
  return i+1;
}

void QuickSort (int *vetor, int esq, int dir) {
  if (esq < dir)
  {
    int p = particao(vetor, esq, dir);
    QuickSort(vetor, esq, p-1);
    QuickSort(vetor, p+1, dir);
  }
}

/*Função principal.*/
int main (int argc, char *argv[]) {
   clock_t start, end;
   double elapsed_time;
   srand(time(NULL));
   int i;
   int tamanho = 10;
   int *vetor = (int *)malloc(tamanho * sizeof(int));
   for (i = 0; i < tamanho; i++) {
      vetor[i] = rand() % (tamanho+1);
   }
   Imprimir (vetor, tamanho);
   start = clock();
   QuickSort (vetor, 0, tamanho-1);
   end = clock();
   elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
   printf("Tempo de execução (Quick-Sort): %.2f\n", elapsed_time);
   if (!Verifica_Ordenacao(vetor, tamanho)) {
      printf("Erro: a ordenação não está correta!\n");
   }
   Imprimir (vetor, tamanho);
   free (vetor);
   return 0;
}
