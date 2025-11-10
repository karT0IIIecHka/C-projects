#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef struct node{
    int key;
    int level;
    struct node *ansector;
    struct node *left;
    struct node *right;
} Node;

typedef Node *pNode;

typedef struct elem{
    pNode inf;
    struct elem *link;
} Elem;

typedef struct queue{
    int size;
    Elem *beg;
    Elem *end;
} Queue;

void output_queue(Queue *q){
    Elem *p;
    p = q->beg;
    while (p != NULL)
    {
        printf("%3d", p->inf->key);
        p = p->link;
    }
    printf("\n");
}

void push(Queue *q, pNode val){
    Elem *p;
    p = (Elem*) malloc(sizeof(Elem));
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
    q->size += 1;
    // printf("push %d\n", val->key);
    // output_queue(q);
}

pNode pop(Queue *q){
    Elem *p;
    // p = (Elem*) malloc(sizeof(Elem));
    p = q->beg;
    q->beg = p->link;
    if (q->size == 1){
        q->end = p->link;
    }
    q->size -= 1;
    // printf("pop %d\n", p->inf->key);
    // output_queue(q);
    return p->inf;
} 

void delete_queue(Queue *q){
    Elem *p;
    p = q->beg;
    while (p != NULL){
        q->beg = p->link;
        free(p);
        p = q->beg;
        q->size -= 1;
    }
}

Queue* createQueue(){
    Queue *queue;
    queue = (Queue*) malloc(sizeof(Queue));
    queue->size = 0;
    queue->beg = NULL;
    queue->end = NULL;
    return queue;
}

void add_node(pNode *p, int val, int level, pNode *q){
    if (*p == NULL){
        *p = (Node *) malloc(sizeof(Node));
        (*p)->level = level;
        (*p)->key = val;
        (*p)->left = NULL;
        (*p)->right = NULL;
        (*p)->ansector = *q;
    }
    else{
        if (val < (*p)->key){
            add_node(&( (*p)->left ), val, level+1, p);
        }
        else{
            add_node(&( (*p)->right ), val, level+1, p);
        }
    }
}

void create_tree(pNode *root){
    char element;
    int num = 0;

    while ((element = getchar()) != 'n')
    {
        if (isdigit(element)){
            num = num * 10 + element - 48;
            continue;
        }
        else{
            add_node(root, num, 0, root);
            num = 0;
        }
    }
}

void pre_order(pNode p) { 
    if (p != NULL) { 
        printf("%3d", p->key);
        pre_order(p->left);
        pre_order(p->right);
    } 
} 

void in_order(pNode p){
    if (p != NULL) {
        in_order(p->left);
        printf("%3d", p->key);
        in_order(p->right);
    } 
}

void post_order(pNode p, int A[], int *i){
    if (p != NULL) {
        post_order(p->left, A, i);
        post_order(p->right, A, i);
        A[*i] = p->key;
        *i += 1;
    } 
}

int sum_one_descendant(pNode p){
    int sum = 0;
    if (p != NULL){
        if (p->left == NULL && p->right != NULL){
            sum += p->key;
        }
        else if (p->left != NULL && p->right == NULL){
            sum += p->key;
        }
        sum += sum_one_descendant(p->right);
        sum += sum_one_descendant(p->left);
    }
    return sum;
}

void delete_tree(pNode *p){
    if (*p != NULL) {
        delete_tree(&((*p)->left));
        delete_tree(&((*p)->right));
        free(*p);
    } 
}

int max_level(pNode p){
    int lv = 0, tp;
    if (p != NULL){
        lv = p->level;
        tp = max_level(p->left);
        lv = lv > tp ? lv : tp;

        tp = max_level(p->right);
        lv = lv > tp ? lv : tp;
    }
    return lv;
}

// void add_rand_list(pNode *p, int n, int a, int b){
//     for (int i = 0; i < n; i++){
//         int val = (rand() % (b - a)) + a;
//         add_node(p, val, 0);
//     }
// }

Queue* breadthFirst(pNode root) {
    Queue *q = createQueue();
    Queue *paint = createQueue();
    push(q, root); //поместим в очередь кореньS
    printf("\n");
    while (q->size != 0) {
        pNode tmp = (pNode) pop(q);
        printf("%d ", tmp->key);
        push(paint, tmp);
        //Если есть левый наследник, то помещаем его в очередь для дальнейшей обработки
        if (tmp->left != NULL) {
            push(q, tmp->left);
        }
        //Если есть правый наследник, то помещаем его в очередь для дальнейшей обработки
        if (tmp->right != NULL) {
            push(q, tmp->right);
        }
    }
    printf("\n");
    return paint;
    // delete_queue(q);
}

void draw_tree(pNode root, int space){
    if (root == NULL) {
        return;
    }
    
    space += 4; // расстояние между уровнями
    
    draw_tree(root->right, space);
    
    // Печатаем узел
    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->key);

    for (int i = 5; i < space - 1; i++) {
        printf(" ");
    }
    if (root->ansector->left != root  && root->ansector != root){
        printf("/");
    }
    
    if (root->left != NULL && root->ansector != NULL){
        printf("  %c", 92);
    }
    

    draw_tree(root->left, space);
}

void swap(int *x, int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void QuickSort(int A[], int n, int first, int last){
    int l = first, r = last; /*левый и правый счетчики*/
    int pivot = A[(l+r)/2]; /*опорное значение*/
    while (l <= r) {
        while (A[l] < pivot){
            l++;
        }
        while (A[r] > pivot){
            r--;
        }
        if (l<=r){
            swap(&A[l],&A[r]); /*перестановка двух элементов*/
            l++;
            r--;
        }
    } /*Рекурсивная сортировка:*/
    if (first<r){
        QuickSort(A, n, first, r); /*- левого участка, */
    }
    if (l<last){
        QuickSort(A, n, l, last); /*- правого участка.*/
    }
}

void put(pNode *root, int *A, int l, int r, int lv){
    // printf("%d %d\n", l, r);s
    int mid = (l+r)/2;
    
    if (l <= r) add_node(root, A[mid], lv, root);
    if (l < r){
        put(root, A, l, mid - 1, lv);
        put(root, A, mid + 1, r, lv);
    }
}

void balance(pNode root){
    Queue *q;
    q = breadthFirst(root);
    int i = 0;
    int *A;
    A = (int*) malloc(q->size*sizeof(int));
    post_order(root, A, &i);

    // printf("OK\n");
    // for (int j = 0; j < q->size; j++){
    //     printf("%3d", A[j]);
    // }
    // printf("\n");

    QuickSort(A, q->size, 0, q->size-1);

    pNode Root;
    Root = NULL;
    put(&Root, A, 0, q->size-1, 0);
    draw_tree(Root, 0);
}

int main()
{
    pNode root;
    root = NULL;
    create_tree(&root);
    
    // delete_tree(&root);
    // add_rand_list(&root, 5, 0, 30);
    // pre_order(root);
    // in_order(root);
    // post_order(root);
    // breadthFirst(root);
    
    draw_tree(root, 0);
    balance(root);
    // draw_tree(root, 0);

    
    // printf("\n%d\n", sum_one_descendant(root));
    // printf("\n%d\n", max_level(root));

    return 0;
}

/*
42 6 18 92 80 94 3 103 52 39 17 4 n
8 15 26 4 98 196 34 2 3 4 7 1 0 n
*/