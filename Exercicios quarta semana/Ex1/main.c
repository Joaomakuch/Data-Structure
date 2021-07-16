#include "queue.h"

int main () {
  int i, m, n, j;
  printf("Josephus - digite o passo da morte e numero de competidores: ");
  scanf("%d %d", &m, &n);
  Queue *q = create_queue ();
  for (i = 1; i <= n; i++)
  {
    q = enqueue(q, i);
  }
  for (i = 1; i<n; i++)
  {
    for (j = 1; j < m; j++)
    {
      q = enqueue(q, front(q));
      q = dequeue(q);
    }
    printf("%d\t", front(q));
    q = dequeue(q);
  }
  printf("\n Numero sobrevivente: %d", front(q));
  free_queue (q);
  return 0;
}