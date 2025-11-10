#include <stdio.h>
#include <math.h>

#define Ans 4.
#define a 1 * pow(10, -7)
#define b 1 * pow(10, -6)

int main()
{
    double L = -3.0, R = 3.0, M1 = (L + R) / 2., M2 = (L + R) / 2.;
    while (fabs(L - M1) > a && fabs(R - M2) > a){
        double left = cosh(L) - Ans;
        double right = cosh(R) - Ans;
        double middle1 = cosh(M1) - Ans;
        double middle2 = cosh(M2) - Ans;
        if (left * middle1 < 0){
            if (left * (cosh((L + M1) / 2.) - Ans) < 0){
                M1 = (L + M1) / 2.;
            }
            else{
                L = (L + M1) / 2.;
            }
        }
        if (middle2 * right < 0){
            if ((cosh((M2 + R) / 2.) - Ans) * right < 0){
                M2 = (M2 + R) / 2.;
            }
            else{
                R = (M2 + R) / 2.;
            }
        }
    }
    double E = Ans - cosh((M2 + R) / 2.);
    double x1 = (L + M1) / 2., x2 = (M2 + R) / 2.;
    
    double S = 0.;
    int n = 0;
    while (fabs(Ans - S) > b){
        int factorial = 1;
        for (int i = 1; i <= 2 * n; i++){
            factorial *= i;
        } 
        S += pow(x1, 2*n) / factorial;
        n += 1;
    }
    printf("%10.7f\n %.8f\n %.6f\n %d\n", x1, E, S, n);
    printf("%10.7f\n %.8f\n %.6f\n %d\n", x2, E, S, n);
    return 0;
}