#include <stdlib.h>
#include <stdio.h>

void input(int m, int n, int A[][n]){
    for (int j = 0; j < n; j++){
        for (int i = 0; i < m; i++){
            if (j % 2 == 0) scanf("%d", &A[i][j]);
            else scanf("%d", &A[m - 1 -i][j]);
        }
    }
}

void output(int m, int n, int A[][n]){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%3d", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void max_sum_colomn(int m, int n, int A[][n]){
    int max_sum = 0;
    int N[n];

    for (int j = 0; j < n; j++){
        int temp_sum = 0;
        for (int i = 0; i < m; i++){
            temp_sum += A[i][j];
        }
        max_sum = max_sum > temp_sum ? max_sum : temp_sum;
        N[j] = temp_sum;
    }
    
    int flag = 1;
    for (int i = 0; i < n; i++){
        if (N[i] == max_sum){
            if (flag == 1){
                printf("%d", i+1);
                flag = 0;
            }
            else printf(" %d", i+1);
        }
    }
    printf("\n");
}

void saddle_elem(int m, int n, int A[][n]){
    int B[m][n];
    int cnt = 0;
    int res = 0;

    for (int i = 0; i < m; i++){
        int min_string = A[i][0];

        for (int j = 0; j < n; j++){
            min_string = min_string > A[i][j] ? A[i][j] : min_string;
        }

        for (int j = 0; j < n; j++){
            B[i][j] = A[i][j] == min_string ? 1 : 0;
        }
    }

    for (int j = 0; j < n; j++){
        int max_colomn = A[0][j];

        for (int i = 0; i < m; i++){
            max_colomn = max_colomn < A[i][j] ? A[i][j] : max_colomn;
        }

        for (int i = 0; i < m; i++){
            if (B[i][j] == 1 && A[i][j] == max_colomn){
                B[i][j] = 1;
                cnt += 1;
                res = A[i][j];
            }
            else{
                B[i][j] = 0;
            }
        }
    }
    // output(m, n, B);
    if (cnt == 0){
        printf("-\n");
    }
    else if (cnt == 1){
        printf("%d\n", res);
    }
    else{
        printf("%d %d\n", res, cnt);
    }
}

void random_array(int m, int n, int A[][n], int a, int b){
    for (int j = 0; j < n; j++){
        for (int i = 0; i < m; i++){
            A[i][j] = (rand() % (b - a)) + a;
        }
    }
}

int main()
{
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);
    int A[m][n];

    input(m, n, A);
    // random_array(m, n, A, 0, 100);
    output(m, n, A);
    max_sum_colomn(m, n, A);
    saddle_elem(m, n , A);
    
    return 0;
}