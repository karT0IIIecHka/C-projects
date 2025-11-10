#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void in_keyboard(int *m, int cnt){
    for (int i = 0; i < cnt; i++) {
    scanf("%d", &m[i]);
    }
}

void out(int *m, int cnt){
    for (int i = 0; i < cnt; i++){
        printf("%4d", m[i]);
    }
    printf("\n");
}

void expansion(int **m, int *cnt, int a){
    // расширяет массив на a элементов
    if (a == 0) return;
    int *q;
    *cnt += a;
    q = (int*) realloc(*m, (*cnt)*sizeof(int));
    if (q == NULL){
        printf("Не удалось увеличить память.");
        return;
    }
    *m = q;
}

void compression(int *m, int *cnt, int a){
    // сжимает массив m на a элементов
    if (a == 0) return;
    *cnt -= a;
    m = (int*) realloc(m, (*cnt)*sizeof(int));
}

void rule_out(int *m, int cnt, int n){
    // представляет первые 2n элементов массива по какому-то правилу
    if (2*n > cnt){
        printf("Выход за пределы массива.");
        return;
    }
    for (int i = 0; i < n; i++){
        printf("%4d%4d", m[i], m[n + i]);
    }
    printf("\n");
}

void add(int *m, int cnt, int ind, int digit){
    // применяется в паре с expansion()
    // вставляет в массив m элемент digit по индексу ind - 1 
    for (int i = cnt - 1; i > ind - 1 ; i--){
        m[i] = m[i-1];
    }
    m[ind - 1] = digit;
}

void delete(int *m, int cnt, int ind){
    // применяется в паре с compression()
    // удаляет из массива m элемент по индексу ind 
    for (int i = ind; i < cnt - 1 ; i++){
        m[i] = m[i+1];
    }
}

void read_from_file(FILE *file, int *m, int *cnt){
    file = fopen("file.txt", "r");
    int elem, num = 0, i = 0, flag = 0;

    // считаем кол-во элементов (amount) в файле, считая элементом каждую ЦИФРУ
    int amount = 0;
    while ( (elem = getc(file)) != EOF){
        if (isdigit(elem)) amount++;
    }

    // перемещаемся в начало файла
    fseek(file, 0, SEEK_SET);

    // расширяем или сужаем динамический массив до нужного размера
    if (*cnt < amount){
        expansion(&m, cnt, amount - *cnt);
    }
    else{
        compression(m, cnt, *cnt - amount);
    }

    // считываем данные из файла и записываем их в динамический массив
    while ( (elem = getc(file)) != EOF){
        if (isdigit(elem)){
            flag = 1;
            num = num * 10 + elem - 48;
            continue;
        }
        else{
            if (flag != 0){
                m[i] = num;
                num = 0;
                flag = 0;
                i++;
            }
        }
    }
    m[i] = num;
    
    fclose(file);
}

void saving_to_file(FILE *file, int *m, int cnt){
    file = fopen("file.txt", "w");
    for (int i = 0; i < cnt; i++){
        fprintf(file, "%4d", m[i]);
    }
    fclose(file);
}

int main()
{
    int n;
    // 7
    // scanf("%d", &n);

    FILE *file;

    // выделение динамической памяти под массив
    int am = 10;
    int *A;
    A = (int *) malloc(am * sizeof(int));
    if (A == NULL){
        printf("Не удалось выделить память.");
        exit(0);
    }
    
    // A = {1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16};

    // вызов функций
    // in_keyboard(A, am);
    // saving_to_file(file, A, am);
    read_from_file(file, A, &am);
    // expansion(&A, &am, 1);
    // add(A, am, 5, 9);
    // delete(A, am, 4);
    // compression(A, &am, 1);
    // rule_out(A, am, n);
    out(A, am);

    // очищение динамической памяти
    free(A);

    return 0;
}