#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
/*Definino nome para o arquivo*/
#define FILE_NAME "arquivo_dados.txt"

/*Essa struct do programa*/
struct pessoa
{
  char nome[150];
  char telefone[15];
  char cpf[15];
  int idade;
  float altura;
  int dia, mes, ano;
};

/***VARIAVEIS GLOBAIS***/
//Ponteiro para fazer o vetor de struct.
struct pessoa *p;
// Struct para ter o controle e evitar bugs.
struct pessoa pes;
// Ponteiro para arquivo.
FILE *arq;
//Contralar laco for.
int i=0;
//Controlar numero de fichas.
int n_fichas;
//Serve para controlar o lopp do while em algumas funcoes.
int cont = 0 ;
//Serve para tomar decisao para buscar uma ficha em algumas funcoes.
int opcao;
// Tamanho para alocar memoria para o vetor
int tam_vet = 100;
// tamnho do char nome na strcut
int tam_nome = 150;
// Tamanho do char telefone na struct
int tam_tel = 15;
// Tamanho do char cpf ma struct
int tam_cpf = 15;

/*FUNCOES DO PROGRAMA*/
struct pessoa alteraracao_ficha();
int validar_pessoa();
int validar_telefone();
int validar_cpf();
void* alocar_memoria_vetor();
void lerDoArquivo();
void salvarEmArquivo();
void menu_principal();
void forma_busca ();
void gerar_ficha ();
void buscar_ficha();
void excluir_ficha ();
void alterar_ficha();
void imprimir_ficha();

/*Funcao Main*/
int main ()
{
int input;
p = alocar_memoria_vetor(p);
do
{
  menu_principal();
  scanf("%d", &input);
  switch(input)
  {
    case 0:
      printf("Tchau...\n");
      printf("Créditos:\n");
      printf("Guilherme Sales de Andrade-473995\n");
      printf("Gabriel Laurindo-495579\n");
      printf("Paulo Douglas Sousa dos Santos-510163\n");
      printf("José Hyrton Dantas carneiro Neto-494335\n");
      printf("José Ricardo Mesquita dos Santos-497170\n");
    exit(EXIT_SUCCESS);

    case 1:
      lerDoArquivo();
      gerar_ficha();
      salvarEmArquivo();
    break;

    case 2:
      lerDoArquivo();
      buscar_ficha();
      salvarEmArquivo();
    break;

    case 3:
      lerDoArquivo();
      excluir_ficha();
      salvarEmArquivo();
    break;

    case 4:
      lerDoArquivo();
      alterar_ficha();
      salvarEmArquivo();
    break;

    case 5:
      lerDoArquivo();
      imprimir_ficha();
      salvarEmArquivo();
    break;

    default:
      printf ("\nNumero invalido");
      printf("\n\n");
    break;
    }

  }while(input != 0);
  free(p);
  return 0;
}

/*Funcao para alocar memoria de um vetor*/
void* alocar_memoria_vetor (void* pont)
{
  pont = (size_t*) malloc(tam_vet * sizeof(size_t));
  if( pont == NULL)
  {
    printf("Erro: Espaco em memoria insuficiente\n");
    exit(1);
  }
  return pont;
}

