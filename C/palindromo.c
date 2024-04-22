#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (void){
  char palavra [50];
  char oposto [50];
  int i, j=0, tam;
  printf("Digite uma palavra\n");
  scanf("%s", palavra);
  for (i=0; palavra[i]!='\0'; i++){
    palavra[i] = toupper(palavra[i]);
  }
  tam = strlen(palavra);
  for(i=tam-1; i>=0; i--){
    oposto[j] = palavra[i];
    ++j;
  }
  if(strcmp(palavra,oposto)==0){
    printf("Eh palindromo");
  }
  else{
    printf("Nao eh palindromo");
  }
}
