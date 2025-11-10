#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef struct elem{
    int inf;
    struct elem *link;
} Elem;

typedef struct queue{
    Elem *beg;
    Elem *end;
} Queue;

void push_to_end(Queue *q, int val){
    Elem *p;
    p = (Elem*) malloc(sizeof(Queue));
    p->inf = val;
    p->link = NULL;
    if (q->end == NULL){
        q->beg = p;
        q->end = p; 
    }
    else { 
        q->end->link = p;
        q->end = p;
    }
}

void push_to_begin(Queue *q, int val){
    Elem *p;
    p = (Elem*) malloc(sizeof(Queue));
    p->inf = val;
    p->link = NULL;
    if (q->end == NULL){
        q->beg = p;
        q->end = p; 
    }
    else { 
        p->link = q->beg;
        q->beg = p;
    }
}

void pop_from_begin(Queue *q){
    Elem *p;
    p = q->beg;
    q->beg = p->link;
    free(p);
}

void pop_from_end(Queue *q){
    Elem *p;
    p = q->beg;
    while (p->link != q->end)
    {
        p = p -> link;
    }

    q->end = p;
    free(q->end->link);
    q->end->link = NULL;
}

void output_queue(Queue *q){
    Elem *p;
    p = q->beg;
    while (p != NULL)
    {
        printf("%4d", p->inf);
        p = p->link;
    }
    printf("\n");
}

void input_queue(Queue *q){
    char element;
    int num = 0;

    while ((element = getchar()) != 'n')
    {
        if (isdigit(element)){
            num = num * 10 + element - 48;
            continue;
        }
        else{
            push_to_end(q, num);
            num = 0;
        }
    }
}

Elem* find_elem(Queue *q, int val){
    Elem *p;
    p = q->beg;
    if (p->inf != val){
        while (p->link->inf != val)
        {
            if (p->link == q->end){
                printf("No elem%3d in list\n", val);
                return 0;
            }
            p = p -> link;
        }
        // printf("%d\n", p->link->inf);
        return p->link;
    }
    else{
        // printf("%d\n", p->inf);
        return p;
    }
}

void put_in(Queue *q, Elem *g, int val){
    Elem *p;
    p = q->beg;
    if (p == g){
        push_to_begin(q, val);
    }
    else{
        push_to_begin(q, q->beg->inf);
        while (p->link != g){
            p->inf = p->link->inf;
            p = p->link;
        }
        p->inf = val;
    }
}

int main()
{
    Queue *queue;
    queue = (Queue*) malloc(sizeof(Queue));
    queue->beg = NULL;
    queue->end = NULL;

    input_queue(queue);
    
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);

    Elem *g = find_elem(queue, n);
    if (g){
        put_in(queue, g, k);
    }
 
    output_queue(queue);

    return 0;
}