/*Funcao para ler dados do arquivo. Caso nao ter para abrir como leitura
� criado o arquivo do zero*/
void lerDoArquivo ()
{
  int l = 0,j=0;
  arq = fopen(FILE_NAME, "r");
  if(arq)
  {
    fscanf(arq, "%d\n", &n_fichas);
    for(i=0; i<n_fichas; i++)
    {
      fgets(pes.nome, tam_nome, arq);
      fscanf(arq, "%f\n", &pes.altura);
      fscanf(arq, "%d\n", &pes.idade);
      fgets(pes.cpf, tam_cpf, arq);
      fgets(pes.telefone, tam_tel, arq);
      fscanf(arq, "%d\n", &pes.dia);
      fscanf(arq, "%d\n", &pes.mes);
      fscanf(arq, "%d\n", &pes.ano);
      p[i] = pes;
    }
    fclose(arq);
  }

  else
  {
    arq = fopen(FILE_NAME, "w+");
    if(arq)
    {
      fscanf(arq, "%d\n", &n_fichas);
      for(i = 0; i < n_fichas; i++)
      {
        fgets(pes.nome, tam_nome, arq);
        fscanf(arq, "%f\n", &pes.altura);
        fscanf(arq, "%d\n", &pes.idade);
        fgets(pes.cpf, tam_cpf, arq);
        fgets(pes.telefone, tam_tel, arq);
        fscanf(arq, "%d\n", &pes.dia);
        fscanf(arq, "%d\n", &pes.mes);
        fscanf(arq, "%d\n", &pes.ano);
        p[i] = pes;
      }
      fclose(arq);
    }

    else
    {
      printf("Erro na abertura do arquivo\n");
    }

  }

}

/*Funcao para salvar dados no arquivo*/
void salvarEmArquivo ()
{
  arq = fopen(FILE_NAME, "w");
  if(arq)
  {
    fprintf(arq, "%d\n", n_fichas);
    for(i = 0; i < n_fichas; i++)
    {
      fprintf(arq, "%s", p[i].nome);
      fprintf(arq, "%1.2f\n", p[i].altura);
      fprintf(arq, "%d\n", p[i].idade);
      fprintf(arq, "%s", p[i].cpf);
      fprintf(arq, "%s", p[i].telefone);
      fprintf(arq, "%d\n", p[i].dia);
      fprintf(arq, "%d\n", p[i].mes);
      fprintf(arq, "%d\n", p[i].ano);
    }
    fclose(arq);
  }

  else
  {
    printf("ERRO: nao foi possivel abrir o arquivo.\n\n");
  }
}

void menu_principal ()
{
  printf("\n");
  printf ("\t\t\t\t  Bancos de Dados\n");
  printf ("\t\t\t\t   Menu de Dados\n");
  printf ("\t\t\t=================================\n");
  printf ("\t\t\t|\t                        |\n");
  printf("\t\t\t| 1 - Criar Uma Ficha           |\n");
  printf("\t\t\t| 2 - Buscar Uma Fihca          |\n");
  printf("\t\t\t| 3 - Excluir Uma Ficha         |\n");
  printf("\t\t\t| 4 - Alterar Uma Ficha         |\n");
  printf("\t\t\t| 5 - Imprimir Todas as Fichas  |\n");
  printf("\t\t\t| 0 - Sair                      |\n");
  printf ("\t\t\t|\t                        |\n");
  printf ("\t\t\t=================================\n");
  printf ("\n\n");
  printf("\t\t\tPor favor, selecione uma opcao: ");
}

int validar_pessoa()
{
  for(i = 0; i < n_fichas; i++)
  {
    if(strcmp(pes.nome,p[i].nome) == 0 && pes.dia == p[i].dia
    && pes.mes == p[i].mes && pes.ano == p[i].ano)
    {
      printf("\nEssa pessoa j� foi cadastrada\n");
      cont = 1;
      break;
    }

    else
    {
      cont = 0;
    }
  }
  return cont;
}

int validar_cpf()
{
  for(i = 0; i < n_fichas; i++)
  {
    if(strcmp(pes.cpf,p[i].cpf) == 0)
    {
      printf("\nEsse cpf ja foi cadastrado\n\n");
      cont = 1;
      break;
    }
    else
    {
      cont = 0;
    }
  }
  return cont;
}

int validar_telefone()
{
  for(i = 0; i < n_fichas; i++)
  {
    if(strcmp(pes.telefone ,p[i].telefone)==0)
    {
      printf("\nEsse telefone ja foi cadastrado\n\n");
      cont = 1;
    }
  }
  return cont;
}

