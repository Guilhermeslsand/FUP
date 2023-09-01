#include <stdio.h>

int main (void){
  char a;
  printf ("Digite um caracter: ");
  scanf("%c", &a);
  printf ("Numero na tebela ascii: %d", a);
  getchar();
  return(0);
}
