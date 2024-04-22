#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void ler_nome(idade nome){
int idade;
printf ("Digite um nome: \n");
scanf ("%[^\n]d", &idade);
printf("%d\n", &nome);
}

int main (void)
{
  char idade;
  ler_nome (nome);
  printf("%d\n", nome);
  printf("%d\n", &nome);
  return 0;
}
