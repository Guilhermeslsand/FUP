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
  }

  for(i=0; i<t; i++){
    if(l[i] != '\0'){
      n++;
    }
    printf("%d ", l[i]);
  }

  printf("\n");
  j=t-1;
  for(i=0; i<t/2; i++){
    aux = l[i];
    l[i] = l[j];
    l[j] = aux;
    j--;
  }
  printf("l: ");
  for(i=0; i<t; i++){
  printf("%d ", l[i]);
  }
  printf("\n");
  printf("n:%d\n", n);
  return 0;
}
