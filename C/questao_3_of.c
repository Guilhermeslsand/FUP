#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *l, *met;
    int t;
    int i;
    int j = 0;
    int aux;

    printf("Digite um valor PAR para tamanho do vetor: ");
    scanf("%d", &t);
    l = (int*)malloc(t*sizeof(int));
    if(l == NULL)
    {
      printf("Erro:Espaco insuficiente\n");
      exit(1);
    }
    met = (int*)malloc(t*sizeof(int));
    if(met == NULL)
    {
      printf("Erro:Espaco insuficiente\n");
      exit(1);
    }
    for(i = 0; i < t; i++)
    {
      printf("Digite o valor: ");
      scanf("%d", &l[i]);
      if(i>=(t+1)/2)
      {
        met[j] = l[i];
        j++;
      }
    }
    j=0;
    for(i=t-2; i>0; i--)
    {
        if(i<=t/2)
        {
          l[i+i] = l[i];
        }
    }
    for(i = 0; i < t; i++)
    {
      if(i%2==1)
      {
        l[i] = met[j];
        j++;
      }
      printf("%d ",l[i]);
    }
    free (l);
    return 0;
  }
