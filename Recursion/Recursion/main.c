//
//  main.c
//  Recursion
//
//  Created by 박재현 on 2024/05/19.
//

#include <stdio.h>

int fact(int num) {
    if(num == 1)
        return 1;
    return num * fact(num - 1);
}

int fibo(int num) {
    if(num == 1 || num == 2)
        return 1;
    else
        return fibo(num - 1) + fibo(num - 2);
}

void move_disk(int from, int to) {
    printf("Move disk from %d pillar to %d pillar\n", from, to);
}

void hanoi(int disk, int from, int via, int to) {
    if(disk == 1) {
        move_disk(from, to);
    } else {
        hanoi(disk - 1, from, to, via);
        move_disk(from, to);
        hanoi(disk - 1, via, from, to);
    }
}

int main(int argc, const char * argv[]) {
    hanoi(3, 1, 2, 3);
    return 0;
}

