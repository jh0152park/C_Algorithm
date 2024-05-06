//
//  main.c
//  Stack_Array
//
//  Created by 박재현 on 2024/05/07.
//

#include <stdio.h>

#define MAX 10

int STACK[MAX];
int TOP;

void init_stack(void) {
    TOP = -1;
}

int push(int value) {
    if(TOP >= MAX - 1) {
        printf("\nstack overflow\n");
        return -1;
    }
    STACK[++TOP] = value;
    return value;
}

int pop(void) {
    if(TOP < 0) {
        printf("\nstack underflow");
        return -1;
    }
    return STACK[TOP--];
}

void print_stack(void) {
    printf("\nValues of stack from Top to Bottom as below\n");
    for(int i = TOP; i >= 0; i--) {
        printf("%-6d", STACK[i]);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    int n;
    init_stack();
    
    printf("\nPush 5, 4, 7, 8, 2, 1\n");
    push(5);
    push(4);
    push(7);
    push(8);
    push(2);
    push(1);
    print_stack();
    
    printf("\nPop!");
    n = pop();
    print_stack();
    printf("Pop value is %d\n", n);
    
    printf("\nPush 3, 2, 5, 7, 2");
    push(3);
    push(2);
    push(5);
    push(7);
    push(2);
    print_stack();
    
    printf("\nCurrently stack is full, then try to push 3!!");
    push(3);
    print_stack();
    
    printf("Initialize stack");
    init_stack();
    print_stack();
    
    printf("\nCurrently stack is empty, then try to pop something!!");
    n = pop();
    print_stack();
    printf("\nPop value is %d\n", n);
    
    return 0;
}
