#include <stdio.h>
#include <stdlib.h>

void in(int m[], int cnt, int a, int b){
    for (int i = 0; i < cnt; i ++){
        m[i] = a * (i - b);
    }
}

void out(int m[], int cnt){
    for (int i = 1; i <= cnt; i++){
        printf("%5d", i);
    }
    printf("\n");
    for (int i = 0; i < cnt; i++){
        printf("%5d", m[i]);
    }
    printf("\n");
}

void change(int m1[], int m2[], int k){
    for (int i = 0; i < k; i++){
        int temp = 0;
        temp = m1[i];
        m1[i] = m2[-k+i];
        m2[-k+i] = temp;
    }
}

int main()
{
    int m1[14], m2[10];
    int a, b, c, d, k;
    scanf("%d %d", &a, &b);
    scanf("%d %d", &c, &d);
    scanf("%d", &k);

    in(m1, 14, a ,b);
    in(m2, 10, c, d);

    out(m1, 14);
    printf("\n");
    out(m2, 10);
    printf("\n");

    change(m1, m2+10, k);
    change(m2, m1+14, k);

    out(m1, 14);
    printf("\n");
    out(m2, 10);
    

    return 0;
}