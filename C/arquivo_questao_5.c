#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *p;
    char str[30], frase[] = "Este é um arquivo chamado: ", resposta[80];
    int i;
    // Le um nome para o arquivo a ser aberto
    printf("Informe um nome de arquivo: ");

    // Usa fgets como se fosse gets
    fgets(str,29,stdin);

    // Elimina o \n da string lida
    for(i=0; str[i]; i++) if(str[i]=='\n') str[i]=0;

    // Caso ocorra algum erro na abertura do arquivo
    // O programa aborta automaticamente
    if (!(p = fopen(str,"w"))){
             printf("Erro! Impossivel abrir o arquivo!\n");
             exit(1);
    }

    // Se nao houve erro, imprime no arquivo, e o fecha
    fputs(frase, p);
    fputs(str,p);
    fclose(p);

    // abre novamente e lê
    p = fopen(str,"r");
    fgets(resposta, 79, p);
    printf("%s\n", resposta);

    // Fecha o arquivo
    fclose(p);
    // Apaga o arquivo
    remove(str);
    return(0);
}
