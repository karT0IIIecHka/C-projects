#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef struct node{
    int key;
    int level;
    struct node *parent;
    struct node *left;
    struct node *right;
} Node;

typedef Node *pNode;

void add_node(pNode *p, pNode *q, int val, int level){
    if (*p == NULL){
        *p = (Node *) malloc(sizeof(Node));
        (*p)->level = level;
        (*p)->key = val;
        if (level == 0) (*p)->parent = NULL;
        else (*p)->parent = *q;
        (*p)->left = NULL;
        (*p)->right = NULL;
    }
    else{
        if (val < (*p)->key){
            add_node(&( (*p)->left ), p, val, level+1);
        }
        else{
            add_node(&( (*p)->right ), p, val, level+1);
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
            add_node(root, root, num, 0);
            num = 0;
        }
    }
}

void post_order(pNode p){
    if (p != NULL) {
        post_order(p->left);
        post_order(p->right);
        printf("%3d", p->key);
    } 
}

pNode find_node(pNode p, int val){
    while (p->key != val && p != NULL){
        if (p->key > val){
            if (p->left == NULL) return NULL;
            p = p->left;
        }
        else{
            if (p->right == NULL) return NULL;
            p = p->right;
        }
    }
    return p;
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

pNode findMaxNode(pNode q){
    pNode p = q;
    while (p->right!= NULL){
        p = p->right;
    }
    return p;
}

pNode deleteValue(pNode *q, int val){
    pNode target = find_node(*q, val);
    if (target == NULL){
        return target;
    }
    if (target->left && target->right){
        pNode localMax = findMaxNode(target->left);
        target->key = localMax->key;
        deleteValue(&localMax, localMax->key);
    }
    else if (target->left){
        if (target == target->parent->left){
            target->parent->left = target->left;
        }
        else {
            target->parent->right = target->left;
        }
    }
    else if (target->right){
        if (target == target->parent->right){
            target->parent->right = target->right;
        }
        else{
            target->parent->left = target->right;
        }
    }
    else{
        if (target == target->parent->left){
            target->parent->left = NULL;
        }
        else{
            target->parent->right = NULL;
        }
    }
    return target;
}

void Balance(pNode *q){
    
}

int main()
{
    pNode root;
    root = NULL;
    create_tree(&root);

    int n;
    scanf("%d", &n);

    post_order(root);
    printf("\n");

    pNode q;
    q = deleteValue(&root, n);

    if (q == NULL){
        printf("!\n");
    }

    post_order(root);
    printf("\n");
    printf("%d\n", sum_one_descendant(root));

    return 0;
}