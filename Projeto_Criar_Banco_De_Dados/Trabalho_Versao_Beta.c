#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct{
  int idade;
  float altura;
  char nome[50];
}pessoa;

void menu_principal (){
  printf("*****************************************************\n");
  printf("******BEM VINDO AO BANCO DE DADOS DO GUILHERME*******\n");
  printf("*****************************************************\n");
  printf("***1 - Inserir dados de uma pessoa.\n");
  printf("***2 - Imprimir dados de uma pessoa.\n");
  printf("**Digite sua escolha: ");
}

void gravar_dados (pessoa p[10]){
  static int i = 0;
  scanf("%s*[^\n]", &p[i].nome);
  scanf("%d", &p[i].idade);
  scanf("%f", &p[i].altura);
  i++;
}

int main (void){
  int escolha;
  char busca[50];
  static int i =0;
  int j = 0;
  pessoa p[10];
  do
  {
    menu_principal();
    scanf("%d", &escolha);
    switch (escolha)
    {
      case 1:
        gravar_dados(p);
        printf("%s\n", p[i].nome);
        printf("%d\n", p[i].idade);
        printf("%f\n", p[i].altura);
        i++;
        printf("\n\n");
      break;

      case 2:
        printf("Qual nome você quer buscar?\n");
        scanf("%s%*[^\n]", &busca);
        for(j = 0; j<10; j++)
        {
          if(strcmp(busca,p[j].nome)==0)
          {
            printf("%s\n%d\n%f\n", p[j].nome, p[j].idade, p[j].altura);
          }
        }
        printf("\n\n");
      break;

      case 0:
      break;

      default:
      printf ("\nNumero invalido");
      printf("\n\n");
      break;
    }
  }while(escolha!=0);
return 0;
}
