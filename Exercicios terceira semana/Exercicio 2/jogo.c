#include "pilha.c"

int main () {

   Pilha *p = create_stack(100);
   Pilha *p1 = create_stack(100);
   int i, random;
   srand(time(NULL));

   shuffle(p, 10);
   shuffle(p1, 10);

   printHands(p, p1, 10);
   printf("\n\n");

   int number1, number2;
   while (!(empty_stack(p) || empty_stack(p1)))
   {
       number1 = pop(p);
       number2 = pop(p1);
       if (number1 > number2)
       {
           for (i=0; i<number1-number2; i++)
           {
               if (!empty_stack(p))
               {
                   push(p1, pop(p));
               }
           }
       }
       else if (number2 > number1)
       {
           for (i=0; i<number2-number1; i++)
           {
               if (!empty_stack(p1))
               {
                   push(p, pop(p1));
               }
           }
       }
       printHands(p, p1, 10);
       printf("\n\n");
   }

   if (empty_stack(p))
   {
       printf("Parabens, o jogador 1 foi o vencedor");
   }
   else
   {
       printf("Parabens, o jogador 2 foi o vencedor");
   }
   destroy_stack(p);
   destroy_stack(p1);
   return 0;
}

