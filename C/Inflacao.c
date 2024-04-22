#include <stdio.h>

int main (void){
  float preco,inflacao;
  printf("Preco do produto:\n");
  scanf ("%f", &preco);
  switch(preco){
    case < 100:
     inflacao=preco+preco*0.1;
     break;
     defaut:
     inflacao=preco+preco*0.2;
  }
  return(0);
}
