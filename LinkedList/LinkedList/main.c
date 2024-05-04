//
//  main.c
//  LinkedList
//
//  Created by 박재현 on 2024/05/04.
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
    head -> next = tail;
    tail -> next = tail;
}

void print_list(node *n) {
    printf("\n");
    while(n != tail) {
        printf("%-8d", n -> value);
        n = n -> next;
    }
    printf("\n");
}

node *insert_behind(int value, node *target) {
    node *new;
    
    new = (node *)malloc(sizeof(node));
    new -> value = value;
    new -> next = target -> next;
    target -> next = new;
    
    return new;
}

node *insert_front(int value, int target) {
    node *find;
    node *prev;
    node *new;
    
    prev = head;
    find = prev -> next;
    while(find -> value != target && find != tail) {
        prev = prev -> next;
        find = prev -> next;
    }
    
    if(find != tail) {
        new = (node *)malloc(sizeof(node));
        new -> value = value;
        prev -> next = new;
        new -> next = find;
    }
    return prev -> next;
}

node *find_node(int value) {
    node *t;
    
    t = head -> next;
    while(t -> value != value && t != tail) {
        t = t -> next;
    }
    return t;
}

node *ordered_insert(int value) {
    node *find;
    node *prev;
    node *new;
    
    prev = head;
    find = prev -> next;
    while(find -> value <= value && find != tail) {
        prev = prev -> next;
        find = prev -> next;
    }
    
    new = (node *)malloc(sizeof(node));
    new -> value = value;
    prev -> next = new;
    new -> next = find;
    return new;
}

node *delete_all(void) {
    node *temp;
    node *target;
    
    target = head -> next;
    while(target != tail) {
        temp = target;
        target = target -> next;
        free(temp);
    }
    head -> next = tail;
    return head;
}

int delete_next(node *target) {
    node *t;
    
    // can't delete tail node
    if(target -> next == tail) {
        return 0;
    }
    
    t = target -> next;
    target -> next = target -> next -> next;
    free(t);
    
    return 1;
}

int delete_node(int value) {
    node *find;
    node *prev;
    
    prev = head;
    find = prev -> next;
    
    while(find -> value != value && find != tail) {
        prev = prev -> next;
        find = prev -> next;
    }
    
    if(find != tail) {
        prev -> next = find -> next;
        free(find);
        return 1;
    } else {
        return 0;
    }
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
    print_list(head -> next);
    
    printf("\nFinding 4 is %ssuccessful\n", find_node(4) == tail ? "un" : "");
    
    t = find_node(5);
    printf("\nFindind 5 is %ssuccessful\n", t == tail ? "un" : "");
    
    printf("\nInserting 9 after 5");
    insert_behind(9, t);
    print_list(head -> next);
    
    t = find_node(10);
    printf("\nDeleting next last node");
    delete_next(t);
    print_list(head -> next);
    
    t = find_node(3);
    printf("\nDeleting next 3");
    delete_next(t);
    print_list(head -> next);
    
    printf("\nInsert node 2 before 3");
    insert_front(2, 3);
    print_list(head -> next);
    
    printf("\nDeleting node 2");
    if(!delete_node(2)) {
        printf("\nDelete 2 is fail");
    }
    print_list(head -> next);
    
    printf("\nDeleting node 1");
    delete_node(1);
    print_list(head -> next);
    
    printf("\nDeleting all node");
    delete_all();
    print_list(head -> next);
}
