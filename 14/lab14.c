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

void array_random_numbers(int *m, int cnt, int a, int b){
    for (int i = 0; i < cnt; i++){
        m[i] = (rand() % (b - a)) + a;
    }
}

void special_out(int **m, int cnt){
    for (int i = 1; i <= cnt; i++){
        printf("%3d", i);
    }
    printf("\n");

    for (int i = 0; i < cnt; i++){
        printf("%3d", *m[i]);
    }
    printf("\n");
    printf("\n");
}

void swap(int **x, int **y){
    int *temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void QuickSort(int **A, int n, int first, int last){
    int l = first, r = last;
    int pivot = *A[(l+r)/2];
    while (l <= r) {
        while (*A[l] < pivot){
            l++;
        }
        while (*A[r] > pivot){
            r--;
        }
        if (l<=r){
            swap(&A[l], &A[r]);
            l++;
            r--;
        }
    }
    if (first < r){
        QuickSort(A, n, first, r);
    }
    if (l < last){
        QuickSort(A, n, l, last);
    }
}

int main()
{
    int f;
    scanf("%d", &f);
    int F[f];
    in_keyboard(F, f);
    // array_random_numbers(F, f, 0, 100);

    int s;
    scanf("%d", &s);
    int S[s];
    in_keyboard(S, s);
    // array_random_numbers(S, s, 0, 100);

    out(F, f, 1);
    out(S, s, 1);

    int *arr_pointers[f+s];
    
    for (int i = 0; i < f; i++){
        arr_pointers[i] = &F[i];
    }

    for (int i = 0; i < s; i++){
        arr_pointers[f + i] = &S[i];
    }

    QuickSort(arr_pointers, s + f, 0, s + f - 1);
    special_out(arr_pointers, s + f);

    return 0;
}