/*Funcao para fazer as fichas das pessoas*/
void gerar_ficha ()
{
  if(n_fichas < tam_vet)
  {
    do
    {
      printf("\nDigite o Nome:\n");
      getchar();
      fgets(pes.nome, tam_nome, stdin);

      for(int j = 0; j < tam_nome; j++)
      {
        pes.nome[j] = toupper(pes.nome[j]);
      }

      printf("Digite a data de Nascimento: (Exemplo: 1 1 2000)\n");
      scanf("%d %d %d", &pes.dia, &pes.mes, &pes.ano);
      cont = validar_pessoa();
    }while(cont!=0);

    printf("Digite a Altura:\n");
    scanf("%f", &pes.altura);
    printf("Digite a Idade:\n");
    scanf("%d", &pes.idade);

    do
    {
      printf("Digite o CPF:\n");
      getchar();
      fgets(pes.cpf, tam_cpf, stdin);
      cont = validar_cpf();
    }while(cont!=0);

    do
    {
      printf("Digite o Telefone: (Exemplo: 98000-0000)\n");
      fgets(pes.telefone, tam_tel, stdin);
      cont = validar_telefone();
    }while(cont!=0);

    p[n_fichas] = pes;
    n_fichas++;
  }

  else
  {
    printf("\nVetor cheio\n");
  }

  printf("\nNumero de fichas: %d", n_fichas);
  printf("\n\n\n\n");
}

/*Funcao para definir como vai ser feita a busca: por Id ou por nome*/
void forma_busca ()
{
  do
  {
    printf("Por favor, selecione uma opcao:  ");
    scanf("%d", &opcao);
    switch (opcao)
    {
      case 1:
        printf("\nQual nome voce quer buscar?\n");
        getchar();
        fgets(pes.nome, tam_nome, stdin);
        for(i = 0; i < tam_nome; i++)
        {
          pes.nome[i] = toupper(pes.nome[i]);
        }
      break;

      case 2:
        printf("\nQual cpf voce quer buscar?\n");
        getchar();
        fgets(pes.cpf, tam_cpf, stdin);
      break;

      default:
        printf("\nOpcao invalida\n");
      break;
    }
  }while(opcao < 1 || opcao > 2);
}

/*Funcao para imprimir a ficha desejada*/
void buscar_ficha()
{
  printf("\n1 - Buscar por nome.\n");
  printf("2 - Buscar por cpf.\n");
  forma_busca();
  switch(opcao)
  {
    case 1:
      for(i = 0; i < n_fichas; i++)
      {
        if(strcmp(pes.nome,p[i].nome)==0)
        {
          printf("\nNOME --- %s", p[i].nome);
          printf("ALTURA --- %1.2f\n", p[i].altura);
          printf("IDADE --- %d\n", p[i].idade);
          printf("CPF --- %s", p[i].cpf);
          printf("TELEFONE --- %s", p[i].telefone);
          printf("NASCIMENTO --- %d/%d/%d\n", p[i].dia, p[i].mes, p[i].ano);
        }
      }
    break;

    case 2:
      for(i = 0; i < tam_vet; i++)
      {
        if(strcmp(pes.cpf,p[i].cpf)==0)
        {
          printf("\nNOME --- %s", p[i].nome);
          printf("ALTURA --- %1.2f\n", p[i].altura);
          printf("IDADE --- %d\n", p[i].idade);
          printf("CPF --- %s", p[i].cpf);
          printf("TELEFONE --- %s", p[i].telefone);
          printf("NASCIMENTO --- %d/%d/%d\n", p[i].dia, p[i].mes, p[i].ano);
        }
      }
    break;

    default:
    break;
  }
  printf("\nNumero de fichas: %d", n_fichas);
  printf("\n\n\n\n");
}

