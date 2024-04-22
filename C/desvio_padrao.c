/* prog25.c
 Cria um vetor dinâmico de tamanho 'n',
 lê valores e calcula soma e media.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
 float *vet, media, xi, desvio = 0, dif, soma = 0;
 int n, i;
 printf("Numero de elementos do vetor: ");
 scanf("%d", &n);
 vet = (float*) malloc(n*sizeof(float));
 if(vet==NULL){
 printf("Sem Memoria!\n");
 return(1);
 }
 for(i=0;i<n;i++){
 printf("[%d]: ", i);
 scanf("%f", &vet[i]);
 soma += vet[i];
 }
 media=(float)soma/n;
 for(i=0; i<n; i++){
   dif += pow((vet[i]-media),2);
 }
 desvio = sqrt(dif/n);
 printf("Soma: %0.2f\nMedia: %2.1f\nDesvio Padrao: %0.4f\n", soma, media, desvio);
 free(vet);
 //fflush(stdin);
 getchar();
 return(0);
}
