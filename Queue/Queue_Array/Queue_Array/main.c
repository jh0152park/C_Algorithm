//
//  main.c
//  Queue_Array
//
//  Created by 박재현 on 2024/05/10.
//

#include <stdio.h>

#define MAX 10

int queue[MAX];
int front, rear;

void init_queue(void) {
    rear = 0;
    front = 0;
}

void clear_queue(void) {
    front = rear;
}

int put(int k) {
    if((rear + 1) % MAX == front) {
        printf("\nQueue Overflow\n");
        return -1;
    }
    
    queue[rear++] = k;
    rear %= MAX;
    
    return k;
}

int get(void) {
    int value;
    
    if(rear == front) {
        printf("\nQueue Underflow\n");
        return -1;
    }
    
    value = queue[front++];
    front %= MAX;
    
    return value;
}

void print_queue(void) {
    for(int i = front; i != rear; i = (i + 1) % MAX) {
        printf("%-6d", queue[i]);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    int i;
    
    init_queue();
    
    printf("\nPut 5, 4, 7, 8, 2, 1\n");
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
    printf("\nGetting value is %d\n", i);
    
    printf("\nPut 3, 2, 5, 7\n");
    put(3);
    put(2);
    put(5);
    put(7);
    print_queue();
    
    printf("\nCurrently queue is full, try to put 3");
    put(3);
    print_queue();
    
    printf("\nInitialize queue\n");
    clear_queue();
    print_queue();
    
    printf("\nCurrently queue is empty, try to get");
    i = get();
    print_queue();
    printf("\nGetting value is %d\n", i);
    
    return 0;
}
