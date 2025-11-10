#include <stdlib.h>
#include <stdio.h>

void in_keyboard(int *m, int cnt){
    for (int i = 0; i < cnt; i++) {
    scanf("%d", &m[i]);
    }
}

void out(int *m, int cnt, int f){
    for (int i = 1; i <= cnt; i++){
        printf("%3d", i);
    }
    printf("\n");

    for (int i = 0; i < cnt; i++){
        printf("%3d", m[i]);
    }
    printf("\n");
    if (f == 1) printf("\n");
}

void sort(int *m, int cnt, unsigned long int *a, unsigned long int *c){
    for (int i = 1; i < cnt; i++){
        // out(m, cnt, 1);
        int temp = m[i], flag = 0;
        *a += 1;
        for (int j = 0; j < i; j++){
            *c += 1;
            if (m[j] > temp){
                flag = 1;
                for (int k = i; k > j; k--){
                    m[k] = m[k-1];
                    *a += 1;
                }
                m[j] = temp;
                *a += 1;
                break;
            }
        }
        if (flag == 0){
            *a += 1;
        }
    }
}

void improved_sort(int *m, int cnt, unsigned long int *a, unsigned long int *c){
    for (int i = 1; i < cnt; i++){
        // out(m, cnt, 1);
        int temp = m[i], flag = 0;
        *a += 1;
        *c += 1;
        int j, b;
        if (m[i/2] > temp){
            j = 0;
            b = i / 2;
        }
        else{
            j = i/2;
            b = i;
        }
        for (j; j <= b; j++){ 
            *c += 1;
            if (m[j] > temp){
                flag = 1;
                for (int k = i; k > j; k--){
                    m[k] = m[k-1];
                    *a += 1;
                }
                m[j] = temp;
                *a += 1;
                break;
            }
        }
        if (flag == 0){
            *a += 1;
        }
    }
}

void array_random_numbers(int *m, int cnt, int a, int b){
    for (int i = 0; i < cnt; i++){
        m[i] = (rand() % (b - a)) + a;
    }
}

void array_zero(int *m, int cnt){
    for (int i = 0; i < cnt; i ++){
        m[i] = 0;
    }
}

int array_sum(int *m, int cnt){
    int summa = 0;
    for (int i = 0; i < cnt; i++){
        summa += m[i];
    }
    return summa;
}

int main()
{
    int n;
    scanf("%d", &n);
    int A[n], B[n];
    // in_keyboard(A, n);
    array_random_numbers(A, n, 0, 100);
    for (int i = 0; i < n; i++){
        B[i] = A[i];
    }
    
    unsigned long int assignment_f = 0, comparison_f = 0;
    sort(A, n, &assignment_f, &comparison_f);
    
    unsigned long int assignment_s = 0, comparison_s = 0;
    improved_sort(B, n, &assignment_s, &comparison_s);
    // out(B, n, 0);
    // out(A, n, 1);

    printf("%lu %lu\n", assignment_s, comparison_s);
    printf("\n");
    printf("%lu %lu\n", assignment_f, comparison_f);

    // printf("%d\n", array_sum(A, n));
    //array_zero(A, n);

    return 0;
}