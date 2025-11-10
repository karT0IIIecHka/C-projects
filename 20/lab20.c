#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define m 13

struct elem{
    char *name;
    struct elem *next;
};

void output(struct elem** q){
    printf("\n");
    for (int i = 0; i < m; i++){
        struct elem *p;
        p = q[i];
        if (p != NULL){
            printf("%d ---> %s", p, p->name);
            while (p->next != NULL){
                p = p->next;
                printf(" %d ---> %s", p, p->name);
            }
            printf("\n");
        }
        else{
            printf("%d\n", p);
        }
    }
    printf("\n");
}

int hesh_func(char *name, int letters){
    int h = 0;
    for (int i = 0; i < letters; ++i){
        int p = name[i];
        h = (h*123 + p) % m;
    }
    return h;
}

void put_name(char *name, int letters, struct elem **q){
    
    int h = hesh_func(name, letters);
    struct elem *elem;
    elem = (struct elem *) malloc(sizeof(struct elem));
    elem->next = NULL;
    elem->name = (char *) malloc(letters * sizeof(char));
    strcpy(elem->name, name);
    
    struct elem *p;
    p = q[h];
    if (p == NULL){
        q[h] = elem;
    }
    else{
        while (p->next != NULL){
            p = p->next;
        }
        p->next = elem;
    }

    // output(q);
}

struct elem** input(){
    struct elem** q;
    q = (struct elem**) malloc(m*sizeof(struct elem*));
    for (int i = 0; i < m; i++){
        q[i] = NULL;
    }

    char element;
    char *name;
    name = (char *) malloc(sizeof(char));
    int letters = 0;

    while ((element = getchar()) != '\n'){
        if (isalpha(element)){
            char *tm;
            tm = (char*) realloc(name, (letters+1)*sizeof(char));
            if (tm == NULL){
                printf("No memory for new letter\n");
                exit(0);
            }
            name = tm;

            name[letters] = element;
            letters++;
        }
        else{
            put_name(name, letters, q);
            name = NULL;
            letters = 0;
        }
    }

    put_name(name, letters, q);
    letters = 0;
    return q;
}

char* find_name(struct elem** q, char *name, int letters){
    int h = hesh_func(name, letters);
    int equal = 0;
    int flag = 0;
    struct elem *p;
    p = q[h];

    while(p != NULL){
        equal += 1;
        if (strcmp(p->name, name) == 0){
            flag = 1;
            break;
        }
        p = p->next;
    }
    // printf("There was: %d comparisons\n", equal);
    if (flag == 1){
        // printf("%s\n", p->name);
        return p->name;
    }
    else{
        printf("not found\n");
    }
}

void Max_len(struct elem **q){
    int len = 0;
    for (int i = 0; i < m; i++){
        struct elem *p;
        p = q[i];
        int cnt = 0;
        if (p != NULL){
            cnt += 1;
            while(p->next != NULL){
                cnt += 1;
                p = p->next;
            }
            len = len >= cnt ? len : cnt;
        }
    }
    printf("%d\n", len);
}

void koef(struct elem **q){
    double a = 0;
    int n = 0;
    for (int i = 0; i < m; i++){
        struct elem *p;
        p = q[i];
        if (p != NULL){
            n += 1;
            while(p->next != NULL){
                n += 1;
                p = p->next;
            }
        }
    }
    a = (n + 0.0) / m;
    printf("%.2f\n", a);
}

void delete(struct elem **q){
    struct elem *p;
    for (int i = 0; i < m; i++){
        p = q[i];
        while (q[i] != NULL){
            q[i] = q[i]->next;
            free(p);
            p = q[i];
        }
    }
}

int main()
{
    struct elem **b;

    b = input();

    char name[20];
    scanf("%s", &name);
    printf("%s\n", find_name(b, name, strlen(name)));
    Max_len(b);
    koef(b);
    // delete(b);
    // output(b);

    return 0;
}
/*
Vicktor Aleksey Igor Aleksandr Demyan Vicktor Igor Sanya Petr Ivan Papusha Sergey
Vicktor
*/