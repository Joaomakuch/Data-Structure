#include "queue.c"

int main()
{
  Fila *fila[2];
  int i, j;
  float prize = 0;

  srand(time(NULL));

for (i = 0; i < 3; i++)
{
  fila[i] = create_queue(11);
}
  for (i = 0; i < 3; i++)
    for (j=0; j<10; j++)
      {
         enqueue(fila[i], j);
      }
  int random = 0;
  int a = 0;
  int winner[3];

 do
 {
  for (i = 0; i < 3; i++)
  {
    random = (rand()%9) +1;
    for (j = 0; j < random; j++)
    {
      enqueue(fila[i], dequeue(fila[i]));
    }
    printVet (fila[i], i, winner);
  }

  if (winner[0] == winner[1] && winner[1] == winner[2])
  {
    printf("\n\n****WINNER****");
    printf("\nPrize = R$%.2f", prize);
    break;
  }

  printf("\n");
  prize = prize + 50;

  //sleep(1);
 }while(a == 0);

 for (i=0; i < 3; i++)
 {
   free_queue(fila[i]);
 }

return 0;
}
