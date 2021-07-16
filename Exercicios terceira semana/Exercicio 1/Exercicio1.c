#include <string.h>
#include "pilha.c"

int main () {

  Pilha *p = create_stack(30);
  char *seq = "( [ ) ]";
   int i = 0;

   while (seq[i] != '\0') {
      printf ("%c", seq[i]);
      push(p, seq[i]);
      i++;
   }
   printf("\n\n");
   checkStack (p, i);
   destroy_stack (p);

   return 0;
}
