#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    int a, b, c, m, d, f, k=0;
    scanf("%d %d %d", &a, &b, &c);
    scanf("%d", &m);

    if(a == b && b == c){
        printf("%d=%d=%d\n\n", a, b, c);
    }
    else if(a == b || b == c || a == c){
        if(a==b){
            if(a > c) printf("%d=%d>%d\n\n", a, b, c);
            else printf("%d=%d<%d\n\n", a, b, c);
        }
        else if(b == c){
            if(a > b) printf("%d=%d<%d\n\n", b, c, a);
            else printf("%d=%d>%d\n\n", b, c, a);
        }
        else{
            if(a > b) printf("%d=%d>%d\n\n", a, c, b);
            else printf("%d=%d<%d\n\n", a, c, b);
        }
    }
    else{
        d = (a > b) ? a : b;
        d = (d > c) ? d : c;
        f = (a < b) ? a : b;
        f = (f < c) ? f : c;
        printf("%d\n\n", (a + b + c) - (d + f));
    }

    for(int i = 1; i*7 < m; i *= 7){
        k += 1;
    }

    printf("%d\n\n", k);

    for(int i = 1, k = 1; i < 11; i++){
        k *= 7;
        if (i < 10){
            printf("  %d  %d\n", i, k);
        }
        else{
            printf(" %d  %d\n", i, k);
        }
    }

    return 0;
}