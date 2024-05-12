//
//  main.c
//  Binary_Tree
//
//  Created by 박재현 on 2024/05/12.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int key;
    struct _node *left;
    struct _node *right;
} node;

node *head, *tail;

void init_tree(void) {
    head = (node *)malloc(sizeof(node));
    tail = (node *)malloc(sizeof(node));
    head->left = tail;
    head->right = tail;
    tail->left = tail;
    tail->right = tail;
}

void visit(node *t) {
    printf("visit value is %d\n", t->key);
}

int is_queue_empty(void) {
    return head->left == tail && head->right == tail ? 1 : 0;
}

void put(node *t) {
    // do nothing
}

node *get(void) {
    return 0;
}

void preorder_traverse(node *t) {
    if(t != tail) {
        visit(t);
        preorder_traverse(t->left);
        preorder_traverse(t->right);
    }
}

void inorder_travers(node *t) {
    if(t != tail) {
        inorder_travers(t->left);
        visit(t);
        inorder_travers(t->right);
    }
}

void postorder_travers(node *t) {
    if(t != tail) {
        postorder_travers(t->left);
        postorder_travers(t->right);
        visit(t);
    }
}

void levelorder_travers(node *t) {
    put(t);
    while(!is_queue_empty()) {
        t = get();
        visit(t);
        
        if(t->left != tail)
            put(t->left);
        if(t->right != tail)
            put(t->right);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
