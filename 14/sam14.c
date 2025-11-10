#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void swap(char **x, char **y){
    char *temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void QuickSort(char **A, int n, int first, int last){
    int l = first, r = last; /*левый и правый счетчики*/
    int pivot = A[(l+r)/2][0]; /*опорное значение*/
    while (l <= r) {
        int Left = A[l][0];
        int Right = A[r][0];
        while (Left < pivot){
            l++;
            Left = A[l][0];
        }
        while (Right > pivot){
            r--;
            Right = A[r][0];
        }
        if (l<=r){
            swap(&A[l],&A[r]); /*перестановка двух элементов*/
            l++;
            r--;
        }
    }
    /*Рекурсивная сортировка:*/
    if (first<r){
        QuickSort(A, n, first, r); /*- левого участка, */
    }
    if (l<last){
        QuickSort(A, n, l, last); /*- правого участка.*/
    }
}

char** input(int *n){
    char **q;
    q = (char**) malloc(sizeof(char*));
    char end[] = "!";
    char *surname;
    scanf("%s", surname);
    while (strcmp(surname, end) != 0){
        int cnt = strlen(surname);

        // выделение памяти для новой фамилии
        char **tm;
        tm = (char**) realloc(q, (*n+1)*sizeof(char*));
        if (tm == NULL){
            printf("No memory for new surname\n");
            exit(0);
        }
        q = tm;

        // выделение памяти для строки
        char *p;
        p = (char*) malloc((cnt)*sizeof(char*));
        if (p == NULL){
            printf("No memory for surname\n");
            exit(0);
        }
        q[*n] = p;
        strcpy(q[*n], surname);
        // printf("%s\n", q[*n]);

        *n += 1;
        scanf("%s", surname);
    }
    return q;
}

char** file_input(FILE *file, int *n){
    file = fopen("file.txt", "r");
    char end[] = "!";
    char **q;
    q = (char**) malloc(sizeof(char*));
    char *surname;
    while(strcmp(fgets(surname, 20, file), end) != 0){
        int cnt = strlen(surname);

        // выделение памяти для новой фамилии
        char **tm;
        tm = (char**) realloc(q, (*n+1)*sizeof(char*));
        if (tm == NULL){
            printf("No memory for new surname\n");
            exit(0);
        }
        q = tm;

        // выделение памяти для строки
        char *p;
        p = (char*) malloc((cnt)*sizeof(char*));
        if (p == NULL){
            printf("No memory for surname\n");
            exit(0);
        }
        q[*n] = p;
        strcpy(q[*n], surname);
        // printf("%s\n", q[*n]);

        *n += 1;
    }

    printf("%d\n", *n);
    fclose(file);
    return q;
}

void output(char **b, int cnt){
    printf("\n");
    for (int i = 0; i < cnt; i++){
        printf("%s\n", b[i]);
    }
    printf("\n");
}

void groups(char **b, int n){
    int alphabet[26];
    for (int i = 0; i < 26; i++){
        alphabet[i] = 0;
    }

    for (int i = 0; i<n; i++){
        alphabet[b[i][0]-65] += 1;
    }

    // количество фамилий, начинающихся на i-ую букву
    for (int i = 0; i < 26; i++){
        if (alphabet[i] != 0){
            printf("%c: %d\n", i+65, alphabet[i]);
        }
    }

    // распределение по группам

    int surnames = 0; // сколько всего разных первых букв
    for (int i = 0; i < 26; i++){
        if (alphabet[i] != 0){
            surnames += 1;
        }
    }
    // printf("%d\n", surnames);

    int mid = n/4+1; // человек в группе в среднем + 1
    int group = 0; // человек в текущей группе
    int vacant = 3; // сколько групп ещё не сформировано
    int flag = 1; // нет открытой группы

    printf("\n");
    printf("A-");
    for (int i=0; i < 26; i++){
        if (alphabet[i] != 0){
            if ((group + alphabet[i] > mid && vacant > 0) || surnames - 1 < vacant){
                printf("%c %d\n", i-1+65, group);
                printf("%c-", i+65);
                group = alphabet[i];
                surnames -= 1;
                vacant -= 1;
            }
            else{
                group += alphabet[i];
                surnames -= 1;
            }
        }
    }
    printf("Z %d\n", group);
}

int main()
{
    FILE *file;

    char **b;
    int n = 0;
    b = input(&n);
    // b = file_input(file, &n);
    
    // вывод всех фамилий в первоначальном порядке
    // output(b, n);

    // printf("=========\n");

    QuickSort(b, n, 0, n-1);
    
    // вывод всех фамилий в алфавитном порядке
    output(b, n);

    groups(b, n);
    
    return  0;
}