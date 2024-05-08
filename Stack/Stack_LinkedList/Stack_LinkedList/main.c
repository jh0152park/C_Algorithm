//
//  main.c
//  Stack_LinkedList
//
//  Created by 박재현 on 2024/05/08.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int value;
    struct _node *next;
} node;

node *head;
node *tail;

void init_list(void) {
    head = (node *)malloc(sizeof(node));
    tail = (node *)malloc(sizeof(node));
    head->next = tail;
    tail->next = tail;
}

void push(int value) {
    node *new;
    if( (new = (node *)malloc(sizeof(node))) == NULL ) {
        printf("Occurred OOM !\n");
        return;
    }
    
    new->value = value;
    new->next = head->next;
    head->next = new;
}

int pop(void) {
    if(head->next == tail) {
        printf("Stack underflow !!!\n");
        return -1;
    }
    int value;
    node *temp;
    
    temp = head->next;
    value = temp->value;
    head->next = temp->next;
    free(temp);
    
    return value;
}

void clear_stack(void) {
    node *temp;
    node *delete;
    
    temp = head->next;
    while(temp != tail) {
        delete = temp;
        temp = temp->next;
        free(delete);
    }
    head->next = tail;
}

void print_stack(void) {
    node *t;
    t = head->next;
    
    printf("\nStack as below\n");
    while(t != tail) {
        printf("%-6d", t->value);
        t = t->next;
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    int num;
    init_list();
    
    printf("\nPush 5, 4, 7, 8, 2, 1");
    push(5);
    push(4);
    push(7);
    push(8);
    push(2);
    push(1);
    print_stack();
    
    printf("POP !\n");
    num = pop();
    print_stack();
    printf("POP value is %d\n", num);
    
    printf("\nPush 3, 2, 5, 7, 2");
    push(3);
    push(2);
    push(5);
    push(7);
    push(2);
    print_stack();
    
    printf("Push 3\n");
    push(3);
    print_stack();
    
    printf("Initialize stack!\n");
    clear_stack();
    print_stack();
    
    printf("Currently Stack is Empty !!\nLet's try POP!\n");
    num = pop();
    print_stack();
    printf("POP value is %d\n", num);
    
    
    return 0;
}
