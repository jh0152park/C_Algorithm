//
//  main.c
//  Parse Tree
//
//  Created by 박재현 on 2024/05/13.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct _node {
    int key;
    struct _node *left;
    struct _node *right;
} node;

node *head, *tail;
node *stack[MAX];

int top;

void init_stack(void) {
    top = -1;
}

node *push(node *t) {
    if(top >= MAX - 1) {
        printf("\nStack Overflow...\n");
        return NULL;
    }
    
    stack[++top] = t;
    return t;
}

node *pop(void) {
    if(top < 0) {
        printf("\nStack Underflow...\n");
        return NULL;
    }
    
    return stack[top--];
}

int is_stack_empty(void) {
    return (top == -1);
}

node *queue[MAX];
int front, rear;

void init_queue(void) {
    front = 0;
    rear = 0;
}

node *put(node *k) {
    if((rear + 1) % MAX == front) {
        printf("\nQueue Overflow...\n");
        return NULL;
    }
    
    queue[rear++] = k;
    rear %= MAX;
    return k;
}

node *get(void) {
    if(front == rear) {
        printf("\nQueue Underflow...\n");
        return NULL;
    }
    
    node *t = queue[front++];
    front %= MAX;
    return t;
}

int is_queue_empty(void) {
    return (front == rear);
}

void init_tree(void) {
    head = (node *)malloc(sizeof(node));
    tail = (node *)malloc(sizeof(node));
    head->left = tail;
    head->right = tail;
    tail->left = tail;
    tail->right = tail;
}

int is_operator(int k) {
    return (k == '+' || k == '-' || k == '*' || k == '/');
}

node *make_parse_tree(char *p) { // 후위표기법 수식에서 수식 나무 구성
    node *t;
    while(*p) {
        while(*p == ' ') {
            p++;
        }
        
        t = (node *)malloc(sizeof(node));
        t->key = *p;
        t->left = tail;
        t->right = tail;
        
        if(is_operator(*p)) {
            t->right = pop();
            t->left = pop();
        }
        
        push(t);
        p++;
    }
    return pop();
}

int is_legal(char *s) {
    int f = 0;
    while(*s) {
        while(*s == ' ')
            s++;
        
        if(is_operator(*s))
            f--;
        else
            f++;

        if(f < 1) break;
        s++;
    }
    
    return (f == 1);
}

void visit(node *t) {
    printf("%c ", t->key);
}

void preorder_travers(node *t) { // 전위순회, 뿌리를 먼저 방문
    if(t != tail) {
        visit(t);
        preorder_travers(t->left);
        preorder_travers(t->right);
    }
}

void inorder_travers(node *t) { // 중위순회, 뿌리를 중간에 방문
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
    char post[256] = "A B + C D - * E / F G * +";
    
    init_stack();
    init_queue();
    init_tree();
    
    if(!is_legal(post)) {
        printf("\n옳바른 수식이 아닙니다.\n");
        exit(0);
    }
    
    printf("Postfix expression -> %s", post);
    
    head->right = make_parse_tree(post);
    
    printf("\nPreorder travers -> ");
    preorder_travers(head->right);
    
    printf("\nInorder travers -> ");
    inorder_travers(head->right);
    
    printf("\nPostorder travers -> ");
    postorder_travers(head->right);
    
    printf("\nLevelorder travers -> ");
    levelorder_travers(head->right);
    
    printf("\n");
    
    return 0;
}
