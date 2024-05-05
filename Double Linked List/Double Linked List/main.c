//
//  main.c
//  Double Linked List
//
//  Created by 박재현 on 2024/05/05.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int key;
    struct _node *prev;
    struct _node *next;
} node;

node *head;
node *tail;

void init_list(void) {
    head = (node *)malloc(sizeof(node));
    tail = (node *)malloc(sizeof(node));
    
    head->prev = head;
    head->next = tail;
    tail->prev = head;
    tail->next = tail;
}

node *insert_front(int key, node *t) {
    node *new;
    
    if(t == head) {
        return NULL;
    }
    
    new = (node *)malloc(sizeof(node));
    
    new->key = key;
    t->prev->next = new;
    new->prev = t->prev;
    t->prev = new;
    new->next = t;
    
    return new;
}

int delete_node_ptr(node *t) {
    if(t == head || t == tail) {
        return 0;
    }
    
    t->prev->next = t->next;
    t->next->prev = t->prev;
    free(t);
    
    return 1;
}

node *find_node(int k) {
    node *s;
    s = head->next;
    
    while(s->key != k && s != tail) {
        s = s->next;
    }
    return s;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
