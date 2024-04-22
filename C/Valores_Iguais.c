#include <stdio.h>

int main (void){
  int x,y,i;
  printf ("Valor de x:\n");
  scanf ("%d", &x);
  printf ("Valor de y:\n");
  scanf ("%d", &y);
  if (x<y){
    for (i=x+1;i<y;++i)
     printf ("\n%d", i);
  }
  else if(x>y){
    for (i=x-1;i>y;--i)
    printf ("\n%d", i);
  }
  else {
    printf ("valores iguais");
  }
  return (0);
}
