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

void push(Queue *q, int val){
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

void pop(Queue *q){
    Elem *p;
    p = q->beg;
    q->beg = p->link;
    free(p);
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

int how_many_elem(Queue *q){
    int cnt = 0;
    Elem *p;
    p = q->beg;
    while (p != NULL)
    {
        p = p->link;
        cnt ++;
    }
    return cnt;
}

void input(Queue *q){
    char element;
    int num = 0;

    while ((element = getchar()) != 'n')
    {
        if (isdigit(element)){
            num = num * 10 + element - 48;
            continue;
        }
        else{
            push(q, num);
            num = 0;
        }
    }
}

int main()
{
    Queue *queue;
    queue = (Queue*) malloc(sizeof(Queue));
    queue->beg = NULL;
    queue->end = NULL;

    input(queue);

    pop(queue);
    pop(queue);

    output_queue(queue);
    printf("%d\n", how_many_elem(queue));

    return 0;
}