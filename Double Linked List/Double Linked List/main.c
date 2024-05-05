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

int delete_node(int k) {
    node *s;
    s = find_node(k);

    if(s != tail) {
        s->prev->next = s->next;
        s->next->prev = s->prev;
        return 1;
    }
    return 0;
}

// t를 갖고있는 node 앞에 k를 갖는 노드를 삽입
node *insert_node(int k, int t) {
    node *s;
    node *i = NULL;
    
    s = find_node(t);
    if(s != tail) {
        i = (node *)malloc(sizeof(node));
        i->key = k;
        
        s->prev->next = i;
        i->prev = s->prev;
        s->prev = i;
        i->next = s;
    }
    
    return i;
}

node *ordered_insert(int k) {
    node *s;
    node *i;
    
    s = head->next;
    while(s -> key <= k && s != tail) {
        s = s->next;
    }
    
    i = (node *)malloc(sizeof(node));
    i->key = k;
    s->prev->next = i;
    i->prev = s->prev;
    s->prev = i;
    i->next = s;
    
    return i;
}

void print_list(node *p) {
    printf("\n");
    while(p != tail) {
        printf("%-8d", p->key);
        p = p->next;
    }
    printf("\n");
}

void delete_all(void) {
    node *p;
    node *s;
    
    p = head->next;
    while(p != tail) {
        s = p;
        p = p->next;
        free(s);
    }
    head->next = tail;
    tail->prev = head;
}

int main(int argc, const char * argv[]) {
    node *t;
    
    init_list();
    
    ordered_insert(10);
    ordered_insert(5);
    ordered_insert(8);
    ordered_insert(3);
    ordered_insert(1);
    ordered_insert(7);
    ordered_insert(8);
    
    printf("\nInitial Linked list status as below");
    print_list(head->next);
    
    printf("\nFinding 4 is %ssuccessful\n", find_node(4) == tail ? "un" : "");
    
    t = find_node(5);
    printf("\nFinding 5 is %ssuccessful\n", t == tail ? "un" : "");
    
    printf("\nInserting 7 before 5");
    insert_front(7, t);
    print_list(head->next);
    
    t = find_node(3);
    printf("\nDeleting 3");
    delete_node_ptr(t);
    print_list(head->next);
    
    printf("\nInserting node 2 before 10");
    insert_node(2, 10);
    print_list(head->next);
    
    printf("\nDeleting node 2");
    if(!delete_node(2)) {
        printf("\nDeleting 2 is fail");
    }
    print_list(head->next);
    
    printf("\nDeleting node 1");
    delete_node(1);
    print_list(head->next);
    
    printf("\nInserting 15 at first");
    insert_front(15, head->next);
    print_list(head->next);
    
    printf("\nDeleting all node");
    delete_all();
    print_list(head->next);
    
    
    return 0;
}
