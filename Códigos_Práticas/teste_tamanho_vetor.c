#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    int n = 100;
    int *p = malloc(n * sizeof(int));
    printf("%p = %d\n", p, n);
}
