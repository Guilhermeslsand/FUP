#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *l;
  int aux;
  int i;
  int t;
  int result;

  printf("Digite um valor PAR para tamanho do vetor: ");
  scanf("%d", &t);
  l = (int*)malloc(t*sizeof(int));
  if(l == NULL)
  {
    printf("Erro:Espaco insuficiente\n");
    exit(1);
  }

  if(t == 2)
  {
    for(i = 0; i < t; i++)
    {
      printf("Digite o valor: ");
      scanf("%d", &l[i]);
    }
    for(i = 0; i < t; i++)
    {
      printf("%d ", l[i]);
    }
  }

  else
  {
    result = (t-1)/2;
    if(result%2 == 0)
    {
      result++;
    }
    for(i = 0; i < t; i++)
    {
      printf("Digite o valor: ");
      scanf("%d", &l[i]);
    }
    for(i = 0; i < t/2; i++)
    {
      if(i%2 == 1)
      {
        aux = l[i];
        l[i] = l[i+result];
        l[i+result] = aux;
      }
    }
    for(i = 0; i < t; i++)
    {
      printf("%d ", l[i]);
    }
  }
  free (l);
  return 0;
}
