#include <stdio.h>
#include <stdlib.h>
int main (void)
{
int *p, a, i;
a = 30;
p=(int *)malloc(a*sizeof(int));
if (p==NULL)
{
printf("** Erro: Memoria Insuficiente **");
return(1);
}
for (i=0; i<a ; i++)
{
  p[i] = i*i;
  a = 100;
  p = (int *)realloc (p, a*sizeof(int));
  if (p==NULL)
  {
    printf ("\nErro: memoria insuficiente\n");
    return (1);
  }
  printf("%d\n", p[i]);
}
}
