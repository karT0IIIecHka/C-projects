#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c, d, e;
    scanf("%d", &a);
    b = a / 1000;
    c = a /100 % 10;
    d = a % 100 / 10;
    e = a % 10;
    /*printf("%d %d %d %d %d\n", a, b, c, d, e);*/
    printf("%d\n", a % (b * c * d * e));
    return 0;
}