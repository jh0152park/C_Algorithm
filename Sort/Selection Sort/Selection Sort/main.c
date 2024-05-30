//
//  main.c
//  Selection Sort
//
//  Created by 박재현 on 2024/05/30.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void select_sort(int a[], int n) {
    int min;
    int min_index;
    
    for(int i = 0; i < n - 1; i++) {
        min = a[i];
        min_index = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < min) {
                min = a[j];
                min_index = j;
            }
        }
        a[min_index] = a[i];
        a[i] = min;
    }
}

int main(int argc, const char * argv[]) {
    int length;
    int *array;
    char *str = "TOLEARNSORTALGORITHM";
    
    length = (int)strlen(str);
    array = (int *)malloc(sizeof(int) * length);
    
    printf("Before select sort\n");
    for(int i = 0; i < length; i++) {
        array[i] = (int)str[i];
        printf("%d ", array[i]);
    }
    printf("\n\n");
    
    select_sort(array, length);
    
    printf("After select sort\n");
    for(int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    return 0;
}
