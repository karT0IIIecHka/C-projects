#include <stdio.h>
#include <math.h>
#define MIN 20000000
#define MAX 200000000

int main()
{
    double summa = 0.0;
    double D = 0.0, Dcor = 0.0, cor = 0.0, Scor = 0.0, Summa = 0.0;
    int n = 1, N = MIN;
    while (n <= MAX){
        D = sqrt((1 + 2 * pow(n , 2))/(3 + pow(n, 2)));
        Dcor = D - cor;
        Scor = Summa + Dcor;
        cor = (Scor - Summa) - Dcor;
        Summa = Scor;
        summa += D;
        if (n == N){
            printf("%9.4d%18.4f%18.4f%10.4f\n", N, summa, Summa, summa - Summa);
            N += MIN;
        }
        n += 1;
    }
    return 0;
}