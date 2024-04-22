# include <stdio.h>

int main(void){
  float f;
  float c;
  printf("Temperatura em Celsius: ");
  scanf("%f", &c);
  f = c*9/5+32;
  printf("Temperatura em Fahrereint: %3.2f", f);
  getchar();
  return(0);
}
