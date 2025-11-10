#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <locale.h>


long int a(long int n) {
    if (n <= 2){
        return 1;
    }
    else{
        return a(n - 1) + 2 * a(n - 2);
    }
}

void table(long int n){
    printf("current recursion level    recursive descent      recursive return\n");
    printf("--------------------------------------------------------------------\n");
    int i = 0;
    int j = n - 1;
    int deep = 1;
    int k = 0;
    while (j > 0) {
        while (n - (i + j) > 0) {
            if ((n - i - k) < 1) {
                break;
            }
            if ((n - i - k) == 2 || (n - i - k) == 1) {
                printf("%3d                              %3ld    ---------->>>       %ld\n",deep, n-i-k, n-i-k);
                i++;
                deep++;
            }
            else {
                printf("%3d                              %3ld                        %ld\n",deep, n - i - k, a(n - i - k));
                i++;
                deep++;
            }
        }
        k++;
        j--;
        i = 0;
        printf("--------------------------------------------------------------------\n");
    }
}

int main() {
    long int n;
    scanf("%ld", &n);
    printf("%ld\n", a(n));

    setlocale(LC_ALL, "");
    table(n);

    return 0;
}