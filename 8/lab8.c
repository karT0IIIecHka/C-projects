#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

unsigned long int a = 0;

long int F(unsigned long int n, unsigned long int m){
    if (a > 1000){
        printf("endless\n");
        exit(0);
    }
    a += 1;
    if ((n+m) % 2 != 0){
        return n >= m ? n : m;
    }
    return F((n + m) / 2, m) + F(n, (n + m) / 2);
}

int main()
{
    unsigned long int n, m;
    scanf("%lu\n%lu", &n, &m);
    printf("%ld\n", F(n, m));
    return 0;
}