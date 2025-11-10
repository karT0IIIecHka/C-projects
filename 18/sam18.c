#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef struct elem{
    int inf;
    struct elem *prev;
    struct elem *next;
} Elem;

typedef struct list{
    Elem *beg;
    Elem *end;
} List;

void push_to_begin(List *l, int val){
    Elem *p;
    p = (Elem*) malloc(sizeof(Elem));
    p->inf = val;
    p->next = NULL;
    p->prev = NULL;
    if (l->end == NULL){
        l->beg = p;
        l->end = p; 
    }
    else { 
        p->next = l->beg;
        l->beg->prev = p;
        l->beg = p;
    }
}

void push_to_end(List *l, int val){
    Elem *p;
    p = (Elem*) malloc(sizeof(Elem));
    p->inf = val;
    p->prev = NULL;
    p->next = NULL;
    if (l->end == NULL){
        l->beg = p;
        l->end = p;
    }
    else{
        p->prev = l->end;
        l->end->next = p;
        l->end = p;
    }
}

void pop_from_begin(List *l){
    Elem *p;
    p = l->beg;
    l->beg = p->next;
    l->beg->prev = NULL;
    free(p);
}

void pop_from_end(List *l){
    Elem *p;
    p = l->end;
    l->end = p->prev;
    l->end->next = NULL;
    free(p);
}

void input_list(List *l){
    char element;
    int num = 0;

    while ((element = getchar()) != 'n')
    {
        if (isdigit(element)){
            num = num * 10 + element - 48;
            continue;
        }
        else{
            push_to_end(l, num);
            num = 0;
        }
    }
}

void output_list_beg(List *l){
    Elem *p;
    p = l->beg;
    while (p != NULL)
    {
        printf("%4d", p->inf);
        p = p->next;
    }
    printf("\n");
}

void output_list_end(List *l){
    Elem *p;
    p = l->end;
    while (p != NULL)
    {
        printf("%4d", p->inf);
        p = p->prev;
    }
    printf("\n");
}

void count_sum(List *l){
    if (l->end == NULL){
        printf("%d\n", 0);
        return;
    }
    int sum = 0;
    Elem *p;
    p = l->beg;
    while (p != NULL)
    {
        sum += p->inf;
        p = p->next;
    }
    printf("%d\n", sum);
}

void delete_list(List *l){
    if (l->end == NULL){
        printf("No elements in list\n");
        return;
    }
    Elem *p;
    p = l->beg;
    while (p != NULL){
        l->beg = p->next;
        free(p);
        p = l->beg;
    }
    free(p);
}

void delete_elem(List *i, Elem *g){
    g->prev->next = g->next;
    g->next->prev = g->prev;
    free(g);
}

void push_n_elem(List *l, int n, int a, int b, char start){
    if (start == 'b'){
        for (int i = 0; i < n; i++){
            push_to_begin(l,(rand() % (b - a)) + a);
        }
    }
    else{
        for (int i = 0; i < n; i++){
            push_to_end(l, (rand() % (b - a)) + a);
        }
    }
}

Elem* find_elem(List *l, int val){
    Elem *p;
    p = l->beg;
    if (p->inf != val){
        while (p->next->inf != val)
        {
            if (p->next == l->end){
                printf("No elem%3d in list\n", val);
                return 0;
            }
            p = p ->next;
        }
        return p->next;
    }
    else{
        return p;
    }
}

void put_in(List *l, List *t, Elem *g){
    g->next->prev = t->end;
    t->end->next = g->next;

    t->beg->next->prev = g;
    g->next = t->beg->next;
}

int main()
{
    List *list;
    list = (List*) malloc(sizeof(List));
    list->beg = NULL;
    list->end = NULL;

    input_list(list);

    int n;
    scanf("%d", &n);

    List *temp;
    temp = (List*) malloc(sizeof(List));
    temp->beg = NULL;
    temp->end = NULL;
    
    input_list(temp);
    
    Elem *g = find_elem(list, n);
    if (g){
        put_in(list, temp, g);
    }

    delete_elem(list, g);
    output_list_beg(list);

    return 0;
}