#include <stdio.h>
#include <stdlib.h>

int A[6];

void zer(int m[], int cnt){
    for (int i = 0; i < cnt; i ++){
        m[i] = 0;
    }
}

void in_keyboard(int m[], int cnt){
    for (int i = 0; i < cnt; i++) {
    scanf("%d", &m[i]);
    }
}

// генерация случайного целого числа из промежутка
int randint(int a, int b){
    int result = (rand() % (b - a)) + a;
    return result;
    return 0;
}

void in_random(int m[], int cnt, int a, int b){
    for (int i = 0; i < cnt; i++) {
        m[i] = randint(a, b);
    }
}

void out(int m[], int cnt){
    for (int i = 0; i < cnt; i++){
        printf("%d ", m[i]);
    }
    printf("\n");
}

int amount(int m[], int cnt){
    int s = 0;
    for (int i = 0; i < cnt; i++){
        s += m[i];
    }
    return s;
}

// ищем число в массиве
int exist(int a, int m[], int cnt){
    for (int i = 0; i < cnt; i++){
        if (a == m[i]){
            return 1;
        }
    }
    return 0;
}

void same_digits(int m1[], int m2[], int m3[], int s1, int s2, int s3){
    for (int i = 0; i < s1; i++){
        if (exist(m1[i], m2, s2) && exist(m1[i], m3, s3)){
            A[m1[i] - 10] = 1;
        }
    }
    for (int i = 0; i < 6; i++){
        if (A[i] != 0){
            printf("%d ", i + 10);
        }
    }
    printf("\n");
}

int main()
{
    int m1[5], m2[6], m3[8];
    int a = 0, b = 0, c = 0;

    // заполнение случайными числами
    // in_random(m1, 5, 10, 15);
    // in_random(m2, 6, 10, 15);
    // in_random(m3, 8, 10, 15);
    

    // заполнение числами с клавиатуры
    in_keyboard(m1, 5);
    in_keyboard(m2, 6);
    in_keyboard(m3, 8);

    /*
    14 12 13 10 12
    10 14 12 10 12 15
    13 12 11 15 11 14 11 13 
    */

    //вывод массивов
    out(m1, 5);
    out(m2, 6);
    out(m3, 8);

    // определение сумм элементов массивов
    a = amount(m1, 5);
    b = amount(m2, 6);
    c = amount(m3, 8);

    printf("%d %d %d\n", a, b, c);

    zer(A, 6);
    same_digits(m1, m2, m3, 5, 6, 8);

    return 0;
}