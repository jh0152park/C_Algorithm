//
//  main.c
//  Array
//
//  Created by 박재현 on 2024/05/04.
//

#include <stdio.h>

#define SIZE 10

void print_array(int array[][SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0 ; j < SIZE; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, const char * argv[]) {
    int array[SIZE][SIZE] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    };
    
    print_array(array);
    
    return 0;
}
