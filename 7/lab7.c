#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calcul(int a, int q, int n, double *A, double *S){
    if (n <= 0){
        return 1;
    }
    else{
        for (int i = 1; i < n; i++){
            *A *= q;
            *S += *A;
        }

        /*
        *S = (a * (1 - pow(q, n)))/(1 - q);
        *A = a * pow(q, n-1)
        */

        if (q < 0){
            return 2;
        }
        if (a == a * q){
            return 3;
        }
        return 0;
    }
    
}

int main()
{
    int a, q, n;
    scanf("%d", &a);
    scanf("%d", &q);
    scanf("%d", &n);
    double A = a, S = a;
    int code = calcul(a, q, n, &A, &S);
    
    if (code == 1){
        printf("%d\n", code);
    }
    else{
        printf("%d\n", code);    
        if (S >= A){
           printf("%.6f\n%.6f\n", A, S); 
        }
        else{
            printf("%.6f\n%.6f\n", S, A);
        }  
    }
    return 0;
}