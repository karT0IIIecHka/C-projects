#include <stdlib.h>
#include <stdio.h>

void in_keyboard(int *m, int cnt){
    for (int i = 0; i < cnt; i++) {
    scanf("%d", &m[i]);
    }
}

void out(int *m, int cnt){
    for (int i = 1; i < cnt + 1; i++){
        printf("%3d", i);
    }
    printf("\n");

    for (int i = 0; i < cnt; i++){
        printf("%3d", m[i]);
    }
    printf("\n");
}

void change(int *m, int cnt, int i){
    int a = m[0];
    m[0] = m[i];
    m[i] = a;
}

void expansion(int **m, int *cnt){
    int *q;
    *cnt += 1;
    q = (int*) realloc(*m, (*cnt)*sizeof(int));
    if (q == NULL){
        printf("Не удалось увеличить память.");
        return;
    }
    *m = q;
}

void input(int *m, int cnt, int a, int k){
    for (int i = cnt - 1; i > k-1 ; i--){
        m[i] = m[i-1];
    }
    m[k - 1] = a;
}

int main()
{
    int n, i, a, k;
    int *m;
    scanf("%d", &n);

    m = (int *) malloc(n * sizeof(int));
    if (m == NULL){
        printf("Не удалось выделить память.");
        exit(0);
    }

    in_keyboard(m, n);
    scanf("%d", &i);
    scanf("%d", &a);
    scanf("%d", &k);
    
    out(m, n);
    printf("\n");

    change(m, n, i-1);
    expansion(&m, &n);
    input(m, n, a, k);

    out(m, n);

    free(m);

    return 0;
}