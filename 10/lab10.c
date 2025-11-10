#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    char c, temp;
    c = getchar();
    int cnt = 0, flag = 1;
    int k = 0;

    while (c != '\n'){
        cnt = isalpha(c);
        if (cnt != 0){
            if (flag == 1){
                k += 1;
            }
            printf("%c", c);
            flag = 0;
        }
        else{
            if (flag == 0){
                printf("\n");
                flag = 1;
            }
        }
        temp = c;
        c = getchar();
    }
    if (isalpha(temp) != 0) printf("\n\n%d\n", k);
    else printf("\n%d\n", k);

    return 0;
}