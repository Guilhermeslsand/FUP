#include <stdio.h>

int main (void){
  int escolha;
  char sair=0;
  do
  {
    scanf("%d", &escolha);
    switch (escolha)
    {
      case 1:
        printf("Você escolheu 1\n");
      break;

      case 2:
        printf("Você escolheu 2\n");
      break;

      case 0:
      break;

      default:
        printf("Você escolheu o numero errado:");
      break;
    }
  }while(escolha!=0);
}
