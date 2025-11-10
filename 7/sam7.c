#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

long int Six_to_Dec(long int a, int sign){
    long int b = 0;
    long int i = 1;
    while (a > 0){
        if (LONG_MAX - (a % 3) * i >= b){
            b += (a % 10) * i;
        }
        i *= 6;
        a /= 10;
    }
    if (sign < 0) return -b;
    return b;
}

long  int Dec_to_Trip(long int a, int sign){
    long int b = 0;
    long int i = 1;
    while (a > 0){
        if (LONG_MAX - (a % 3) * i >= b){
            b += (a % 3) * i;
        }
        else return 0;
        i *= 10;
        a /= 3;
    }
    if (sign < 0) return -b;
    return b;
}

long int add(long int a, long int b){
    if (fabs(LONG_MAX - b) >= a){
        return a + b;
    }
    printf("!1\n");
    exit(0);
    //return 1;

}

long int sub(long int a, long int b){
    if (LONG_MAX  - fabs(b) >= a){
        return a - b;
    }
    printf("!2\n");
    exit(0);
    //return 2;
}

long int mult(long int a, long int b){
    if (fabs(LONG_MAX / b) >= a){
        return a * b;
    }
    printf("%d %d %d\n", LONG_MAX / b, a, b);
    printf("!3\n");
    exit(0);
    //return 3;
}

long int step(long int a, long int b){
    int c = 1;
    for (int i = 0; i < b; i++){
        if (fabs(LONG_MAX / a) >= c){
            c *= a;
        }
        else{
            printf("!4\n");
            exit(0);
            //return 4;
        }
    }
    return c;
}

int main()
{
    long int a ,b, A, B, result = 0;
    
    scanf("%d", &a);
    scanf("%d", &b);

    A = Six_to_Dec(fabs(a), a / fabs(a));
    B = Six_to_Dec(fabs(b), b / fabs(b));

    result = add(sub(mult(step(A, 2), B), mult(A, sub(A, B))), A);
    result = Dec_to_Trip(fabs(result), result / fabs(result));

    printf("%d\n", result);
    
    return 0;
}