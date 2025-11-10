#include <stdio.h>
#include <math.h>
#define a  1 * pow(10, -10)

int main()
{
    double A = -2.0, B = 2.0, C = (A + B)/2., D = 0.0, E = 0.0, F = 0.0;
    while (fabs(A - B) > a){
        double left = pow(A, 2) - A - 1;
        double right = pow(B, 2) - B - 1;
        double middle = pow(C, 2) - C - 1;
        if (left * middle < 0){
            if (middle * right < 0){
                D = C;
                E = B;
                F = (D + E) / 2.;
            }
            B = C;
        }
        else if (middle * right < 0){
            if (left * middle < 0){
                D = A;
                E = C;
                F = (D + E) / 2.;
            }
            A = C;
        }
        C = (A + B)/2.;
    }
     while (fabs(D - E) > a){
        double left = pow(D, 2) - D - 1;
        double right = pow(E, 2) - E - 1;
        double middle = pow(F, 2) - F - 1;
        if (left * middle < 0){
            E = F;
        }
        else if (middle * right < 0){
            D = F;
        }
        F = (D + E)/2.;
     }
    printf("%.10f\n", C);
    printf("%.10f\n", F);
    return 0;
} 