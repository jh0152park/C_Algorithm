//
//  main.c
//  Array
//
//  Created by 박재현 on 2024/05/04.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    for(int i = 0; i < 10; i++) {
        printf("%d ",array[i]);
    }
    printf("\n\n");
    
    int array2[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", array2[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
