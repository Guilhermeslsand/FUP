#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
/*Definino nome para o arquivo*/
#define FILE_NAME "banco_dinheiro.txt"

struct pessoa
{
  char nome [120];
  char telefone [12];
  char cpf [13];
  int idade;
  int dia, mes, ano;
};

/*Declarando Varieaveis*/
struct pessoa *p;

void menuPrincipal()
{
    do
    {
        printf("\n");
        printf ("\t\t\t\t  H&R GAMES!\n");
        printf ("\t\t\t===============================\n");
        printf ("\t\t\t|\t                      |\n");
        printf("\t\t\t|\t 1 - Cliente          |\n");
        printf("\t\t\t|\t 2 - Saldo         |\n");
        printf("\t\t\t|\t 3 - Sair            |\n");
        printf("\t\t\t|\t 4 - Vendas           |\n");
        printf("\t\t\t|\t 0 - Sair             |\n");
        printf ("\t\t\t|\t                      |\n");
        printf ("\t\t\t===============================\n");
        printf ("\n\n");
        printf("\t\t\tPor favor, selecione uma opcao: ");
        fflush(stdin);
        scanf("%d", &input);
        system("cls");
        switch(input)
        {
        case 1:
            menuClientes();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 0:
            exit(EXIT_SUCCESS);
        default:
            printf ("\n\t\t\tOpcao invalida!\n\n");
            fflush(stdin);
        }
    }
    while(input != 0);
    system("cls");
}
