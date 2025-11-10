#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int max_num = 0, num = 0;
int numbers[100];
FILE *file;
 
int f(char a, int num){
    if (isdigit(a)){
    num = num * 10 + a - 48;
    }
    else{
        max_num = max_num >= num ? max_num : num;
        num = 0;
    }
    return num;
}

void in(int str, int cnt){
    file = fopen("file.txt", "w");
    for (int i = 0; i < str; i++){
        for (int j = 0; j < cnt; j++){
            int len_digit = rand() % 3 + 1;
            char digits[9] = "123456789";
            for (int k = 0; k < len_digit; k++){
                fprintf(file, "%c", digits[rand() % 9]);
            }
            fprintf(file, " ");
        }
        fprintf(file, "\n"); 
    }
    fclose(file);
}

void out(int str, int cnt){
    file = fopen("file.txt", "r");
    char d;
    int s = 1;

    fscanf(file, "%c", &d);
    num = f(d, num);

    while (d != EOF && s < str){
        fscanf(file, "%c", &d);
        num = f(d, num);
        if (d == '\n'){
            numbers[s] = max_num;
            max_num = 0;
            s++;
        }
    }

    int M = 0;
    for (int i = 0; i < s; i++){
        M = M >= numbers[i] ? M : numbers[i];
    }
    int cn = 0;
    for (int i = 0; i < s; i++){
        if (M == numbers[i]){
            if (cn == 0){
                printf("%d %d", numbers[i], i);
                cn ++;
            }
            else printf(" %d %d", numbers[i], i);
        }
    }
    printf("\n");

    fclose(file);
}

void standart(){
    char c, d;
    int s = 1;

    c = getchar();
    num = f(c, num);
    d = getchar();
    num = f(d, num);

    while ((c != '\n' || d != '\n') && s <= 30 ){
        c = d;
        d = getchar();
        num = f(d, num);
        if (d == '\n'){
            numbers[s] = max_num;
            max_num = 0;
            s++;
        }
    }

    int M = 0;
    for (int i = 0; i < s; i++){
        M = M >= numbers[i] ? M : numbers[i];
    }
    int cn = 0;
    for (int i = 0; i < s; i++){
        if (M == numbers[i]){
            if (cn == 0){
                printf("%d", i);
                cn ++;
            }
            else printf(" %d", i);
        }
    }
    printf("\n");

}

int main()
{ 
    
    // int str = rand() % 30 + 1;
    // int cnt = rand() % 20 + 1;
    // in(str, cnt);
    // out(str, cnt);

    standart();
    
    return 0;
}