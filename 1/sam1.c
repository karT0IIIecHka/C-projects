#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    scanf("%d\n%d", &a, &b);
    c = a * b;
    if (c > 999){
        c = c / 1000 + 48;
    }
    else{
        c = c / 100 + 48;
    }
    a = a / 10 + 48;
    b = b / 10 + 48;
    printf("%d:   %o   %d   %x\n", a-48, a, a, a);
    printf("%d:   %o   %d   %x\n", b-48, b, b, b);
    printf("%d:   %o   %d   %x\n", c-48, c, c, c);
    return 0;
}