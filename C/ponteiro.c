#include <stdio.h>

int main (void){
  int a, c = 10;
  int *b;
  a = 10;
  printf("Valor de a %d\n", a);
  b = &a;
  *b = 25;
  b = &c;
  printf("Valor de a %d\n", a);
  printf("Valor de b %d\n", *b);
  return 0;
}
