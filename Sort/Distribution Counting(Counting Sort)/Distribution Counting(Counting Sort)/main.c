//
//  main.c
//  Distribution Counting(Counting Sort)
//
//  Created by 박재현 on 2024/06/26.
//

#include <stdio.h>
#include <stdlib.h>

void print_array(int array[], int length) {
    for(int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void dist_count(int array[], int lenght, int range) {
    int *count;
    int *sorted;
    
    count = (int *)malloc(sizeof(int) * range+1);
    sorted = (int *)malloc(sizeof(int) * lenght);
    
    for(int i = 0; i <= range; i++) {
        count[i] = 0;
    }
    
    for(int i = 0; i < lenght; i++) {
        count[array[i]]++;
    }
    
    for(int i = 2; i <= range; i++) {
        count[i] += count[i-1];
    }
    
    for(int i = lenght - 1; i >= 0; i--) {
        sorted[--count[array[i]]] = array[i];
    }
    
    for(int i = 0; i < lenght; i++) {
        array[i] = sorted[i];
    }
    
    free(count);
    free(sorted);
}


int main(int argc, const char * argv[]) {
    int array[20] = {1, 3, 2, 2, 3, 1, 3, 2, 4, 2, 4, 3, 1, 2, 1, 2, 5, 1, 5, 3};
    
    printf("Before Distribution Counting.\n");
    print_array(array, 20);
    
    printf("\nAfter Distribution Counting.\n");
    dist_count(array, 20, 5);
    print_array(array, 20);
    
    return 0;
}
