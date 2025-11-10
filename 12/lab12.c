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

void sort(int *m, int cnt, int *a, int *c){
    for (int i = 1; i < cnt; i++){
        out(m, cnt, 1);
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

int main()
{
    int n;
    scanf("%d", &n);
    int A[n];
    in_keyboard(A, n);

    int assignment = 0, comparison = 0;
    sort(A, n, &assignment, &comparison);
    out(A, n, 0);
    printf("%d %d\n", assignment, comparison);

    return 0;
}