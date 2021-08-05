#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int minIndex(int *vetor, int i, int j)
{
  if (i == j)
  {
    return i;
  }

  int k = minIndex(vetor, i+1, j);

  if (vetor[i] < vetor[k])
  {
    return i;
  }
  else
  {
    return k;
  }
}

void BubbleSort (int *vetor, int tamanho) {
    if (tamanho == 1)
    {
      return;
    }

    int i, aux = 0;
    for (i = 0; i<tamanho-1; i++)
    {
      if (vetor[i] > vetor[i+1])
      {
        aux = vetor[i];
        vetor[i] = vetor[i+1];
        vetor[i+1] = aux;
      }
    }
    BubbleSort(vetor, tamanho-1);
}
 
void SelectionSort (int *vetor, int tamanho, int index) {
    if (index == tamanho)
    {
      return;
    }

    int aux = minIndex(vetor, index, tamanho - 1);
    int temp = 0;

    if (aux != index)
    {
      temp = vetor[aux];
      vetor[aux] = vetor[index];
      vetor[index] = temp;
    }
    SelectionSort(vetor, tamanho, index + 1);
}

void InsertionSort (int *vetor, int tamanho) {
    if (tamanho <= 1)
    {
      return;
    }

    InsertionSort(vetor, tamanho-1);

    int aux = vetor[tamanho-1];
    int j = tamanho-2;

    while(j >= 0 && vetor[j] > aux)
    {
      vetor[j+1] = vetor[j];
      j--;
    }
    vetor[j+1] = aux;
}

void Imprimir (int *A, int tamanho) {
  int i;
  for (i = 0; i < tamanho; i++) {
    printf("%d, ", A[i]);
  }
  printf("\n");
}

/*Função que retorna 1 se a ordenação estiver correta e 0 caso contrário.*/
int Verifica_Ordenacao (int *A, int tamanho) {
  int i;
  for (i = 0; i < tamanho-1; i++) {
    if (A[i] > A[i+1]) {
       return 0;
    }
  }
  return 1;
}


int main () {

  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));

  int i;
  int index = 0;
  

  int tamanho = 10;

  int *v1 = (int *)malloc(tamanho * sizeof(int));
  int *v2 = (int *)malloc(tamanho * sizeof(int));
  int *v3 = (int *)malloc(tamanho * sizeof(int));

  for (i = 0; i < tamanho; i++) {
     v1[i] = rand() % (tamanho+1);
     v2[i] = rand() % (tamanho+1);
     v3[i] = rand() % (tamanho+1);
  }  

  start = clock();
  Imprimir(v1, tamanho);
  BubbleSort (v1, tamanho);
  Imprimir(v1, tamanho);
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Tempo de execução (BubbleSort): %.2f\n", elapsed_time);
  if (!Verifica_Ordenacao(v1, tamanho)) {
     printf("Erro: a ordenação do BubbleSort não está correta!\n");
  }

  start = clock();
  Imprimir(v2, tamanho);
  SelectionSort (v2, tamanho, index);
  Imprimir(v2, tamanho);
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Tempo de execução (SelectionSort): %.2f\n", elapsed_time);
  if (!Verifica_Ordenacao(v2, tamanho)) {
     printf("Erro: a ordenação do SelectionSort não está correta!\n");
  }

  start = clock();
  Imprimir(v3, tamanho);
  InsertionSort (v3, tamanho);
  Imprimir(v3, tamanho);
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Tempo de execução (InsertionSort): %.2f\n", elapsed_time);
  if (!Verifica_Ordenacao(v3, tamanho)) {
     printf("Erro: a ordenação do InsertionSort não está correta!\n");
  }
 
  free (v1);
  free (v2);
  free (v3);

  return 0;
}

