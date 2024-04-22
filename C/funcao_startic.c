#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


void print_var(void)
{
int i_tmp = 0;
 static int i = 0;

 i++;
 i_tmp++;

 printf("i_tmp: %d\n i = %d\n", i_tmp, i);
}

int main()
{
 print_var();
 print_var();
 print_var();
 print_var();

 return 0;
}
