#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<limits.h>

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    int k, fr = 1, sc = 3, a, s1 = 1, s2 = 2, s3 = 5;
    scanf("%d", &k);
    if (x > 0) {
        if (x * x + y * y > pow(200, 2) && abs(y) < 200 && abs(x) < 200) {
            printf("inside\n\n");
        }
        else {
            printf("outside\n\n");
        }
    }
    else if (x < 0) {
        if (x * x + y * y < pow(200, 2) && x < -100 && abs(y) < abs(x)) {
            printf("inside\n\n");
        }
        else {
            printf("outside\n\n");
        }
    }
    else {
        printf("outside\n\n");
    }

    printf("  %d  %d\n", 1, s1);
    printf("  %d  %d\n", 2, s2);
    printf("  %d  %d\n", 3, s3);
    for (int i = 4; i <= 40; i++) {
        a = sc + 2 * fr;
        fr = sc;
        sc = a;
        if (s3 <= LONG_MAX - a) {
            s1 = s2;
            s2 = s3;
            s3 = s3 + a;
        }
        else {
            printf(" %d  %d\n", i - 3, s1);
            printf(" %d  %d\n", i - 2, s2);
            printf(" %d  %d\n", i - 1, s3);
            break;
        }
        
        if (i < k) {
            if (i < 10) printf("  %d  %d\n", i, s3);
            else printf(" %d  %d\n", i, s3);
        }
        else if (i == k) {
            if (i < 10) printf("  %d  %d\n", i, s3);
            else printf(" %d  %d\n", i, s3);
            printf("\n");
        }
    }
    return 0;
}