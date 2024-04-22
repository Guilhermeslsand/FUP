#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void uppercase( char *sNome )
{
    sNome = "GUILHERME";
}

int main (void)
{
    char sNome = "Guilherme";
    printf( "Antes: %s\n", sNome );
    printf( "Antes: %d\n", &sNome );
    uppercase(sNome);
    printf( "\nDepois:%s", sNome );
    printf( "\nDepois:%d\n", &sNome );

}
