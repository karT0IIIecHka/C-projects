#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void input(int **a, int m, int n){
    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }
}

void output(int **a, int m, int n){
    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%6d", a[i][j]);
        }
        printf("\n");
    }
}

void input_random(int **a, int m, int n, int first, int last){
    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            a[i][j] = (rand() % (last - first)) + first;
        }
    }
}

void read_from_file(FILE *file, int ***a, int *m, int *n){
    file = fopen("file.txt", "r");
    int str = 0, amount = 0;
    int elem;

    // Считаем сколько строк и символов в файле
    while ( (elem = getc(file)) != EOF){
        if (isdigit(elem)) amount++;
        if (elem == '\n') str++;
    }
    int col = amount / str;

    // Меняем размер динамического массива
    int **q;
    q = (int **) realloc(*a, str * sizeof(int*) + str * col * sizeof(int));
    if (q == NULL){
        printf("The memory could not be increased.\n");
        exit(0);
    }
    *m = str;
    *n = col;
    *a = q;

    // перезаписываем адреса
    for (int i = 0; i < *m; i++){
        *a[i] = (int*) *a + *m + i * *n;
    }

    // printf("%d %d\n", *m, *n);

    // перемещаемся в начало файла
    fseek(file, 0, SEEK_SET);
    
    // считываем данные из файла и записываем их в динамический массив
    int num = 0, flag = 0;
    int i = 0, j = 0;
    while ( (elem = getc(file)) != EOF){
        if (isdigit(elem)){
            flag = 1;
            num = num * 10 + elem - 48;
            continue;
        }
        else{
            if (flag != 0){
                *a[i][j] = num;
                num = 0;
                flag = 0;
                if (j == *n-1){
                    j = 0;
                    i++;
                }
                else{
                    j++;
                }
            }
        }
    }

    fclose(file);
}

int **  transposition(int **a, int m, int n){
    int **q;
    q = (int**) malloc(n * sizeof(int*) + n * m * sizeof(int));
    for (int i = 0; i < n; i++){
        q[i] = (int*) q + n + i * m;
    }
    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            q[j][i] = a[i][j];
        }
    }
    return q;
}

int ** addition(int **a, int ma, int na, int **b, int mb, int nb){
    if (ma != mb || na != nb){
        printf("!1\n");
        exit(0);
    }
    int **q;
    q = (int**) malloc(ma * sizeof(int*) + ma * nb * sizeof(int));
    for (int i = 0; i < ma; i++){
        q[i] = (int*) q + ma + i * nb;
    }

    for(int i = 0; i < ma; i++){
        for (int j = 0; j < na; j++){
            q[i][j] = a[i][j] + b[i][j];
        }
    }
    return q;
}

int ** multiplication(int **a, int ma, int na, int **b, int mb, int nb){
    if (na != mb){
        printf("!2\n");
        exit(0);
    }
    int **q;
    q = (int**) malloc(ma * sizeof(int*) + ma * nb * sizeof(int));
    for (int i = 0; i < ma; i++){
        q[i] = (int*) q + ma + i * nb;
    }

    for(int i = 0; i < ma; i++){
        for (int j = 0; j < na; j++){
            q[i][j] = 0;
            for (int k = 0; k < na; k++){
                 q[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return q;
}

int ** exponentiation(int **a, int m, int n, int k){
    if (m != n || k < 1){
        printf("!3\n");
        exit(0);
    }
    int **q;
    q = (int**) malloc(m * sizeof(int*) + m * n * sizeof(int));
    for (int i = 0; i < m; i++){
        q[i] = (int*) q + m + i * n;
    }

    if (k == 1)  return a;
    else{
        q = multiplication(a, m, n, a, m ,n);
        for (int l = 0; l < k - 2; l++){
            q = multiplication(q, m, n, a, m ,n);
        }
    }
    return q;
}

int main()
{
    FILE *file;

    int Ma, Na;
    scanf("%d %d", &Ma, &Na);

    int **a;
    a = (int**) malloc(Ma * sizeof(int*) + Ma * Na * sizeof(int));
    for (int i = 0; i < Ma; i++){
        a[i] = (int*) a + Ma + i * Na;
    }

    // input_random(a, Ma, Na, 0, 30);
    input(a, Ma, Na);
    // read_from_file(file, &a, &Ma, &Na);
    
    int Mb, Nb;
    scanf("%d %d", &Mb, &Nb);

    int **b;
    b = (int**) malloc(Mb * sizeof(int*) + Mb * Nb * sizeof(int));
    for (int i = 0; i < Mb; i++){
        b[i] = (int*) b + Mb + i * Nb;
    }

    // input_random(b, Mb, Nb, 0, 30);
    input(b, Mb, Nb);

    // printf("\n");
    // output(a, Ma, Na);
    // printf("\n");
    // output(b, Mb, Nb);
    // printf("\n");

    // output(addition(a, Ma, Na, b, Mb, Nb), Ma, Na);
    // output(transposition(a, Ma, Na), Na, Ma);
    // output(multiplication(a, Ma, Na, a, Ma, Na), Ma, Na);
    // output(exponentiation(a, Ma, Na, 2), Ma, Na);

    output(addition(exponentiation(multiplication(a, Ma, Na, b, Mb, Nb), Ma, Nb, 2), Ma, Nb, multiplication(a, Ma, Na, transposition(a, Ma, Na), Na, Ma), Ma, Ma), Ma, Ma);
    
    return 0;
}

/*
3 4
3 2 4 1
5 2 1 4
1 3 4 2
4 3
2 4 5
3 2 1
4 3 3 
1 5 2
*/