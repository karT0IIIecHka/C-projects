#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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

void array_random_numbers(int *m, int cnt, int a, int b){
    for (int i = 0; i < cnt; i++){
        m[i] = (rand() % (b - a)) + a;
    }
}

// ---------Вставка---------

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

// ---------Пирамида---------

void swap(int *x, int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void TreeRebuild(int A[], int i, int n, int N, unsigned long int *a, unsigned long int *c){
    int ancestor = i;
    int top = A[ancestor];
    *a += 1;
    int descendant = 2 * ancestor + 1;
    int pp = 0;
    while (descendant <= n && !pp) {
        if (descendant < n){// если потомков 2
            *c += 1;
            if (A[descendant] < A[descendant+1]) // находим наибольшего потомка
                descendant++;
        }
        *c += 1;;
        if (top <= A[descendant]){
            A[ancestor] = A[descendant];
            *a += 1;
            ancestor = descendant; 
            descendant = 2 * ancestor + 1;
        }
        else {
            pp = 1;
        }
    }
    if (A[ancestor] != top){
        A[ancestor] = top;
        *a += 1;
    }
}

void TreeSort(int A[], int n, unsigned long int *a, unsigned long int *c){
    for (int i=n/2-1; i>=0; i--){
        TreeRebuild(A, i, n-1, n, a, c);
    }
    for (int i=n-1; i>=1; i--) {
        swap(&A[0],&A[i]);
        *a += 3;
        TreeRebuild(A, 0, i-1, n, a, c); 
    }
}

int main()
{
    int N[4] = {100, 500, 1000, 5000};
    // int n;
    // scanf("%d", &n);
    unsigned long int assignment_pyr = 0, comparison_pyr = 0;
    unsigned long int assignment_s = 0, comparison_s = 0;

    printf("\nassignments    comparisons    number of elements    theoretical complexity\n\n");
    for (int i = 0; i < 4; i++){

        int A[N[i]], B[N[i]];
        // in_keyboard(A, n);
        array_random_numbers(A, N[i], 0, 100);
        for (int j = 0; j < N[i]; j++){
            B[j] = A[j];
        }
        
        improved_sort(A, N[i], &assignment_s, &comparison_s);
        printf(" %7lu        %7lu        %10d              %10lu\n", assignment_s, comparison_s, N[i], N[i]*N[i]);

        TreeSort(B, N[i], &assignment_pyr, &comparison_pyr);
        printf(" %7lu        %7lu        %10d              %10.0f\n", assignment_pyr, comparison_pyr, N[i], N[i]*log2(N[i]));

        printf("\n");
    }

    return 0;
}