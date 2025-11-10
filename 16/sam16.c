#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct adress{
    char Town[16];
    char Street[16];
    int Home;
    int Flat;
};

struct Participants_files{
    char SurName[16];
    char Name[16];
    struct adress Adress;
    char Section[16];
    int Score;
    int flag;
};


void swap_T(int *x, int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void swap_Towns(char **x, char **y){
    char *temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void QuickSort_Towns(char **t, int T[], int town, int first, int last){
    int l = first, r = last; /*левый и правый счетчики*/
    int pivot = T[(l+r)/2]; /*опорное значение*/
    while (l <= r) {
        int Left = T[l];
        int Right = T[r];
        while (Left < pivot){
            l++;
            Left = T[l];
        }
        while (Right > pivot){
            r--;
            Right = T[r];
        }
        if (l<=r){
            swap_T(&T[l], &T[r]); /*перестановка двух элементов*/
            swap_Towns(&t[l], &t[r]);
            l++;
            r--;
        }
    }
    /*Рекурсивная сортировка:*/
    if (first<r){
        QuickSort_Towns(t, T, town, first, r); /*- левого участка, */
    }
    if (l<last){
        QuickSort_Towns(t, T, town, l, last); /*- правого участка.*/
    }
}

void swap(struct Participants_files **x, struct Participants_files **y){
    struct Participants_files *temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void QuickSort(struct Participants_files **A, int n, int first, int last){
    int l = first, r = last; /*левый и правый счетчики*/
    int pivot = A[(l+r)/2]->Score; /*опорное значение*/
    while (l <= r) {
        int Left = A[l]->Score;
        int Right = A[r]->Score;
        while (Left < pivot){
            l++;
            Left = A[l]->Score;
        }
        while (Right > pivot){
            r--;
            Right = A[r]->Score;
        }
        if (l<=r){
            swap(&A[l], &A[r]); /*перестановка двух элементов*/
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

struct Participants_files** input(struct Participants_files participants[], int n){
    struct Participants_files **q;
    q = (struct Participants_files **) malloc(n*sizeof(struct Participants_files *));
    for (int i = 0; i < n; i++){
        scanf("%s", &participants[i].SurName);
        scanf("%s", &participants[i].Name);
        scanf("%s", &participants[i].Adress.Town);
        scanf("%s", &participants[i].Adress.Street);
        scanf("%d", &participants[i].Adress.Home);
        scanf("%d", &participants[i].Adress.Flat);
        scanf("%s", &participants[i].Section);
        scanf("%d", &participants[i].Score);
        participants[i].flag = 0;
        q[i] = &participants[i];
    }
    return q;
}

void output(struct Participants_files participants[], int n){
    printf("\n");
    for (int i = 0; i < n; i++){
        printf("%s ", participants[i].SurName);
        printf("%s ", participants[i].Name);
        printf("%s ", participants[i].Adress.Town);
        printf("%s ", participants[i].Adress.Street);
        printf("%d ", participants[i].Adress.Home);
        printf("%d ", participants[i].Adress.Flat);
        printf("%s ", participants[i].Section);
        printf("%3d", participants[i].Score);
        printf("\n");
    }   
    printf("\n");
}

void b_output(struct Participants_files **q, int n){
    printf("\n");
    for (int i = 0; i < n; i++){
        printf("%s ", q[i]->SurName);
        printf("%s ", q[i]->Name);
        printf("%s ", q[i]->Adress.Town);
        printf("%s ", q[i]->Adress.Street);
        printf("%d ", q[i]->Adress.Home);
        printf("%d ", q[i]->Adress.Flat);
        printf("%s ", q[i]->Section);
        printf("%3d", q[i]->Score);
        printf("%3d", q[i]->flag);
        printf("\n");
    }   
    printf("\n");
}
 
void Final_Scores(struct Participants_files **q, struct Participants_files participants[], int n, int k){
    char **s;
    int sect = 0;
    int f = 0;
    s = (char **) malloc(sizeof(char*));
    for (int i = 0; i < n; i++){
        
        for (int j = 0; j < sect; j++){
            if (strcmp(s[j], participants[i].Section) == 0){
                f = 1;
                break;
            }
        }
        if (f == 0){
            s = (char **) realloc(s, (sect+1)*sizeof(char*));
            s[sect] = participants[i].Section;
            sect += 1;
        }
        f = 0;

        int cnt = 0;
        for (int j = n - 1; j >= 0; j--){
            if (strcmp(q[j]->Section, participants[i].Section) == 0){
                cnt += 1;
                if (cnt <= k){
                    q[j]->flag = 1;
                }
            }
        }
    }

    for (int i = 0; i < sect; i++){
        for (int j = 0; j < n; j++){
            if (strcmp(s[i], q[j]->Section) == 0 && q[j]->flag == 1){
                printf("%s %d\n", q[j]->Section, q[j]->Score);
                break;
            }
        }
    }
    printf("\n");
}

void List_sections(struct Participants_files participants[], int n){
    char **s;
    int sect = 0;
    int f = 0;
    s = (char **) malloc(sizeof(char*));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < sect; j++){
            if (strcmp(s[j], participants[i].Section) == 0){
                f = 1;
                break;
            }
        }
        if (f == 0){
            s = (char **) realloc(s, (sect+1)*sizeof(char*));
            s[sect] = participants[i].Section;
            sect += 1;
        }
        f = 0;
    }
    // printf("All Ok\n");

    for (int j = 0; j < sect; j++){
        printf("%s\n", s[j]);
        for (int i = 0; i < n; i++){
            if (strcmp(s[j], participants[i].Section) == 0){
                printf(" %s\n", participants[i].SurName);
            }
        }
        printf("\n");
    }
}

void List_towns(struct Participants_files participants[], int n){
    char **t;
    int town = 0;
    int f = 0;
    t = (char **) malloc(sizeof(char*));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < town; j++){
            if (strcmp(t[j], participants[i].Adress.Town) == 0){
                f = 1;
                break;
            }
        }
        if (f == 0){
            t = (char **) realloc(t, (town+1)*sizeof(char*));
            t[town] = participants[i].Adress.Town;
            town += 1;
        }
        f = 0;
    }

    printf("%d\n\n", town);
    
    int T[town];
    for (int j = 0; j < town; j++){
        int cnt = 0;
        for (int i = 0; i < n; i++){
            if (strcmp(t[j], participants[i].Adress.Town) == 0){
                cnt += 1;
            }
        }
        T[j] = cnt;
    }
    QuickSort_Towns(t, T, town, 0, town-1);

    printf("%s", t[town-1]);
    for (int j = town - 2; j >= 0; j--){
        printf(" %s", t[j]);
    }

    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    struct Participants_files participants[n];

    struct Participants_files **b;
    b = input(participants, n);

    int k;
    scanf("%d", &k);

    QuickSort(b, n, 0, n-1);
    Final_Scores(b, participants, n, k);

    // output(participants, n);
    // b_output(b, n);

    List_sections(participants, n);
    List_towns(participants, n);

    return 0;
}

/*
8
Noname Tolya Moskow Sadovnaya 34 87 Orientirovanie 95
Yakovlev Demyan Krasnoyarsk Molokova 8 17 Sambo 100
Buravzchov Oleg Moskow Lenina 51 25 OFP 79
Zaripov Ilya Krasnoyarsk Totmina 15 21 Orientirovanie 96
Marchuk Vlad Bolgograd Pavlova 3 6 OFP 72
Poykalaynen Egor Yaroslavl Matrosova 15 2 Tourism 73
Pristavka Timofey Kaliningrad Rechnaya 96 62 Sambo 73
Tsygankov Ivan Moskow Tutcheva 5 36 Sambo 73
2
*/