/*Funcao para excluir os dados de uma ficha escolhida*/
void excluir_ficha ()
{
  printf("\n1 - Buscar por nome.\n");
  printf("2 - Buscar por id.\n");
  forma_busca();
  switch(opcao)
  {
    case 1:
      for(i = 0; i < tam_vet; i++)
      {
        if(strcmp(p[i].nome,pes.nome) == 0)
        {
          printf("\nEssa eh a ficha que vai ser excluida\n");
          printf("O nome eh: %s", p[i].nome);
          printf("O cpf eh: %s", p[i].cpf);
          while(i<n_fichas)
          {
            p[i] = p[i+1];
            i++;
          }
          n_fichas--;
        }
      }
    break;

    case 2:
      for(i = 0 ; i < tam_vet; i++)
      {
        if(strcmp(pes.cpf,p[i].cpf) == 0)
        {
          printf("\nEssa � a ficha que vai ser excluida\n");
          printf("O nome eh: %s", p[i].nome);
          printf("O cpf eh: %s", p[i].cpf);
          while(i<n_fichas)
          {
            p[i] = p[i+1];
            i++;
          }
          n_fichas--;
        }
      }
    break;

    default:
    break;
  }
  printf("\nNumero de fichas: %d", n_fichas);
  printf("\n\n\n\n");
}

/*Funcao que altera os dados da fun��o encontrada*/
struct pessoa alteraracao_ficha()
{
  printf("\nO nome atual eh: %s", p[i].nome);
  printf("Digite o novo nome:\n");
  fgets(pes.nome,tam_nome,stdin);
  for(int j = 0; j < tam_nome; j++)
  {
    pes.nome[j] =  toupper(pes.nome[j]);
  }
  printf("\nA data atual eh: %d/%d/%d\n", p[i].dia, p[i].mes, p[i].ano);
  printf("Digite a nova data de nascimento:\n");
  scanf("%d %d %d", &pes.dia, &pes.mes, &pes.ano);
  printf("\nA altura atual eh: %2.2f\n", p[i].altura);
  printf("Digite a nova altura:\n");
  scanf("%f", &pes.altura);
  printf("\nA idade atual eh: %d\n", p[i].idade);
  printf("Digite a nova idade:\n");
  scanf("%d", &pes.idade);
  printf("\nO CPF atual eh: %s", p[i].cpf);
  printf("Digite o novo CPF:\n");
  getchar();
  fgets(pes.cpf,tam_cpf,stdin);
  printf("\nO telefone atual eh: %s", p[i].telefone);
  printf("Digite o novo telefone:\n");
  fgets(pes.telefone,tam_tel,stdin);

  return pes;
}

/*Funcao para encontrar a ficha para alterar*/
void alterar_ficha()
{
  printf("\n1 - Buscar por nome.\n");
  printf("2 - Buscar por cpf.\n");
  forma_busca();
  switch(opcao)
  {
    case 1:
      for(i = 0; i < tam_vet; i++)
      {
        if(strcmp(pes.nome,p[i].nome) == 0)
        {
          p[i]=alteraracao_ficha();
        }
      }
    break;

    case 2:
      for(i = 0; i < tam_vet; i++)
      {
        if(strcmp(pes.cpf,p[i].cpf) == 0)
        {
          p[i] = alteraracao_ficha();
        }
      }
    break;

    default:
    break;
  }
  printf("\nNumero de fichas: %d", n_fichas);
  printf("\n\n\n\n");
}

void imprimir_ficha()
{
  if(n_fichas == 0)
  {
    printf("\nNao existe fichas cadastradas\n");
  }
  else
  {
    for(i = 0; i < n_fichas; i++)
    {
      printf("\nNome --- %s", p[i].nome);
      printf("Altura --- %1.2f\n", p[i].altura);
      printf("Idade --- %d\n", p[i].idade);
      printf("CPF --- %s", p[i].cpf);
      printf("Telefone --- %s", p[i].telefone);
      printf("Aniversario --- %d/%d/%d\n", p[i].dia, p[i].mes, p[i].ano);
    }
  }
  printf("\nNumero de fichas: %d", n_fichas);
  printf("\n\n\n\n");
}
