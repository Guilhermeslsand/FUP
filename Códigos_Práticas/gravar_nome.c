#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *Upper2( char *string)
{
    int i;
    char *strUpper;
    strUpper = (char*) malloc(100*sizeof(char));
    if (strUpper == NULL )
    {
      perror("Erro ocorrido");
      exit(1);
    }
    for( i=0; i < 100 ; i++ )
    {
      strUpper[i] =  toupper(string[i]);
    }
    i++;
    strUpper[i] = '\0';//Alterado aqui, para finalização da string
    return strUpper;
}

int main(void)
{
  char string[100];
  char *retorno;
  memset( string, '\0', 100 );
  for (int i = 0; i<2; i++)
  {
    printf("Digite a string: \n");
    scanf("%s*[^\n]", &string);
    //Use Upper1 ou Upper2, são diferentes, porém causam o mesmo efeito
    retorno = Upper2( string );
    printf("Antes: %s\nDepois: %s\n\n", string, retorno);
    //Se usar Upper2, descomente abaixo
    free(retorno);
  }
return 0;
}
