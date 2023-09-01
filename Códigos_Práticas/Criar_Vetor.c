#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *l;
  int aux;
  int t;
  int n;
  int i, j;

  printf("Digite um valor para tamanho do vetor: ");
  scanf("%d", &t);
  l = (int*)malloc(t*sizeof(int));
  if(l == NULL)
  {
    printf("Erro:Espaco insuficiente\n");
    exit(1);
  }

  for(i = 0; i < t; i++)
  {
    printf("Digite o valor: ");
    scanf("%d", &l[i]);
    if(l[i] != '\0')
    {
      n++;
    }
    aux=l[n-1];
  }

  printf("\n");

  for(i=n-1; i>=0; i--){
    l[i]=l[i-1];
    if(i == 0)
    {
      l[i]=aux;
    }
  }
  for(i=0; i<t; i++){
  printf("%d ", l[i]);
  }
  printf("\n");
  printf("%d\n", n);
  return 0;
}
