#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int m[40];
    
    // ввод элементов массива
    /*
    scanf("%d %d", &a, &b);
    for (int i = 0; i < 40; i++){
        m[i] = (int) rand(a, b);
    }
    */
   
    for (int i = 0; i < 40; i++){
        scanf("%d", &m[i]);
    }

    // вывод элементов массива
    /*
    for (int i = 0; i < 40; i++){
        printf("%d %d\n", i, m[i]);
    }
    */

    int a;
    scanf("%d", &a);
    
    int c = 0, max = 0, cmax = 0;
    double mid = 0., cmid = 0.;

    for (int i = 0; i < 40; i++){
        if (m[i] < a){
            mid += m[i];
            cmid += 1;
        }
    }

    double n = (mid + 0.) / (cmid + 0.);

    for (int i = 0; i < 40; i++){
        if (m[i] < n){
            c += 1;
            max = (max >= m[i] ? max : m[i]);
        }
    }

    for (int i = 0; i < 40; i++){
        if (m[i] == max){
            cmax += 1;
        }
    }
    
    printf("%.4f\n%d\n%d %d\n", n, c, max, cmax);
    return 0;
}