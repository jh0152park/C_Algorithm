//
//  main.c
//  Queue_LinkedLIst
//
//  Created by 박재현 on 2024/05/11.
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

void init_queue(void) {
    head = (node *)malloc(sizeof(node));
    tail = (node *)malloc(sizeof(node));
    
    head->prev = head;
    head->next = tail;
    tail->prev = head;
    tail->next = tail;
}

int put(int k) {
    node *new;
    
    if((new = (node *)malloc(sizeof(node))) == NULL) {
        printf("\nCould not put a value due to OOM\n");
        return -1;
    }
    
    // put into front of tail
    new->key = k;
    tail->prev->next = new;
    new->prev = tail->prev;
    tail->prev = new;
    new->next = tail;
    
    return k;
}

int get(void) {
    node *temp;
    int key;
    
    temp = head->next;
    if(temp == tail) {
        printf("\nQueue underflow.\n");
        return -1;
    }
    
    key = temp->key;
    head->next = temp->next;
    temp->next->prev = head;
    free(temp);
    
    return key;
}

void clear_queue(void) {
    node *t;
    node *s;
    
    t = head->next;
    while(t != tail) {
        s = t;
        t = t->next;
        free(s);
    }
    
    head->next = tail;
    tail->prev = head;
}

void print_queue(void) {
    node *t;
    t = head->next;
    
    while(t != tail) {
        printf("%-6d", t->key);
        t = t->next;
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    int i;
    
    init_queue();
    
    printf("Put 5, 4, 7, 8, 2, 1\n");
    put(5);
    put(4);
    put(7);
    put(8);
    put(2);
    put(1);
    print_queue();
    
    printf("\nGet\n");
    i = get();
    print_queue();
    printf("Getting value is %d\n", i);
    
    printf("\nPut 3, 2, 5, 7\n");
    put(3);
    put(2);
    put(5);
    put(7);
    print_queue();
    
    printf("\nPut 3\n");
    put(3);
    print_queue();
    
    printf("\nInitialize Queue\n");
    clear_queue();
    print_queue();
    
    printf("\nCurrently queue is empty.\n");
    i = get();
    print_queue();
    printf("\nGetting value is %d\n", i);
    
    return 0;
}
