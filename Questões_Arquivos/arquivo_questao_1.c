#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

typedef struct{
    char nome[50];
    int idade;
    char sexo;
}Pessoa;

int tam = 10;
Pessoa lista[10];
int quant = 0;

void salvarEmArquivo(){
    FILE *arq = fopen("lista.txt", "w");
    int i;
    if(arq){
        fprintf(arq, "%d\n", quant);
        for(i = 0; i < quant; i++){
            fprintf(arq, "%s", lista[i].nome);
            fprintf(arq, "%d\n", lista[i].idade);
            fprintf(arq, "%c\n", lista[i].sexo);
        }
        fclose(arq);
    }
    else
        printf("ERRO: nao foi possivel abrir o arquivo.\n\n");
}

void lerDoArquivo(){
    FILE *arq = fopen("lista.txt", "r");
    int i;
    if(arq){
        fscanf(arq, "%d\n", &quant);
        for(i = 0; i < quant; i++){
            Pessoa p;
            fgets(p.nome, 50, arq);
            fscanf(arq, "%d\n", &p.idade);
            fscanf(arq, "%c\n", &p.sexo);
            lista[i] = p;
        }
        fclose(arq);
    }
    else
        printf("ERRO: nao foi possivel abrir o arquivo.\n\n");
}

int cadstrarPessoa(){
  lerDoArquivo();
    if(quant < tam){
        Pessoa p;
        scanf("%*c");
        printf("Nome: ");
        fgets(p.nome, 100, stdin);

        printf("Digite idade e sexo m ou f: ");
        scanf("%d %c", &p.idade, &p.sexo);
        lista[quant] = p;
        quant++;
        salvarEmArquivo();
        return 1;
    }
    else{
        printf("ERRO: vetor cheio.\n\n");
        return 0;
    }
}

void imprimirVetor(){
  int i;
  char *busca;
  busca = (char*)calloc(50,sizeof(char*));
  lerDoArquivo();
  if(busca==NULL)
  {
    printf("Espaço em memória insuficiente\n");
    exit(1);
  }
  getchar();
  printf("Qual nome você quer buscar?\n");
  fgets(busca,50*sizeof(char), stdin);
    for(i = 0; i < 10; i++){
      if(strcmp(busca,lista[i].nome)==0)
      {
        printf("Nome: %s", lista[i].nome);
        printf("Idade: %d\tSexo: %c\n\n", lista[i].idade, lista[i].sexo);
      }
    }
}

int main() {
    int op;

    do{
        printf("\n1 - Cadastrar\n2 - Imprimir\n");
        //printf("3 - Salvar em arquivo texto\n4 - Ler do arquivo texto\n");
        //printf("\n5 - Salvar em arquivo binario\n6 - Ler do arquivo binario\n0 - Sair\n");
        scanf("%d", &op);

        switch(op){
        case 0:
            printf("Tchau...\n\n");
            break;
        case 1:
            cadstrarPessoa();
            break;
        case 2:
            imprimirVetor();
            break;
        //case 3:
            //salvarEmArquivo();
            //break;
        //case 4:
            //lerDoArquivo();
            //break;
        default:
            printf("Opcao invalida.\n\n");
        }

    }while(op != 0);

    return 0;
}
