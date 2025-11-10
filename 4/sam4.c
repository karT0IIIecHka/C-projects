#include <stdio.h>
#include <math.h>

#define a 0.5 * pow(10, -8)
#define Ans 1.0 / 3.0

int main()
{
    int n = 0, z = 0;
    double D = 0.0, S = 0.0;
    while (1){
        n += 1;
        D = 1.0 / ((3. * n - 2) * (3. * n + 1));
        if (fabs(Ans - (S + D)) > a){
            S += D;
        }
        else{
            break;
        }
    }
    int cnt = 0, ST = 1;
    while (fabs(Ans * 100 * ST - S * 100 * ST) < 1){
        cnt += 1;
        ST *= 10;
    }
    printf("%.9f\n%.9f\n%.9f\n%d\n%d\n", Ans, S, a, n, cnt);
    return 0;
}